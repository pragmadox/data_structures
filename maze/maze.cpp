#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "maze.h"
#include "stack6.h"

using namespace std;    

//declare a two-dimensional array that represents the labyrinth
char labyrinth[SIZE][SIZE] = {{'*'}};

//declare a two-dimensional vector to accept the non-zero values from the data file.
vector < vector<char> > v;

void Maze::read_data_file()
{
    
    //declare a one-dimensional vector that can accept each element along the line of the data file.
    vector<char> row;

    //declare a stringstream object for holding the data from the file
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

    //Open the file for the name that was given and convert the string
    //that was holding the value into a const string.
    fstream myfile(fileName.c_str());
    //If statement checks to see if the file is open, then proceeds
    if(myfile.is_open())
    {

        //Prints a message to notify that the file is open.
        cout << "The data file is open.\n";

        //While the function is able to retrieve another line, the following occurs.
        while(getline(myfile,line))
        {
            //The stringstream variable is cleared
            ss.clear();
            //The stringstream contents are converted to a string
            ss.str ("");
            //The contents of the line from the file are transferred to the stringstream
            ss << line;
            //While the stringstream (consisting of a line of data) is able to pass an
            //additional character to the element variable (of type char), the following occurs
            while(ss >> element)
            {
                //The element that was passed (one character) is addended to the vector variable
                //called 'row'
                row.push_back( element );
            }
            //When the end of the line is reached, the loop concludes and the entire row of data
            //which was stored in the vector variable 'row' is addended to the vector of vectors variable
            //called 'v'.
            v.push_back(row);
            //The vector variable for storing a row of data 'row' is cleared, allowing it to
            //accept a new line of data.
            row.clear();
        }
        //When all lines of data have been ingested the file is closed.
        myfile.close();
    }

    //If there is a problem opening the file, a message is displayed.
    else
    {
        cout << "Unable to open file.";
    }

}

//This function prints the contents of the vector of vectors variable to show what data
//was transferred to it by the 'read_data_file' function.
void Maze::print_vector()
{
    //A for loop iterates through the vector of vectors as long as the int variable 'r'
    //remains smaller than the length.
    for( int r = 0; r < v.size(); r++ )
    {
        //A for loop iterates through the vector of vectors as long as the int variable 'c'
        //remains smaller than the width.
        for( int c = 0; c < v[r].size(); c++ )
        {
            //For every set of x,y indices, the corresponding character is printed.
            cout << setw(3) << v[r][c];
        }
        //The function moves to the next line for printing after each line concludes.
        cout << endl;
    }
}

//This function displays the values held in the array using unicode characters.
void Maze::print_labyrinth()
{
    //define the characters that will be needed to print out the labyrinth
    string const BLANK = " ";
    string const BLOCK = "\u25a0";
    string const EMPTY_SPACE = "\u25fd";
    string const TRIANGLE = "\u25b3";

    //The variable 'difference' holds the value for the offset between the size of the
    //array variable 'labyrinth' and the vector of vectors variable 'v'. (In this case there
    //is no difference between the size of the two variables.)
    const int difference = (SIZE-v.size())/2;
    for(int diw=0; diw<difference; diw++)
        cout << setw(5) << " ";


    int column_num = 0;
    //Print a space to account for the column of numbers to the left of the array.
    cout << setw(5) << " ";
    //Print the numbers that will reside above the rows displayed in the array.
    for(int c=0; c<(v.size()); c++)
    {
        cout << setw(5) << column_num;
        column_num++;
    }
    cout << endl << endl;

    //Prints the row numbers that will reside to the left of the array denoting
    //the index for each row.
    int row_num = 0;
    for(int r=0; r<SIZE; r++)
    {
        cout << setw(5) << row_num;
        row_num++;

        //This for loop iterates through the contents of each line of the array.
        for(int c=0; c<SIZE; c++)
        {
            //The switch statements displays unicode characters depending on what character
            //it encounters in the array.
            switch(labyrinth[r][c])
            {
            //The character '*' denotes an unnavigable space.
            case '*':
                cout << setw(7) << BLOCK;
                break;
            //The character 'E' denotes the point of entrance.
            case 'E':
                cout << setw(7) << TRIANGLE;
                break;
            //The character '-' denotes a potential path.
            case '-':
                cout << setw(7) << EMPTY_SPACE;
                break;
            //The character '|' denotes an exit point.
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

//This function transfers values from the vector of vectors to the array 'labyrinth'.
void Maze::fill_labyrinth()
{
    //Initialize an int variable 'filling_index' to hold the offset value
    //which accounts for the differences in size between the array and vector
    //of vectors variable 'v', so that the data will be stored in the center of 'v'.
    int filling_index;

    //The for loop iterates through 'v' row by row.
    for( int r=0; r<SIZE; ++r)
        if(r < v.size())
        {
            //The offset (difference in sizes) is calculated and assigned.
            filling_index = (SIZE - v[r].size())/2;

            //The for loop iterates through 'v' column by column and assigns the values
            //to the 'labyrinth' array, but centered.
            for(int c=0; c<v[r].size(); ++c)
                labyrinth[r][c+filling_index] = v[r][c];
        }
}

//This function recursively finds the route through the array 'labryinth'.
//It must be provided the x and y coordinates in the array for the entrance point.
int Maze::solve(int x, int y)
{
    //This int variable 'success' is initialized to zero.
    int success = 0;

        //The switch statement tells the function to keep iterating through the array
        //until the entire path is found and the character '|' is uncovered.
        switch( labyrinth[x][y])
        {
            case '|': success = 1;
                break;
            case '*': success = 0;
                break;
            case 'T': success = 0;
                break;
            //The default case for the switch statement places a 'T' for traversed
            //wherever the function has already examined.
            default: labyrinth[x][y] = 'T';

            //The default case then forces the function to keep attempting to examine
            //the neighboring spots in the array: up, down, side, side.
            if(x==0 && y==0)
                success = this->solve(x+1, y) + this->solve(x, y+1);
                else 
                    if(x==SIZE && y==0)
                        success = this->solve(x, y+1) + this->solve(x-1, y);
                        else 
                            if (x==0 && y==SIZE)
                                success = this->solve(x+1, y) + this->solve(x, y-1);
                                else 
                                    if (x==SIZE && y==SIZE)
                                        success = this->solve(x-1, y) + this->solve(x, y-1);
                                        else 
                                            if (x==0)
                                                success = this->solve(x+1, y) + this->solve(x, y+1) + this->solve(x, y-1);
                                                else 
                                                    if (y==0)
                                                        success = this->solve(x+1, y) + this->solve(x, y+1) + this->solve(x-1, y);
                                                        else
                                                            success = this->solve(x+1, y) + this->solve(x, y+1) + this->solve(x-1, y) + this->solve(x, y-1);
                break;
        }
        //If success is achieved the function will print each x and y coordinate along
        //the route.
        if(success>0)
        {
            coords coord_point;
            coord_point.x = x;
            coord_point.y = y;
            coord_stack.push(coord_point);
        }

    //The function will either loop indefinitely or return success (assuming the maze
    //is navigable.)
    return success;
}

void Maze::print_coordinates()
{
    cout << "The path from entry to exit consists of the following points: " << endl;
    while(!coord_stack.is_empty())
    {
        coords point;
        point = coord_stack.pop();
        cout << "The x and y coordinates are: " << point.x << ", " << point.y << endl;;
    }
}