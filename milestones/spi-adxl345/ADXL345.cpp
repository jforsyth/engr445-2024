/* 
 * ADXL345.cpp
 *
 * Created: 10/7/2019
 * Author: Jason Forsyth
 *
 *  Modified: April 15, 2024 for
 *     ADXL345 in ENGR 445
 */


#include "ADXL345.h"

// default constructor
ADXL345::ADXL345()
{
  //DO NOTHING HERE
}

// default destructor
ADXL345::~ADXL345()
{
  //DO NOTHING HERE
}

void ADXL345::initialize()
{
  //configure the required clocks
  setupClocks();

  //configure the required GPIO
  setupGPIO();

  //configure the USART for SPI operation
  setupSPI();

  //configure the ADXL345 to capture sensor data
  setupADXL345();

  return;
}

/**
 * Setup all the internal clocks of the Giant Gecko
 */
void ADXL345::setupClocks()
{
  //enable the clock for the High-Frequency Peripherals
  CMU_ClockEnable(cmuClock_HFPER, true);

  //enable GPIO clock
  CMU_ClockEnable(cmuClock_GPIO, true);

  //enable the USART1 clock
  CMU_ClockEnable(cmuClock_USART1, true);

}

/**
 * Setup all the GPIO pins for the Giant Gecko
 */
void ADXL345::setupGPIO()
{
  /**
   * PD0 - MOSI - SDA
   * PD1 - MISO - SDO
   * PD2 - CLK - SCLK
   * PD3 - CS
   */
  GPIO_PinModeSet(gpioPortD, 0, gpioModePushPull, 1);
  GPIO_PinModeSet(gpioPortD, 1, gpioModeInput, 1);
  GPIO_PinModeSet(gpioPortD, 2, gpioModePushPull, 1);
  GPIO_PinModeSet(gpioPortD, 3, gpioModePushPull, 1);
}

/**
 * Perform all operations to configure the USART for SPI operation
 */
void ADXL345::setupSPI()
{

  /**
   * Setup USART for Synchronous operations
   */

  /**
   * Configure the size of the data packet to be sent.
   * It should be 8-bits with no stop, or parity bits.
   * Enable synchronous operation and Most Significant Bit First operation.
   */

  //clear parity bits[9:8] to 0. Default is 0x0. No action needed.
  //clear stop bits[13:12] to 0. Default is 0x0. No action needed.
  //set DATABITS[3:0] to 0x5 for 8-bit mode. Default is 0x5. No action needed.

  //enable synchronous operations
  //set SYNC[0] in CTRL
  usart->CTRL |= 0x1;

  //set format to MSB first
  //set MSBF[10] in CTRL
  usart->CTRL |= 0x1 << 10;

  /**
   * Calculate desired clock speed (USARTn_CLKDIV) based upon formula below.
   * ADXL345 max speed is 5 MHz. Recommend selecting 1 MHz.
   *
   * USARTn_CLKDIV = 256 * (f_hfperclk/(2*desired_br)-1)
   */
  //query the USART clock to confirm value
  int usart1Clock = CMU_ClockFreqGet(cmuClock_USART1);
  unsigned int desired_BR = 1000000;
  unsigned int CLKDIV = 256 * (usart1Clock / (2*desired_BR)-1);

  // set CLKDIV register based upon calculation results
  usart->CLKDIV = CLKDIV;

  //ADXL345 expects SPI MODE 3.
  //Configure CPOL as Idle High. Set CPOL[8] to HIGH;
  //Configure CPHA as Trailing Edge. Set CPHA[9] to HIGH;
  usart->CTRL |= (0x1 << 8);
  usart->CTRL |= (0x1 << 9);

  // Enable transmission buffer level. Unsure why we have this but it works :)
  //set TXBIL to 1 [12] in control
  usart->CTRL |= (0x1 << 12);

  /**
   * Setup all pins for Route #1
   * Dr. Forsyth has completed this.
   */
  usart->ROUTE = (0x1) << 8;

  /**
   * Enable all pins in ROUTE[3-0]
   * Dr. Forsyth has completed this.
   */
  //re-route clock pin, set CLKPEN[3]
  usart->ROUTE |= (0x1) << 3;

  //re-route TX pin, set TXPEN[1]
  usart->ROUTE |= (0x1) << 1;

  //re-route RX pin, set RXPEN[0]
  usart->ROUTE |= 0x1;

  /**
   * Enable Master, TX, and RX
   */
  //set to master mode
  //set MASTEREN[4] in CMD to HIGH
  usart->CMD |= 0x1 << 4;

  //enable transmissions and reception on the SPI interface
  //set transmit[2] and receive[0] in CMD to HIGH
  usart->CMD |= 0x1 << 2;
  usart->CMD |= 0x1;
}


