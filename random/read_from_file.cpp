#include <iostream>
#include <fstream>
using namespace std;

//Reading data from a file
int main()
    {
	// your code goes here
	const string BLANK = " ";
	const string SQUARE = BLANK + "\u2588" + BLANK;
	const string EMPTY_SQUARE = BLANK + "\u25fd" + BLANK;
	const string TRIANGLE = BLANK + "\u25b3" + BLANK;

    string line;
    fstream myfile("example.txt");
    if(myfile.is_open())
    {
        while(getline(myfile,line))
        cout << line << endl;
    }
    else
        cout << "Unable to open file.";
    myfile.close();
    return 0;
    }
