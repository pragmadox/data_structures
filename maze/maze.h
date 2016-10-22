#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 10;

class Maze
{
    
    public:
    void read_data_file();
    void print_vector();
    void print_labyrinth();
    void fill_labyrinth();
    int solve(int, int);
    int x, y;
    char labyrinth[SIZE][SIZE];

    private:
    vector<vector<char> > v;
    vector<char> row;
    

};