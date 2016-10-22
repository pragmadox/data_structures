#include <iostream>
using namespace std;

int main() {
	// your code goes here
	const string BLANK = " ";
	const string SQUARE = BLANK + "\u2588" + BLANK;
	const string EMPTY_SQUARE = BLANK + "\u25fd" + BLANK;
	const string TRIANGLE = BLANK + "\u25b3" + BLANK;
	//cout << SQUARE;
	//cout << EMPTY_SQUARE;
	//cout << TRIANGLE;

    string test_array[9][9];
    test_array[0][0] = BLANK;
    test_array[0][1] = BLANK + "1" + BLANK;
    test_array[0][2] = BLANK + "2" + BLANK;
    test_array[0][3] = BLANK + "3" + BLANK;
    test_array[0][4] = BLANK + "4" + BLANK;
    test_array[0][5] = BLANK + "5" + BLANK;
    test_array[0][6] = BLANK + "6" + BLANK;
    test_array[0][7] = BLANK + "7" + BLANK;
    test_array[0][8] = BLANK + "8" + BLANK;
    test_array[1][0] = "1";
    test_array[2][0] = "2";
    test_array[3][0] = "3";
    test_array[4][0] = "4";
    test_array[5][0] = "5";
    test_array[6][0] = "6";
    test_array[7][0] = "7";
    test_array[8][0] = "8";

    for(int i=1; i<9; i++)
    {
        for(int j=1; j<9; j++)
        {
            test_array[i][j] = SQUARE;
        }
    }

    test_array[1][4] = TRIANGLE;
    test_array[2][4] = EMPTY_SQUARE;
    test_array[3][4] = EMPTY_SQUARE;
    test_array[3][5] = EMPTY_SQUARE;
    test_array[4][3] = EMPTY_SQUARE;
    test_array[4][4] = EMPTY_SQUARE;
    test_array[4][5] = EMPTY_SQUARE;
    test_array[4][6] = EMPTY_SQUARE;
    test_array[5][3] = EMPTY_SQUARE;
    test_array[5][6] = EMPTY_SQUARE;
    test_array[6][6] = EMPTY_SQUARE;
    test_array[7][6] = EMPTY_SQUARE;
    test_array[8][6] = TRIANGLE;

    //print the array
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cout << test_array[i][j];
        }
        cout << endl << endl;

    }


	return 0;
}
