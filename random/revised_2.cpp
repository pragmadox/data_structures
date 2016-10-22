#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//set the size of the labyrinth
const int SIZE = 10;

//declare a two-dimensional array that represents the labyrinth
char labyrinth[SIZE][SIZE] = {{0}};

//declare a two-dimensional vector to accept the non-zero values from the data file.
vector < vector<char> > v;

void read_data_file( vector<vector<char> > &v)
{
    
    //declare a one-dimensional vector that can accept each element along the line of the data file.
    vector<char> row;

    //open the file containing integer data
    stringstream ss;
    
    //declare an integer "n";
    char element;

    //declare a string "line" for reading the data from the file;
    string line;
    
    //string variable initiated to hold the name of the data file.
    string fileName;
    
    cout << "Enter the name of the data file with its extension: ";
    //Input the name of the data file to be ingested.
    cin >> fileName;
    
    fstream myfile(fileName.c_str());
    if(myfile.is_open())
    {
        cout << "The data file is open.\n";
        while(getline(myfile,line))
        {
            ss.clear();
            ss.str ("");
            ss << line;
            while(ss >> element)
            {
                row.push_back( element );
            }
            v.push_back(row);
            row.clear();
        }
        myfile.close();
    }

    else
    {
        cout << "Unable to open file.";
    }

}

void print_vector( vector<vector<char> > v)
{
    for( int r = 0; r < v.size(); r++ )
    {
        for( int c = 0; c < v[r].size(); c++ )
        {
            cout << setw(3) << v[r][c];
        }
        cout << endl;
    }
}

void print_labyrinth( char labyrinth[SIZE][SIZE], vector<vector<char> > v)
{
    //define the characters that will be needed to print out the labyrinth
    string const BLANK = " ";
    string const BLOCK = "\u25a0";
    string const EMPTY_SPACE = "\u25fd";
    string const TRIANGLE = "\u25b3";
    
    const int difference = (SIZE-v.size())/2;
    for(int diw=0; diw<difference; diw++)
        cout << setw(5) << " ";

    int column_num = 0;
    cout << setw(5) << " ";
    for(int c=0; c<(v.size()); c++)
    {
        cout << setw(5) << column_num;
        column_num++;
    }
    cout << endl << endl;

    int row_num = 0;
    for(int r=0; r<SIZE; r++)
    {
        cout << setw(5) << row_num;
        row_num++;

        for(int c=0; c<SIZE; c++)
        {
            switch(labyrinth[r][c])
            {
            case '*':
                cout << setw(7) << BLOCK;
                break;
            case 'E':
                cout << setw(7) << TRIANGLE;
                break;
            case '-':
                cout << setw(7) << EMPTY_SPACE;
                break;
            case '|':
                cout << setw(7) << TRIANGLE;
                break;
            default:
                cout << setw(7) << BLANK;
            }
        }
        cout << endl << endl;
    }
}

void fill_labyrinth( char labyrinth[SIZE][SIZE], vector<vector<char> > &v)
{
    int filling_index;
    for( int r=0; r<SIZE; ++r)
        if(r < v.size())
        {
            filling_index = (SIZE - v[r].size())/2;
            for(int c=0; c<v[r].size(); ++c)
                labyrinth[r][c+filling_index] = v[r][c];
        }
}

int solve(int x, int y)
{    
    int success = 0;
        switch( labyrinth[x][y])
        {
            case '|': success = 1;
                break;
            case '*': success = 0;
                break;
            case 'T': success=0;
                break;
            default: labyrinth[x][y] = 'T';
            success = solve(x+1, y) + solve(x, y+1) + solve(x-1, y) + solve(x, y-1);
                break;
        }
        if(success>0)
            cout << "X coordinate is: " << x << "\tY coordinate is: " << y << endl;
    return success;
}

int main()
{

read_data_file(v);
print_vector(v);
cout << endl;
fill_labyrinth(labyrinth, v);
print_labyrinth(labyrinth, v);
solve(0,4);

return 0;
}
