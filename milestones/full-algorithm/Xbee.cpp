/*
 * LowEnergySerial.cpp
 *
 *  Created on: Apr 28, 2024
 *      Author: jforsyth
 */

#include "Xbee.h"

Xbee::Xbee ()
{
  // TODO Auto-generated constructor stub

  /**
   * Do nothing.. Can't run here because if variable is declared static then
   * clocks haven't been enabled yet!
   */

}

void Xbee::initialize()
{
  setupClocks();
  setupGPIO();
  setupUART();

  int dummy=0;
}

Xbee::~Xbee ()
{
  // TODO Auto-generated destructor stub
}

void Xbee::setupClocks()
{
  //enable the clock for the High-Frequency Peripherals
  CMU_ClockEnable(cmuClock_HFPER, true);

  //enable GPIO clock
  CMU_ClockEnable(cmuClock_GPIO, true);

  //enable CORELE clock
  CMU_ClockEnable(cmuClock_CORELE, true);

  //enable LEURAT0 clock
  CMU_ClockEnable(cmuClock_LEUART0, true);
}

void Xbee::setupGPIO()
{

  /**
   * PD5 - RX (data incoming)
   * PD5 - TX (data outgoing)
   */

  /* Enable GPIO for LEUART0. TX is on PD4 */
  GPIO_PinModeSet(gpioPortD,                /* GPIO port */
                  4,                        /* GPIO port number */
                  gpioModePushPull,         /* Pin mode is set to push pull */
                  1);                       /* High idle state */

  /* Enable GPIO for LEUART0. RX is on PD5 */
  GPIO_PinModeSet(gpioPortD,                /* GPIO port */
                  5,                        /* GPIO port number */
                  gpioModePushPull,         /* Pin mode is set to push pull */
                  1);                       /* High idle state */
}

void Xbee::setupUART()
{

  ///////////////////BEGIN USART0 CONFIGURATION///////////////////

  /**
   * Begin configuration of LEUART0
   * Set for 9600 8N1
   */

  /**
   * CONFIGURE CLOCK and BAUD RATE
   */

  //Double check that LEUART frequency is 32.768 kHz with CMU_ClockFreqGet
  const float CLOCK_RATE = CMU_ClockFreqGet(cmuClock_LEUART0);

  /**
   * LEUART_CLK_DIV = 256 * (fLEUARTn/BR - 1)
   * CLK_DIV should be 616 for 9600 Baud
   */
  const float BAUD_RATE=9600;
  const int LEUART_CLK_DIV = 256.0 * (CLOCK_RATE / BAUD_RATE -1);
  leuart->CLKDIV=LEUART_CLK_DIV;

  /**
   * CONFIGURE PAYLOAD
   */
  //Configure CTRL Parity[3:2] to 0x0 to set NO parity
  //nothing to do

  //Configure CTRL DATABITS[1] to 0x0 for 8-bits
  //nothing to do

  //Configure CTRL STOPBITS[4] to 0x0 for 1 STOP bit
  //nothing to do


  /**
   * ROUTE and ENABLE GPIO
   * PD5 - RX (data incoming) - Location 0
   * PD5 - TX (data outgoing) - Location 0
   */

  //Use ROUTE Location[10:8] to 0x0 to Location #0
  //nothing to do

  //Enable TX Pin[1] and RX Pin [0] in ROUTE register
  leuart->ROUTE |= (0x3);

  /**
   * ENABLE TX AND TX in Peripheral
   */

  //Enable TXEN and TXEN in CMD
  //Note: will not see this change in peripherals window because is write only
  leuart->CMD |= (0x5);
}

void Xbee::transmitByte(uint8_t data_to_send)
{

  // wait for transmit buffer to empty
  // read TXBL bit[4] in STATUS. Is 0x1 when buffer is empty.
  while(readBit(&(leuart->STATUS),4)==0x0){}

  // Once transmit butter is empty, write to TXBuffer
  leuart->TXDATA = data_to_send;
}
uint8_t Xbee::receiveByte()
{
  //wait for data to be received
  //poll on the RXDATAV bit[5] in STATUS. Ix 0x1 when data is available
  while(readBit(&(leuart->STATUS),5)==0x0){}

  //Read data out of RXDATA.
  uint8_t rxNum = leuart->RXDATA;

  //Return received data
  return rxNum;
}

void Xbee::sendString(std::string s)
{

  //terminate string with \r for new line
  s+='\r';

  //iterate through string and send each character as uint8_t
  for(int i=0;i<s.length();i++)
    {
      unsigned char c = s[i];
      transmitByte((uint8_t)c);
    }

}


/**
 * Helper function take from em_bus.h
 */
inline unsigned int Xbee::readBit(volatile const uint32_t *addr, uint32_t bit)
{
  return ((*addr)>>bit) & 0x1;
}

/**
 * Helper function take from em_bus.h
 */
void Xbee::writeBit(volatile uint32_t *addr, uint32_t bitPos, uint32_t val)
{
  uint32_t tmp = *addr;
  *addr = (tmp & ~(1 << bitPos)) | ((val & 0x1) << bitPos);
  return;
}



