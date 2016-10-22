#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Maze
{

//define the characters that will be needed to print out the labyrinth
static const int SIZE = 10;

private:
//declare a two-dimensional array that represents the labyrinth
char labyrinth[SIZE][SIZE] = {{0}};
//declare a two-dimensional vector to accept the non-zero values from the data file.
vector <vector<char> > v;

    public:
    void print_vector( vector<vector<char> > v)
    {
        for( int r = 0; r < v.size(); ++r )
        {
            for( int c = 0; c < v[r].size(); ++c )
            {
                cout << setw(3) << v[r][c];
            }
            cout << endl;
        }
    }

    public:
    void print_labyrinth( char labyrinth[SIZE][SIZE], vector<vector<char> > v)
    {
        
        string const BLANK = " ";
        string const BLOCK = "\u25a0";
        string const EMPTY_SPACE = "\u25fd";
        string const TRIANGLE = "\u25b3";
        
        cout << setiosflags(ios::left);
        for(int diw=1; diw<=((SIZE-v.size())/2); diw++)
            cout << setw(5) << " ";

        int column_num = 0;
        for(int c=0; c<(v.size()); c++)
        {
            cout << setw(5) << column_num;
        column_num++;
        }
        cout << endl << endl;

        int row_num = 0;
        for(int r=0; r<SIZE; r++)
        {
            if(row_num < 10)
                cout << row_num << " ";
            else
                cout << row_num;
            row_num++;

            for(int c=0; c<SIZE; c++)
            {
                switch(labyrinth[r][c])
                {
                case 'w':
                    cout << setw(5) << BLOCK;
                    break;
                case 't':
                    cout << setw(5) << EMPTY_SPACE;
                    break;
                case 'e':
                    cout << setw(5) << TRIANGLE;
                    break;
                default:
                    cout << setw(5) << BLANK;
                }
            }
            cout << endl << endl;
        }
    }

    public:
    void fill_labyrinth( char labyrinth[SIZE][SIZE], vector<vector<char> > v)
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

    public:
    void fill_vector( vector<vector<char> > v)
    {
        //declare an integer "n";
        char element;

        //declare a string "line" for reading the data from the file;
        string line;

        //declare a one-dimensional vector that can accept each element along the line of the data file.
        vector<char> row;

        //open the file containing integer data
        stringstream ss;

            fstream myfile("example2.txt");
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
                        row.push_back(element);
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
};

int main()
{

mymaze Maze;

mymaze.fill_vector(v);
mymaze.print_vector(v);
cout << endl;
mymaze.fill_labyrinth(labyrinth, v);
mymaze.print_labyrinth(labyrinth, v);

return 0;
}
