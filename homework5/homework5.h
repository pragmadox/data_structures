/*  Jay Price
    Homework 5
    Data Structures
    October 21, 2016
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 20;
const int MAXSIZE = 100;
struct coords
{
    int x;
    int y;
};

class Maze
{
    
    public:
        int is_empty();
        int is_full();
        coords top();
        coords pop();
        void push(coords);
        void print_path();
        void read_data_file();
        void print_vector();
        void print_labyrinth();
        void print_solved_labyrinth();
        void fill_labyrinth();
        int solve(int, int);
        int x, y;
        char labyrinth[SIZE][SIZE];

    private:
        vector<vector<char> > v;
        vector<char> row;

};