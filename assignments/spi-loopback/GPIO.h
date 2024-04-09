/*
 * GPIO.h
 *
 *  Created on: Jun 7, 2017
 *      Author: Jason Forsyth
 */

#ifndef SRC_GPIO_H_
#define SRC_GPIO_H_

#include <em_gpio.h>

#include "Helper.h"

//General GPIO modes and masks
#define PIN_MODE_INPUT 0x1u
#define PIN_MODE_PUSH_PULL 0x4u

#define PIN_MODE_MASK_BITS 0xfu
#define EINT_MASK 0x7u

/**
 * Set pin output value. Only works if correct Port address is provided
 */
void setPinOutputValue(GPIO_Port_TypeDef port, uint32_t pinNum, uint32_t value)
{
  GPIO->P[port].DOUT=(GPIO->P[port].DOUT&~(0x1<<pinNum))|(value&0x1)<<(pinNum);

  return;
}

/**
 * Set pin mode. Only works if correct Port Mode register address is provided
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

inline void toggleLED(GPIO_Port_TypeDef port, uint32_t pinNum)
{
  writeBit(&GPIO->P[port].DOUTTGL, pinNum, 0x1);
}

/**
 * Sets up pin as external interrupt. Enables pin as input, sets edge detection and
 * enables interrupt in NVIC controller
 */
void setupExternalInterrupt(GPIO_Port_TypeDef port, uint32_t pinNum, bool risingEdge, bool fallingEdge)
{
  if(pinNum>15)
  {
    //invalid pin number
    return;
  }

  //set pin as input
  setPinMode(port,pinNum,PIN_MODE_INPUT);

  //grab port number and mask shift
  uint32_t portNum = port&0x7u;
  uint32_t shiftDistance = (pinNum%8)<<2;

  //Enable ENTn based upon pin number
  if(pinNum>7)
  {

    GPIO->EXTIPSELH=(GPIO->EXTIPSELH&~(EINT_MASK<<(shiftDistance)))|(portNum<<(shiftDistance));
  }
  else
  {
    GPIO->EXTIPSELL=(GPIO->EXTIPSELH&~(EINT_MASK<<shiftDistance))|(0x1<<shiftDistance);
  }

  //configure ENTn for FALL
  if(fallingEdge)
  {
    GPIO->EXTIFALL|=(0x1<<pinNum);
  }

  //configure ENTn for RISE
  if(risingEdge)
  {
    GPIO->EXTIRISE|=(0x1<<pinNum);
  }

  //clear any associated IF flags
  GPIO->IFC|=(0x1<<pinNum);

  //enable ENTn in IEN register
  //set bit n in IEN to enable
  GPIO->IEN|=(0x1<<pinNum);

  //enable GPIO_ODD in NVIC
  if(pinNum%2==0)
  {
    NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
    NVIC_EnableIRQ(GPIO_EVEN_IRQn);
  }
  else
  {
    NVIC_ClearPendingIRQ(GPIO_ODD_IRQn);
    NVIC_EnableIRQ(GPIO_ODD_IRQn);
  }

}



#endif /* SRC_GPIO_H_ */
