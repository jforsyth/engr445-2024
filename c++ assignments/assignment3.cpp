#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265358979

int main()
{
    /**
     * Use the Gauss-Legendre Algorithm (https://en.wikipedia.org/wiki/Gauss%E2%80%93Legendre_algorithm)
     * to estimate the value of PI. This iterative algorithm should be performed 10x times.
     *
     * Once completed, print out the final result and compare it to the encoded value of PI
     *
     * Hint: You may want to reference CMATH: https://cplusplus.com/reference/cmath/
     *
     * Hint2: This algorithm is iterative. a_n is the current value of a. a_n+1 is the future value after some
     * calculate is performed. You need to "update" the variables after each loop. It may be helpful to keep
     * track of "a" (meaning a at present) and "a_next" (future value of a)
     */

    //Step 1: Declare Initial Variables (decimal points are important!!)
    double your_estimated_pi=0;
    double a = 1.0;
    double b = 1/sqrt(2);
    double t= 1.0/4.0;
    double p=1.0;

    //Step 2: Perform the iterative algorithm for 10x steps
    for(int i=0;i<10;i++)
    {
        /**
        * YOUR CODE HERE
        */
    }

    //Step 3: Print out results. After 10x iterations the error should be less than 1*10^-15
    cout << "My value of PI is " << your_estimated_pi << endl;
    cout << "Error on this value is " << PI-your_estimated_pi << endl;



    return 0;
}