// include iostream so we get cin and cout
#include <iostream>

// include vectors from the STD library
#include <vector>

// tell the program we're using the STD library so we don't have to write std:: everywhere
using namespace std;
int main()
{
    /**
     * This demo will show how vectors (variable length lists) can be
     * used within C++
     */

    /**
     * Creating a Vector and adding data
     */
    // like all variables, a vector must be given a type. Let's create one with ints
    vector<int> myVector;

    // vectors know how long they are. Since we just created it, the size should be 0.
    int size = myVector.size();

    cout << "Vector size is: " << size << endl;

    // elements can be appended to the end of the vector using push_back(). The element will be added
    // to the vector and its size will increase. The added must be same 'type' as defined above.
    myVector.push_back(10);
    cout << "Vector size is: " << myVector.size() << endl;

    // let's add a few more elements to vector to have some data to work with
    myVector.push_back(5);
    myVector.push_back(2);
    myVector.push_back(4);

    /**
     * Accessing Elements in a Vector
     */
    // elements in a vector, list, or array can be accessed with the [] operator
    // numbering begins at [0] for the 1st element (called the head or front()), [1] is the next location and so on
    // the last element is called the tail or back().

    // get the first element by position value [0]
    int first_element = myVector[0];

    // get the same first element using the special call to front()
    int front = myVector.front();

    // grab an element somewhere in the middle of the vector
    int middle = myVector[2];

    // use size to determine the length of the vector and use that information to find the last element
    int tail = myVector[myVector.size()-1];

    // a safer way to find the last element by calling back()
    int back = myVector.back();

    /**
     * Iterating Through Vectors
     */

    // very ofter the program will need to "walk through" a vector and examine its elements
    // this can be accomplished with a FOR loop in a variety for forms

    // Approach #1: This is the most basic FOR loop to walk through a vector.
    // We use the [] operator to access the elements
    // of the vector directly. To do this, we need enumerate [i] such that i starts at 0 (the first element) and
    // continues until size()-1. Each time through the loop i will be incremented (i++)
    for(int i=0;i<myVector.size();i++)
    {
        // grab the i-th element of the vector
        int element = myVector[i];

        // print out the contents
        cout << "At pos: " << i << " the vector has data " << element << endl;
    }

    // Approach #2: The FOR loop iteration pattern is standard/classic c++ but can be prone to errors, especially
    // if iterating across the vector goes "out of bounds" where i extends past the end of the vector
    // another approach is to us an iterator (an object that directly points to the vectors contents). This
    // methods "ensures" the access goes not go out of bounds.

    // use the iterator format. Each time through the loop "element" will contain a value of
    // my vector. It will start at the front and end at the back. Trouble is, we lose access to which
    // index the element is at. We could keep count though... but that defeats the purpose.
    for(int element : myVector)
    {
        cout << "Vector contains: " << element << endl;
    }

    // we can do several things while iterating through arrays. Here's an example below.
    // Before I forget though.. never add or delete elements in the vector while iterating through it!
    // Undetermined behaviour will occur. It's like ripping up a bridge while you're walking over it...

    // let's count the number of even values.
    int num_even=0;
    for(int element:myVector)
    {
        // note: figure out your own method to check if the value is even
        // if I see this in your solution then I know you just copied me.
        if ((element&0x1)==0x0)
        {
            num_even++;
            cout << element << " is even " << endl;
        }
    }

    /**
     * Removing data from vectors
     */

    // for our application our vectors will operate more like FIFOs (first-in, first-out) objects. The vectors
    // will likely be of fixed length. So once they fill up, and new data arrives, old data will have to be
    // deleted from the vector

    // let's delete the first element since it's the oldest.
    // We have to provide an "iterator" to the object to be deleted, not it's position
    // so we need to call begin() to get the beginning of the list.
    myVector.erase(myVector.begin());

    for(int element : myVector)
    {
        cout << "Vector contains: " << element << endl;
    }

    /**
     * Operations and modifications on a vector
     */

    // the previous examples have shown how to access, add, and erase elements from a vector.
    // below will implement some basic operations on the vector

    // take all the elements of myVector, double them, and add into newVector.
    vector<int> newVector;
    for(int i=0;i<myVector.size();i++)
    {
        int value = myVector[i];
        value = value*2;
        newVector.push_back(value);
    }

    // take all the elements of myVector, if they're even, add to a new vector. Do the same with odds.
    vector<int> evens;
    vector<int> odds;

    for(int element : myVector)
    {
        if (element%2==0)
        {
            evens.push_back(element);
        }
        else
        {
            odds.push_back(element);
        }
    }
}