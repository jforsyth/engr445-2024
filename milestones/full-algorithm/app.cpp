
//include accelerometer class
#include "ADXL345.h"

//include XBee to talk to computer
#include "Xbee.h"

//include custom timer object
#include "PeriodicTimer.h"

//include vectors, math, string
#include <vector>
#include <cmath>
#include <string>

//define appropriate namespace
using namespace std;

//ADXL object
ADXL345 accel;

//Xbee object
Xbee xbee;

//Timer object
PeriodicTimer timer;

/**
 * Place all operations here that will be run "once". These include initializing the
 * SPI, UART, and TIMER Interfaces
 */
void app_init(void)
{

  //enable the clock for the High-Frequency Peripherals
  CMU_ClockEnable(cmuClock_HFPER, true);

  //enable the specific clock for the TIMER0
  CMU_ClockEnable(cmuClock_TIMER0, true);

  //initialize accelerometer
  accel.initialize();

  bool success = accel.selfTest();

  //infinite loop if self-test fails
  while(!success){}

  //initialize Xbee
  xbee.initialize();

  //initialize periodic timer
  timer.initialize();

  /* Turn on board LEDS for debugging purpose */
  GPIO_PinModeSet(gpioPortE,                /* GPIO port */
                  2,                        /* GPIO port number */
                  gpioModePushPull,         /* Pin mode is set to push pull */
                  0);                       /* High idle state */

}



/**
 * Initialize all global/static variables
 */


//containers for raw accel data
vector<float> accelX;
vector<float> accelY;
vector<float> accelZ;

//results of datapath
vector<float> magnitude;
vector<float> diff;
vector<float> square;
vector<float> moving_average;
const int N = 10;
int mySteps = 0;

//any FSM data that might be needed
enum State {
  INIT, STATE_A, STATE_B, STATE_C
};
State currentState = INIT;
State nextState = INIT;
int threshold = -1;
bool initialized = false;

/**
 * Place all code that will happen "everytime" in this block. Should include
 * - Acquiring Data from Accel
 * - Processing Data in Datapath
 * - Determining whether a step has occurred via FSM
 * - Report steps via Xbee
 * - Sleep processor (optional)
 */

void app_process_action(void)
{

  /**
   * Step 1: Acquire data from ADXL345
   */
  int16_t xAccel = accel.getXAcceleration();
  int16_t yAccel = accel.getYAcceleration();
  int16_t zAccel = accel.getZAcceleration();

  accelX.push_back(xAccel);
  accelY.push_back(yAccel);
  accelZ.push_back(zAccel);

  /**
   * Step 2: Put new acceleration data through data path
   */

  //YOUR DATA PATH CODE HERE. Example code below.

  int32_t mag = sqrt(xAccel*xAccel + yAccel*yAccel + zAccel*zAccel);

  /**
   * Step 3: Decide whether a step has occurred
   */

  //YOUR FSM CODE HERE. Example code below.



  /**
   * Step 4: Report what you like back to the PC via Xbee
   * Use to_string() to convert anything to a string
   */
  string s = to_string(mySteps);
  xbee.sendString(s);

  /**
   * Step 5: Sleep the processor for 1s
   */
  // wait for 1s = 1000 ms
  timer.wait(1000);

  // toggle the on-board LED for debugging purposes
  GPIO_PinOutToggle(gpioPortE,2);
}
