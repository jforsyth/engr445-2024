#include <iostream>
#include <cstdlib>
using namespace  std;

/**
 * An example Finite State Machine implementation for a design
 * that randomly samples the number line, and if the result is two consecutive even values,
 * prints out a message.
 */

int main()
{
    // enumerate all potential states
    enum State {INIT, SINGLE_EVEN, DOUBLE_EVEN, ODD};

    // create variables for current and future state
    // initialize them to an appropriate starting value
    State currentState = INIT;
    State nextState = INIT;

    // initialize the random number seed.
    sranddev();



    // this loop will run forever... but let's put a 10 item limit on it
    int loop_counter=0;
    while(loop_counter<10)
    {
        // sample the random number distribution
        int random_number=rand();

        cout << "Value is " << random_number << endl;

        switch (currentState)
        {
            case INIT:

                // Perform State Action
                // ...nothing to do here...

                // Perform Next State Logic
                // is the random sample EVEN or ODD
                if(random_number%2==0)
                {
                    nextState=SINGLE_EVEN;
                }
                else
                {
                    nextState=ODD;
                }

                // must end with BREAK statement otherwise will go to next statement/case/state
                break;

            case SINGLE_EVEN:

                // Perform State Action
                // ...nothing to do here...


                // Perform Next State Logic
                // is the random sample EVEN or ODD
                if(random_number%2==0)
                {
                    nextState=DOUBLE_EVEN;
                }
                else
                {
                    nextState=ODD;
                }

                break;

            case ODD:

                // Perform State Action
                // ...nothing to do here...

                // Perform Next State Logic
                // is the random sample EVEN or ODD
                if(random_number%2==0)
                {
                    nextState=SINGLE_EVEN;
                }
                else
                {
                    nextState=ODD;
                }

                break;

            case DOUBLE_EVEN:
                // Perform State Action
                cout << "WOO HOO! WE DID IT!" << endl;

                // Perform Next State Logic
                // is the random sample EVEN or ODD
                if(random_number%2==0)
                {
                    nextState=DOUBLE_EVEN;
                }
                else
                {
                    nextState=ODD;
                }

                break;

            default:
                // this should never happen!!
                cout << "Error!!" << endl;
        }

        // update state variables. Very important or machine will not advance.
        currentState=nextState;

        // increment the loop counter so we don't do this forever
        loop_counter++;
    }

}
