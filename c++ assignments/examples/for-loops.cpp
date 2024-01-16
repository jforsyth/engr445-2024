#include <iostream>
using namespace std;

int main()
{
    /*
     * The code below creates an ARRAY of integers. These are 5 values collected into a single
     * object. They are stored contiguously in memory (next to one another). The array begin uninitialized
     * and values will need to be entered into it;
     */
    int array[5];

    cout << "Type in 5 integers to fill up the array. Value 1:"; cin >> array[0];
    cout << "\nValue 2: "; cin >> array[1];
    cout << "\nValue 3: "; cin >> array[2];
    cout << "\nValue 4: "; cin >> array[3];
    cout << "\nValue 5: "; cin >> array[4];

    cout << "The contents of the array are...";
    cout << array[0] << " ";
    cout << array[1] << " ";
    cout << array[2] << " ";
    cout << array[3] << " ";
    cout << array[4] << endl;

    /*
     * The code above works, but it's pretty annoying to write the code 5x for each element of the array.
     * It would be better if the operations could occur repeatedly. A FOR loop is a good way to repeat
     * an operation a certain number of times.
     */

    /* This FOR loop looks complicated but is easier to understand in three parts. The main body
     * of the loop has three parts (<init>,<while>,<increment>). In general the <init> block occurs
     * the first time the FOR statement is encountered. At the end of the FOR loop the <increment>
     * statement will execute. This process continues while the <while> condition is TRUE. Once it becomes
     * FALSE, the loop will end.
     */
    for(int i=0;i<5;i++)
    {
        // create a variable to hold the new value
        int new_value = 0;

        // print out a message and read in a new value
        cout << "Type in Value: " << i << " :";
        cin >> new_value;

        // place the new value in the array. Note: the value of "i" should
        // align with the intended location in array[]
        array[i] = new_value;
    }

    // reverse the process and print out the array contents
    cout << "The contents of the array are...";
    for(int i=0;i<5;i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;



    return 0;
}