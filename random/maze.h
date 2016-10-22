//File: maze.h 
//Purpose: Header file with declaration of the maze class, including member functions and private member variables.

#ifndef MAZE.H
#define MAZE.H

class Maze
{
    public:
        void Input(istream &in); //read in the maze
        void Output(ostream; &out); //output the maze

    protected:
        char cells[SIZE][SIZE];
}

#endif //MAZE.H