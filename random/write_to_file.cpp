#include <iostream>
#include <fstream>
using namespace std;

//Writing data
int main()
    {
	// your code goes here
	const string BLANK = " ";
	const string SQUARE = BLANK + "\u2588" + BLANK;
	const string EMPTY_SQUARE = BLANK + "\u25fd" + BLANK;
	const string TRIANGLE = BLANK + "\u25b3" + BLANK;


    ofstream myfile("example.txt", ios::out | ios::app | ios::binary );
    myfile << "Example text written to file.\n";
    myfile.close();
    return 0;
    }
