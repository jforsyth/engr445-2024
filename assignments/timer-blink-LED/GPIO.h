/*
 * GPIO.h
 *
 *  Created on: Jun 7, 2017
 *      Author: Jason Forsyth
 */

#ifndef SRC_GPIO_H_
#define SRC_GPIO_H_

#include <em_gpio.h>

//General GPIO modes and masks
#define PIN_MODE_INPUT 0x1u
#define PIN_MODE_PUSH_PULL 0x4u

#define PIN_MODE_MASK_BITS 0xfu
#define EINT_MASK 0x7u

/**
 * Read a single bit from a register
 * @param addr Pointer to register where bit will be read
 * @param bit The position of the bit to read
 * @return The value of that bit (0 or 1)
 */

unsigned int readBit(volatile const uint32_t *addr, unsigned int bit)
{
  return ((*addr)>>bit) & 0x1;
}


/**
 * Set a single bit in a register
 * @param addr Pointer to register where bit will be set
 * @param bitPos The position of the bit to the set
 * @param val The value (0 or 1) for the bit
 */
void writeBit(volatile uint32_t *addr, unsigned int bitPos, unsigned int val)
{
  uint32_t tmp = *addr;
  *addr = (tmp & ~(1 << bitPos)) | ((val & 0x1) << bitPos);
  return;
}

/**
 * Set pin output value. Only works if correct Port address is provided
 */
/**
 * Set the Output value for a GPIO pin
 * @param port The EMLib definition for each port (gpioPortA, gpioPortB..etc)
 * @param pinNum The pin number that is to be adjusted
 * @param value The output value to set (0x0 or 0x1)
 */
void setPinOutputValue(GPIO_Port_TypeDef port, uint32_t pinNum, uint32_t value)
{
  GPIO->P[port].DOUT=(GPIO->P[port].DOUT&~(0x1<<pinNum))|(value&0x1)<<(pinNum);

  return;
}

/**
 * Set the mode for a GPIO pin
 * @param port The EMLib definition for each port (gpioPortA, gpioPortB..etc)
 * @param pinNum The pin number that is to be adjusted
 * @param mode The configuration value to be used to set the mode
 */
void setPinMode(GPIO_Port_TypeDef port, uint32_t pinNum, uint32_t mode)
{
  if(pinNum>7)
  {
    pinNum%=8;
    GPIO->P[port].MODEH=(GPIO->P[port].MODEH&~(PIN_MODE_MASK_BITS<<(pinNum<<2)))|(mode<<(pinNum<<2));
  }
  else
  {
    GPIO->P[port].MODEL=(GPIO->P[port].MODEL&~(PIN_MODE_MASK_BITS<<(pinNum<<2)))|(mode<<(pinNum<<2));
  }
}

/**
 * Toggle the state (on/off) of an GPIO pin
 * @param port The EMLib definition for each port (gpioPortA, gpioPortB..etc)
 * @param pinNum The pin number that is to be adjusted
 */
void toggleLED(GPIO_Port_TypeDef port, uint32_t pinNum)
{
  writeBit(&GPIO->P[port].DOUTTGL, pinNum, 0x1);
}


#endif /* SRC_GPIO_H_ */