/**
 * Conduct a single 8-bit transfer on the SPI interface
 * @param data Bits to be sent on SPI interface
 * @return Bits returned from transaction
 */
uint8_t ADXL345::SPI_Transfer(uint8_t data)
{
  //wait for transmit buffer to be empty (TXBL flag)
  //wait for space in the TX buffer
  while(!(usart->STATUS & USART_STATUS_TXBL)){};

  //put data in the TX buffer (TXDATA)
  usart->TXDATA=(uint32_t)data;

  //wait for transactions to complete (TXC flag)
  while(!(usart->STATUS & USART_STATUS_TXC)){};

  //read “received” data back from RX buffer
  return (uint8_t)usart->RXDATA;

}

/**
 * Perform all initialization of the ADXL itself. At a minimum
 * the MEASURE bit should be set to cause acceleration measurements
 */
void ADXL345::setupADXL345()
{
  //***Step #1 (Optional) ***
  //write to the DATA_FORMAT register to adjust the sampling range

  //***Step #2 (Optional) ***
  //write to the DATA_FORMAT register to adjust the sampling range

  //***Step #3***
  //write to the MEASURE bit in the POWER_CLT register
  //to begin sampling. Ensure the write does not modify other bits by
  //reading the current value, modifying the data locally, and then write
  //back the new register value.

  /**
   * Your code here
   */
}

/**
 * Write to an internal register of the ADXL345
 * @param address Internal register to be written to
 * @param data Bits that will be written to the register
 */
void ADXL345::writeRegister(uint8_t address, uint8_t data)
{

  /**
   * Implement WriteRegister to write "data" to "address"
   * on the ADXL345
   */
  //return nothing
  return;

}

/**
 * Read from an internal register of the ADXL 345.
 * @param address Internal ADXL345 register address to read
 * @return Result of read operation
 */
uint8_t ADXL345::readRegister(uint8_t address)
{

  /**
   * Implement ReadRegister to read data from "address"
   * on the ADXL345
   */

  // this is a dummy return, replace with your own
  return -1;

}

/**
 * Conducts a self-test by reading the DEVICE_ID register on the ADXL345.
 * If the correct value is found, self-test is correct
 * @return True/False whether self-test completed correctly.
 */
bool ADXL345::selfTest()
{

  //implement code to check if you can
  //read the DEVICE_ID register. Return TRUE if
  //the correct result is found, otherwise FALSE.

  uint8_t deviceID = readRegister(DEVICE_ID_REG_ADDRESS);

  if(deviceID == 0xE5)
    {
      return true;
    }
  else
    {
      return false;
    }
}


/*
 * Get X-axis acceleration from ADXL345 and 16-bit signed value
 * @return x-axis acceleration
 */
int16_t ADXL345::getXAcceleration()
{
  /**
   * Read from the X_DATA_0 and X_DATA_1 registers.
   * Re-assemble the data to form a singular int16_t value
   * that is the acceleration measurement
   */

  return -1;
}

/*
 * Get Y-axis acceleration from ADXL345 and 16-bit signed value
 * @return Y-axis acceleration
 */
int16_t ADXL345::getYAcceleration()
{

  /**
     * Read from the Y_DATA_0 and Y_DATA_1 registers.
     * Re-assemble the data to form a singular int16_t value
     * that is the acceleration measurement
     */

  return -1;
}

/*
 * Get Z-axis acceleration from ADXL345 and 16-bit signed value
 * @return Z-axis acceleration
 */
int16_t ADXL345::getZAcceleration()
{
  /**
     * Read from the Z_DATA_0 and Z_DATA_1 registers.
     * Re-assemble the data to form a singular int16_t value
     * that is the acceleration measurement
     */

  return -1;
}
