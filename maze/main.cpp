#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "maze.h"
#include "stack6.h"


int main()
{

    //Create an object 'maze1' of type Maze;
    Maze maze1;
    maze1.coord_stack.initialize_stack(100);

    //Call each function.
    maze1.read_data_file();
    maze1.print_vector();
    cout << endl;
    maze1.fill_labyrinth();
    maze1.print_labyrinth();

    //Initialize the public coordinate variables for the entry point of the maze.
    int x, y;

    cout << "What are the coordinates for the entry point of your maze?" << endl;
    cout << "Row index: ";
    cin >> x;
    cout << "Column index: ";
    cin >> y;
    cout << endl;

    //Provide the solve function the entrance point.
    maze1.solve(x,y);
    maze1.print_coordinates();

return 0;
}
