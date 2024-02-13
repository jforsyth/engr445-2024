#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string>& splits(string line)
{
    vector<string> parts;

    int start_pos=0;
    int end_pos=-1;

    while(start_pos!=-1)
    {
        end_pos = line.find_first_of(',');
        if (end_pos==-1)
        {
            parts.push_back(line);
            break;
        }
        string sub_string = line.substr(start_pos,end_pos);
        parts.push_back(sub_string);
        line = line.substr(end_pos+1,line.length()-1);

        if (line.empty())
        {
            break;
        }
    }

    return parts;
}

int main()
{
	//create the path to the file
	string filePath = "p1.1_Female_20-29_170-179cm_Hand_held.out.csv";

    // since executing from debug, point up a directory
    filePath="../"+filePath;

	//create an input file stream to hold the file
	ifstream in;

	//open the file
	in.open(filePath.c_str());

	//while there's data in the file...
	while (in.good())
	{
		//read in a single line
		string line = "";
		in >> line;

		//print out the line
		//cout << line << endl;

		/**
		* Break the line into pieces based upon ',' and convert elements to integers
		*/

        vector<string> subParts = splits(line);

		//find the first two commas. Code will break if there are more :)
		//int firstComma = line.find_first_of(',');
		//int secondComma = line.find(',', firstComma + 1);

		//using the commas break into substrings
		//string x = line.substr(0, firstComma);
		//string y = line.substr(firstComma + 1, secondComma-firstComma-1);
		//string z = line.substr(secondComma + 1, line.size()-secondComma-1);

		//take each substring and convert into integer
		int xInt = atoi(x.c_str());
		int yInt = atoi(y.c_str());
		int zInt = atoi(z.c_str());

		cout << xInt << "," << yInt << "," << zInt << endl;
	}


}