#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include "homework5.h"

using namespace std;    

//declare a two-dimensional array that represents the labyrinth
char labyrinth[SIZE][SIZE] = {{'*'}};

//declare a two-dimensional vector to accept the non-zero values from the data file.
vector < vector<char> > v;

//declare a stack of type array for coordinates to hold the path indices.
coords path[MAXSIZE];
int current_size=-1;

using namespace std;

int Maze::is_empty()
{
    if( current_size == -1)
        return 1;
        else 
            return 0;
}

int Maze::is_full()
{
    if( current_size == MAXSIZE)
        return 1;
        else
            return 0;
}

coords Maze::top()
{
    if(!is_empty())
        return path[current_size];
    else
        printf("Could not retrieve data. path is empty.\n");
}

coords Maze::pop()
{
    coords data;
    if(!is_empty())
    {
        data = path[current_size];
        current_size = current_size - 1;
        return data;
    }
    else
        printf("Could not retrieve data. path is empty.\n");
}

void Maze::push(coords data)
{
    if(!is_full())
    {
        current_size = current_size + 1;
        path[current_size] = data;
    }
    else
        printf("Could not insert data. path is full.\n");
}

void Maze::read_data_file()
{
    
    vector<char> row;
    stringstream ss;
    char element;
    string line;
    string fileName;

    cout << "Enter the name of the data file with its extension: ";
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
        cout << "Unable to open file.";

}

void Maze::print_vector()
{
    for( int r = 0; r < v.size(); r++ )
    {
        for( int c = 0; c < v[r].size(); c++ )
            cout << setw(3) << v[r][c];
        cout << endl;
    }
}

void Maze::print_labyrinth()
{
    string const LEFT_ARROW = "\u2190";
    string const UP_ARROW = "\u2191";
    string const RIGHT_ARROW = "\u2192";
    string const DOWN_ARROW = "\u2193";
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
        if(column_num==10)
        {
            cout << " ";
        }
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
            //The character 'L' denotes a path left.
            case 'L':
                cout << setw(7) << LEFT_ARROW;
                break;
            //The character 'U' denotes a path up.
            case 'U':
                cout << setw(7) << UP_ARROW;
                break;
            //The character 'R' denotes a path right.
            case 'R':
                cout << setw(7) << RIGHT_ARROW;
                break;
            //The character 'D' denotes a path down.
            case 'D':
                cout << setw(7) << DOWN_ARROW;
                break;
             //The character 'T' denotes a traversed path.
            case 'T':
                cout << setw(7) << EMPTY_SPACE;
                break;                
            default:
                cout << setw(7) << BLANK;
            }
        }
        cout << endl << endl;
    }
}

void Maze::fill_labyrinth()
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

int Maze::solve(int x, int y)
{
    int success = 0;

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
                                                            success = this->solve(x+1, y) + this->solve(x, y-1) + this->solve(x, y+1) + this->solve(x-1, y);
                break;
        }
        if(success>0)
        {
            coords solution;
            solution.x = x;
            solution.y = y;
            coords last_point;
            last_point = top();
             
            if(solution.x-last_point.x==1)
                labyrinth[solution.x][solution.y] = 'U';
                else
                    if(solution.x-last_point.x==-1)
                        labyrinth[solution.x][solution.y]= 'D';
                        else
                            if(solution.y-last_point.y==1)
                                labyrinth[solution.x][solution.y]= 'L';
                                else
                                    if(solution.y-last_point.y==-1)
                                        labyrinth[solution.x][solution.y]= 'R';
            
            push(solution);
        }
    //The function will either loop indefinitely or return success (assuming the maze
    //is navigable.)
    return success;
}

void Maze::print_path()
{
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "The path from entry to exit for the maze includes the following points:" << endl << endl; 
    while(!is_empty())
    {
        coords point = top();
        cout << "The x and y coordinates are: " << point.x << ", " << point.y << endl;
        pop();
    }
    
}