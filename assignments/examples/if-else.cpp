#include <iostream>

using namespace std;

int main() {
    /*
     * Conditionals help the computer make decisions. In each situation an "expression"
     * is tested to see whether it is TRUE or FALSE. Depending upon the result, certain
     * blocks of code are executed
     */

    /*
     * Simple IF-ELSE statement. The IF will execute if the statement is TRUE, otherwise the
     * ELSE will execute
     */
    int my_value = 5;

    if (my_value < 10) {
        cout << "The value is less than 10..." << endl;
    } else {
        cout << "The greater than or equal to 10..." << endl;
    }

    /*
    * The previous example is pretty boring. Let's read in a value from the terminal and try out
     * something different...
    */
    int new_value = 0;
    cout << "Type in an integer value: " << endl;
    cin >> new_value;

    if (new_value < 10) {
        cout << "The value is less than 10..." << endl;
    } else {
        cout << "The greater than or equal to 10..." << endl;
    }

    /*
     * Now let's do the same process but read in two values...
     */
    int value_one = 0; int value_two = 0;
    cout << "Type in two values. One on each line. \nFirst value: ";
    cin >> value_one;
    cout << "Second value: ";
    cin >> value_two;

    if (value_one >= value_two)
    {
        cout << "Value One: " << value_one << " is greater than or equal to Value Two: " << value_two << endl;
    }
    else
    {
        cout << "Value One: " << value_one << " is less than Value Two: " << value_two << endl;
    }

    return 0;
}