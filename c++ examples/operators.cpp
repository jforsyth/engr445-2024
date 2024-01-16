#include <iostream>
using namespace std;

int main()
{
    /**
     * Addition and subtraction...
     * https://cplusplus.com/doc/tutorial/operators/
     */

    int one = 1;
    int two = 2;
    int add = one + two;
    cout << "1 + 2 = " << add << endl;

    int subtract = one - two;
    cout << "1 - 2 = " << subtract << endl;

    float decimal = 0.1;
    int result = one + decimal;
    cout << "1 + 0.1 = " << result << endl;
    cout << "Maybe we should make that int a float...";
    float better_result = (float)one + decimal;
    cout << "1 + 0.1 = " << better_result << endl;

    /**
     * Multiplication and Division
     * Take care to differentiate between (int) and (float) operations
     */

    //multiplication with ints and floats
    cout << "1 * 2 = " << 1*2 << endl;
    cout << "1.0 * 2 = " << 1.0*2 << endl;
    cout << "1.5 * 2 = " << 1.5*2 << endl;

    //division with ints and floats
    cout << "5/2 = " << 5/2 << endl;
    cout << "5/2.0 = " << 5/2.0 << endl;
    cout << "1/2 = " << 1/2 << endl;
    cout << "1.0 / 2.0 = " << 1.0 / 2.0 << endl;

    //modulus (remainder)
    cout << "5 % 2 = " << 5%2 << endl;

    //increment and decrement
    int i=0;
    cout << "i = " << i << endl;
    cout << "i++ = " << i++ << "...wait..that didn't work..." << endl;
    cout << "i = " << i << "..huh..I guess it did work. C++ is weird" << endl;

    i=0;
    i+=10;
    cout << "i+=10 is " << i << endl;

    //boolean operators (AND, OR, and NOT)
    // Logical operators (&&, ||, !)
    // Bitwise operators (&, |, ~)
    bool a = true;
    bool b = false;

    cout << "a is "<< a << " and b is " << b << endl;

    bool bool_result = a&&b;
    cout << "a AND b = " << bool_result << endl;

    bool_result = a||b;
    cout << "a OR b = " << bool_result << endl;

    cout << "!a = " << !a << endl;

    return 0;
}