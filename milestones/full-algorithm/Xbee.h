/*
 * LowEnergySerial.h
 *
 *  Created on: Apr 28, 2024
 *      Author: jforsyth
 */

#ifndef XBEE_H_
#define XBEE_H_

#include "em_chip.h"
#include "em_device.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_leuart.h"
#include "em_dma.h"
#include "em_gpio.h"

#include <string>

class Xbee
{
public:
  Xbee ();
  virtual ~Xbee ();

  void initialize();

  /**
   * Send a string out of the serial port. Terminate with a new line character
   * @param s String to be sent
   */
  void sendString(std::string s);


private:

  /**
   * Helper function to setup the associated clocks
   */
  void setupClocks();

  /**
   * Helper function to setup the associated GPIO
   */
  void setupGPIO();

  /**
   * Helper function to setup the LEUSART0
   * for UART operation
   */
  void setupUART();

  /**
   * Transmit a single byte
   * @param 8-bits to be sent
   */
  void transmitByte(uint8_t);

  /**
   * Read one byte from receive buffer. Blocking.
   * @return 8-bits received.
   */
  uint8_t receiveByte();

  // handle to manually defined LEUART0
  LEUART_TypeDef* leuart=LEUART0;

  //Helper function to read one bit from a register
  inline unsigned int readBit(volatile const uint32_t *addr, uint32_t bit);

  //Helper function to write on bit to a register
  inline void writeBit(volatile uint32_t *addr, uint32_t bitPos, uint32_t val);

};

#endif /* XBEE_H_ */
