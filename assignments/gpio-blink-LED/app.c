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

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init (void)
{
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/

/**
 * Necessary includes...
 */
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"

#include <stdint.h>

/**
 * Place definitions of useful registers below using the
 * #define methods described in class.
 */

//add UL to make sure the math is done correctly
#define GPIO_BASE_ADDRESS 0x40006000UL

//Port E definitions and addresses
#define GPIO_PE_MODEL_OFFSET 0x094UL
#define GPIO_PE_DOUT_OFFSET 0x09CUL
#define GPIO_PE_MODEL_ADDR (GPIO_BASE_ADDRESS+GPIO_PE_MODEL_OFFSET)
#define GPIO_PE_DOUT_ADDR (GPIO_BASE_ADDRESS+GPIO_PE_DOUT_OFFSET)


void
app_process_action (void)
{
  /**
   * LED0 <-> PE2
   * LED1 <-> PE3
   */

  /**
   * Task 1: Pure Pointer Math. Calculate the addresses for PE_MODEL
   * and PE_DOUT to manually configure the bits for LED1/PE3
   */

  /**
   * Approach #1: Raw pointer math
   */
  // Step 1: create a pointer to GPIO Port E MODE_L Register
  volatile uint32_t *PE_MODEL_PTR = (uint32_t*) GPIO_PE_MODEL_ADDR;

  // Step 2: read in the contents of GPIO Port E MODE_L Register into a local variable mode_L
  uint32_t mode_L = //your code here

  // Step 3: Modify the local variable to set PE3 as a Push/Pull Output
  mode_L = //your code here

  // Step 4: Write the local variable to the pointer to update the MODEL_L register
  (*PE_MODEL_PTR) = //your code here

  // Step 5: Create a pointer to the GPIO Port E DOUT Register
  //your code here

  // Step 6: read in the contents of DOUT register into a local variable DOUT
  //your code here

  // Step 7: write back to set PE3 DOUT to HIGH
  //your code here

  // Bonus! Can you extend/modify the code above to turn on LED0 which is attached
  // to PE2?

}
