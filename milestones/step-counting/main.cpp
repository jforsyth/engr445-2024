#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/**
 * Dr. Forsyth's code for parsing a string...
 * @param line The string to be parsed
 * @param container A vector<string> container to hold the results
 * @return Return True if we successfully complete. False otherwise.
 */
bool splits(string line, vector<string>& container)
{
    vector<string>& parts = container;

    int start_pos=0;
    int end_pos=-1;

    while(start_pos!=-1)
    {
        end_pos = line.find_first_of(',');
        if (end_pos==-1 && !line.empty())
        {
            parts.push_back(line);
            return true;
        }
        string sub_string = line.substr(start_pos,end_pos);
        parts.push_back(sub_string);
        line = line.substr(end_pos+1,line.length()-1);

        if(line.empty())
        {
            return true;
        }
    }

    return false;
}

int main()
{
	//create the path to the file. You can the name to access different files
	string filePath = "48_steps.csv";

    // since executing from debug, point up a directory.
    // Don't change this unless you know what you're doing...
    filePath="../"+filePath;

	//create an input file stream to hold the file
	ifstream in;

	//open the file
	in.open(filePath.c_str());

    if(in.fail())
    {
        cout << "Failed opening file: " << filePath << endl;
        cout << "Could not open file! Check file path. Consider using an absolute path.";
        return -1;
    }


    /**
     * Create containers to hold the accel X, Y, and Z data.
     * Each time through the loop one sample will be added to each vector<>
     */
    vector<float> accelX;
    vector<float> accelY;
    vector<float> accelZ;

    /**
     * Create any initial global variables your program might need...
     */
     enum State {STATE_A, STATE_B, STATE_C};
     int threshold = -1;

    //while there's data in the file...
	while (in.good())
	{
		//read in a single line
		string line = "";
		in >> line;

        //ignore any blank lines
        if (line.empty())
        {
            continue;
        }

		/**
		* Break the line into pieces based upon ',' and convert elements to integers
		*/
        vector<string> subParts;
        bool success = splits(line,subParts);

        /**
         * Convert elements of string into numbers (floats for this dataset)
         */

        // ignore the header information or quick if fails
        if(subParts[0]=="time" || !success)
        {
            continue;
        }

        /**
         * Pull out the X, Y, and Z acceleration and convert to floats.
         * This can be expanded for other data types in the file
         * Each column, for this particular row, now resides as elements of the string
         * Time = [0]
         * AccelX = [1]
         * AccelX = [2]
         * AccelX = [3]
         * GyroX = [4]
         * ... etc
         * 
         * If you are operating on a file with a different structure, adjust the values
         * 1, 2, and 3 below to be the columns that hold the X, Y, and Z acceleration.
         * 0 is the "first column", 1 is the "second"..etc.
         */
        float x = atof(subParts[0].c_str());
        float y = atof(subParts[1].c_str());
        float z = atof(subParts[2].c_str());

        /**
         * Take the data from the single line and add it into our own vector
         */
        accelX.push_back(x);
        accelY.push_back(y);
        accelZ.push_back(z);

        // comment the line below to quiet all the data coming out...
        cout << "X: " << x << "\tY:" << y << "\tZ: " << z << endl;

        /**
         * BEGIN YOUR DATAPATH CODE HERE
         */

        //your code here

        /**
         * BEING YOUR FINITE STATE MACHINE CODE HERE
         */

        // your code here

	}

    /**
     * Report the number of steps counted over all...
     */


}