#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "homework5.h"

int main()
{

//Create an object 'maze1' of type Maze;
Maze maze1;

//Call each function.
maze1.read_data_file();
maze1.print_vector();
cout << endl;
maze1.fill_labyrinth();
maze1.print_labyrinth();

//Initialize the public coordinate variables for the entry point of the maze.
coords entrypoint;

cout << "What are the coordinates for the entry point of your maze?" << endl;
cout << "Row index: ";
cin >> entrypoint.x;
cout << "Column index: ";
cin >> entrypoint.y;
maze1.push(entrypoint);
cout << endl;

//Provide the solve function the entrance point.
maze1.solve(entrypoint.x, entrypoint.y);
maze1.print_labyrinth();
maze1.print_path();

return 0;
}