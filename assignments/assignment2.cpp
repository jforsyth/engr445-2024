#include <iostream>
#include <random>
#include <ctime>
using namespace std;

/*
 * Ignore the function called randomPopulate() this is Dr. Forsyth's
 * and needed to make the program work
 */
int randomPopulate(int*& data)
{
    //provide a random seed
    srand(time(nullptr));

    //generate random length between 1 - 100
    int length = (rand() % 100) + 1;

    //create a new array of that length
    data = new int[length];

    //populate array with random values between 1 and 1000
    int* ptr = data;
    for (int i = 0; i < length; i++)
    {
        int value = (rand() % 1000) + 1;
        *ptr = value;
        ptr++;
    }

    return length;
}

int main()
{

    /**
    *
    * Dr. Forsyth prepares a random array of data...
    *
    */
    int* data = nullptr;
    int length = randomPopulate(data);

    std::cout << "Data is : ";
    for (int i = 0; i < length; i++)
    {
        std::cout << data[i] << std::endl;
    }

    /**
     * Step 1: Walk through the array and count the number of even and odd values.
     * Print out the results once completed.
     *
     * The array of integers is called data[]. Its length is
     *  stored in a variable called "length"
     */
     int num_even=0;
     int num_odd=0;
     /**
      * YOUR CODE HERE
      */

     

    /**
    *  Step 2: Calculate the minimum, maximum, and average of the array
     *  The array of integers is called data[]. Its length is
     *  stored in a variable called "length"
    */

    int min = -1;
    int max = -1;
    float average = -1;

    /**
     * Your code goes here...
     */

    cout << "Minimum value is: " << min << endl;
    cout << "Maximum value is: " << max << endl;
    cout << "Average value is: " << average << endl;


    return 0;

}