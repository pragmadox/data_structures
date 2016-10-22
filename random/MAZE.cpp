

istream &operator >> (istream &in; MAZE &m);
ostream &operator >> (ostream &out; MAZE &m);

//File: maze.cpp
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "maze.h"

void MAZE::Input(istream &in)
{
    int row, col;
    for(row=0; row<SIZE; ++row )
        for(col=0; col<SIZE; ++col)
            in >> cells[row][col];
}

void MAZE::Output()
{
    //#define large_square ""
    int row, col;
    //print column numbers
    //print row numbers followed by the row of the labyrinth

}

istream &operator >> (istream &in, MAZE &m)
{
    m.Input(in);
    return(in);
}

ostream &operator << (ostream &out, MAZE m)
{
    m.Output(out);
    return(out);
}

