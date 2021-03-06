#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//define the characters that will be needed to print out the labyrinth
const int SIZE = 20;
string const BLANK = "   ";
string const BLOCK = " \u25a0 ";
string const EMPTY_SPACE = " \u25fd ";
string const TRIANGLE = " \u25b3 ";

void print_vector( vector<vector<int> > v)
{
    cout << "The function for printing the vector of vectors has been called.\n";
    for( int r = 0; r < v.size(); ++r )
    {
        for( int c = 0; c < v[r].size(); ++c )
        {
            cout << setw(3) << v[r][c];
        }
        cout << endl;
    }
}

void print_labyrinth( const int labyrinth[SIZE][SIZE])
{
    for(int r=0; r<SIZE; r++)
    {
        for(int c=0; c<SIZE; c++)
        {
            switch(labyrinth[r][c])
            {
            case 8:
                cout << EMPTY_SPACE;
                break;
            case 1:
                cout << BLOCK;
                break;
            case 7:
                cout << TRIANGLE;
                break;
            default:
                cout << BLANK;
            }
        }
        cout << endl << endl;
    }
}

void fill_labyrinth( int labyrinth[SIZE][SIZE], vector<vector<int> > v)
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

int main()
{

//declare an integer "n";
int element;

//declare a string "line" for reading the data from the file;
string line;

//declare a two-dimensional array that represents the labyrinth
int labyrinth[SIZE][SIZE] = {{0}};

//declare a two-dimensional vector to accept the non-zero values from the data file.
vector < vector<int> > v;

//declare a one-dimensional vector that can accept each element along the line of the data file.
vector<int> row;

//open the file containing integer data
stringstream ss;

//print_vector(v);
//fill_labyrinth(labyrinth, BLANK);
//print_labyrinth(labyrinth);
//fill_labyrinth(labyrinth, v);
//print_labyrinth(labyrinth);

//print a two-dimensional vector



    fstream myfile("example.txt");
    if(myfile.is_open())
    {
        cout << "The data file is open.\n";
        while(getline(myfile,line))
        {
            ss.clear();
            ss.str ("");
            ss << line;
            while(ss)
            {
                ss >> element;
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

print_vector(v);
cout << endl;
fill_labyrinth(labyrinth, v);
print_labyrinth(labyrinth);

return 0;
}
