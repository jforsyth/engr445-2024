/**
* This example aligns with Section 3.1 from the textbook
*/

/**
 * Include the two libraries we will use
 * <iostream> allows to read from the terminal and to print data to the terminal
 * <string> allows the use of strings (sequences of characters)
 */
#include <iostream>
#include <string>

/**
 * This line tells C++ where to look for certain names. Technically this is bad practice but the
 * alternative is to put std:: in front of everything which is annoying.
 */
using namespace std;

int main()
{
    /**
     * Use COUT to print something to the screen. The words must be ended with a new line (ENDL)
     */

    cout << "Please enter your first name followed by ENTER: " << endl;

    /**
     * Create a variable to hold some future information. We will use a string, which is a sequence
     * of characters. Note: this variable can be declared uninitialized which is BAD.
     */
    string first_name;

    /**
     * Use CIN to read the keyboard from the screen and place in the variable first_name.
     */
    cin >> first_name;

    /**
     * Use COUT again to print the result. New elements can be added with the << operator
     */
    cout << "Hello, " << first_name << endl;

    return 0;
}