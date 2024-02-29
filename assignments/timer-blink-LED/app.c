/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

//include standard C/C++ libraries
#include <stdint.h>
#include <stdbool.h>

//include EMLib required libraries
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_timer.h"

//include Dr. Forsyth's helper function
#include "GPIO.h"

/**
 * Option: This is the TIMER0 interrupt handler. Use if you desire
 * an interrupt driven solution.
 */
void TIMER0_IRQHandler(void)
{
  // Your code here... If you so choose...

}


/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
  // we will use Dr. Forsyth's helper functions to set the state of the GPIO pins
  setPinMode(gpioPortE, 2, PIN_MODE_PUSH_PULL);
  setPinMode(gpioPortE, 3, PIN_MODE_PUSH_PULL);

  // turn on both pins/LEDs just so we know that they work
  setPinOutputValue(gpioPortE,2,0x1);
  setPinOutputValue(gpioPortE,3,0x1);

  //enable the clock for the High-Frequency Peripherals
  CMU_ClockEnable(cmuClock_HFPER, true);

  //enable the specific clock for the TIMER0
  CMU_ClockEnable(cmuClock_TIMER0, true);

}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
  // begin your code here...

  /**
   * Method 1: The following template will set the timer to run for a specified
   * duration. We will write a loop to continually monitor the timer "count".
   * Once the timer "expires" we can toggle the LED.
   */

  //Step 1.1: Configure TIMER0 to be UP COUNT mode. Set bits [1:0] to the
  // appropriate value in the TIMER0_CTRL register. We will use the built-in struct
  // to perform the memory mapped I/O

  // read the value of CTRL into a variable
  unsigned int mode = TIMER0->CTRL;

  // modify "value" to adjust bits [1:0] to the correct mode. Dummy code is
  // written below that you should modify
  mode = mode;

  // write this new configuration back to TIMER0->CTRL
  TIMER0->CTRL = mode;

  //Step 1.2: Configure TIMER0 to use the HFPER clock. Set bits [17:16] to the
  // appropriate value in TIMER0_CTRL register. We will use the built-in struct
  // to perform the memory mapped I/O

  // read the value of CTRL into a variable
  unsigned int clock = TIMER0->CTRL;

  // modify "value" to adjust bits [1:0] to the correct mode. Dummy code is
  // written below that you should modify
  clock = clock;

  // write this new configuration back to TIMER0->CTRL
  TIMER0->CTRL = clock;

  //Step 1.3: Configure TIMER0 Pre-Scaler bits. For this example we will assume a
  // prescale of 1024. Modify bits [27:24] to the correct value in CTRL

  // read the value of CTRL into a variable
  unsigned int prescaler = TIMER0->CTRL;

  // modify "value" to adjust bits [27:24] to the correct mode. Dummy code is
  // written below that you should modify
  prescaler = prescaler;

  // write this new configuration back to TIMER0->CTRL
  TIMER0->CTRL = prescaler;

  //Step 1.4: Configure TIMER0 DebugRun bits. Set bit 6 in CTRL to 0x1.
  // read the value of CTRL into a variable
  unsigned int debugRun = TIMER0->CTRL;

  // modify "value" to adjust bit [6] to the correct mode. Dummy code is
  // written below that you should modify
  debugRun = debugRun;

  // write this new configuration back to TIMER0->CTRL
  TIMER0->CTRL = debugRun;

  /**
   * Step 2: The timer is now configured but is not yet running.
   * While the timer is running we will monitor the value of CNT
   * until it reaches a desired threshold. However, the threshold should be
   * calculated first.
   */

  //query the timer to determine driving clock frequency. Should be 48 MHz.
  int timerClock = CMU_ClockFreqGet(cmuClock_TIMER0);

  // Step 2.1: Read Slide p.48 to determine what TOP/Threshold value should be calculated
  // threshold = (duration * clock freq) / pre-scaler
  // Complete the calculation below to determine what threshold
  // will lead to a 1s timer.
  unsigned int seconds = 0; // select how long you wish to time
  unsigned int preScaler = 0; // enter the prescaler value that was configured
  unsigned int threshold = (seconds*timerClock)/preScaler; // do the math...

  // Step 2.2: Start the timer by writing a bit 0x1 to position 0 in CMD
  TIMER0->CMD=(TIMER0->CMD)|(0x1<<0);

  // Step 2.3: Write a WHILE loop that perpetually reads the TIMER0 CNT
  // register. Complete the line below
  //while(TIMER0->CNT<=...){}

  // Step 2.4: Stop the timer. Write a 0x1 to pos [1] in CMD register
  // Complete the line below. You may wish to examine the previous line that
  // started the timer.
  //TIMER0->CMD=....


  // Step 2.5: Reset the CNT register to 0x0 so the loop will operate correctly
  // the next time through. Complete the line below..
  // TIMER0->CNT = ...

  // Step 2.6: toggle the LED using Dr. Forsyth's code
  toggleLED(gpioPortE, 2);




}
