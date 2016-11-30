#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "stack6.h"

using namespace std;

const int SIZE = 20;

class Maze
{
    
    public:
    stack coord_stack;
    void read_data_file();
    void print_vector();
    void print_labyrinth();
    void fill_labyrinth();
    void print_coordinates();
    int solve(int, int);
    int x, y;
    char labyrinth[SIZE][SIZE];

    private:
    vector<vector<char> > v;
    vector<char> row;
    

};