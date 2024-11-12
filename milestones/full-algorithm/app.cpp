
//include accelerometer class
#include "ADXL345.h"

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

//Timer object
PeriodicTimer timer;


/**
 * Define all global variables and data arrays
 */
const int ARRAY_LENGTH = 16;
float magnitude[ARRAY_LENGTH];
float diffs[ARRAY_LENGTH];
float squares[ARRAY_LENGTH];
float averages[ARRAY_LENGTH];

/**
 * Enumerate some basic states the machine may wish to follow
 */
enum STATE {IDLE, DETECT, TIMEOUT};
STATE currentState;
STATE nextState;


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

  /**
   * Initial all arrays defined above to known values. Really should be 0.
   * Will use FOR LOOP that is very inefficient but is guaranteed to work on all systems
   */

  for(int i=0;i<ARRAY_LENGTH;i++)
    {
      magnitude[i]=0;
      diffs[i]=0;
      squares[i]=0;
      averages[i]=0;
    }

  // Initialize the states of the machine to the initial one
  currentState = IDLE;
  nextState = IDLE;

  //initialize accelerometer
  accel.initialize();

  bool success = accel.selfTest();

  //infinite loop if self-test fails
  while(!success){}

  //initialize periodic timer
  timer.initialize();

  /* Turn on board LEDS for debugging purpose */
  GPIO_PinModeSet(gpioPortE,                /* GPIO port */
                  2,                        /* GPIO port number */
                  gpioModePushPull,         /* Pin mode is set to push pull */
                  0);                       /* High idle state */

}

int counter = 0;
void app_process_action(void)
{

  /**
   * Step 1: Acquire data from ADXL345
   */
  int16_t xAccel = accel.getXAcceleration();
  int16_t yAccel = accel.getYAcceleration();
  int16_t zAccel = accel.getZAcceleration();



  /**
   * Step 2: Put new acceleration data through data path
   */

  //YOUR DATA PATH CODE HERE. Example code below.

  int32_t mag = sqrt(xAccel*xAccel + yAccel*yAccel + zAccel*zAccel);

  float g_magnitude = mag / 256.0;

  /**
   * Step 3: Run your analysis pipeline
   */

  // YOUR DATAPATH CODE HERE....


  /**
   * Step 4: Run your finite state machine
   */
  //YOUR FSM CODE HERE. Example code below.




  /**
   * Step 5: Sleep the processor for a fixed duration. This will be the
   * sample rate for the project.
   */
  // wait for 1s = 1000 ms
  timer.wait(1000);

  // toggle the on-board LED for debugging purposes
  GPIO_PinOutToggle(gpioPortE,2);
}
