//File labyrinth.cpp - the driver file
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "maze.h"

using namespace std;

int main()
{
    int n;
    string file_name;
    Maze this_maze;

    //read_maze();

    //define_entry(x,y)

    //print_labyrinth();

    //this_maze.solve( x (entrance point), y (entrance point) )

    cout << "Enter the file name containing the labyrinth: ";
    cin << file_name;

    ifstream infile;
    infile.open(filename);
    infile >> this_maze;
    cout << "The maze of the labyrinth looks like this: " << endl;
    cout << this_maze;
    return 0;

}
