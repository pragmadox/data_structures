/* 
    Jay Price
    Data valuess
    Homework 8
    October 30, 2016
*/

#include <limits.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct values
{
    int m;
    double x;
};

unsigned int seed = (unsigned int)time(0);
const int SIZE=10;
double random(unsigned int&);
void copy_array_to_vector(int[], double[], vector<values>&);
void print_vector(vector<values>);
bool cmpint(const values&, const values&);
bool cmpdouble(const values&, const values&);

int main()
{
    vector<values> v, w;
    vector<values>::iterator beginning, ending;
    
    intarr[SIZE];
    for(int i=0; i<SIZE, i++)
    {
        local_data = int(10*random(seed));
        intarr[i] = local_data;
    }

    doublearr[SIZE];
    for(int i=0; i<SIZE, i++)
    {
        local_data = double(10*random(seed));
        doublearr[i] = local_data;
    }

    copy_array_to_vector(intarr, doublearr, v);
    w = v;

    cout << "Here is the unsorted vector: " << endl;
    print_vector(v);
    cout << endl;

    beginning = v.begin();
    ending = v.end();
    sort(beginning, ending, cmpint);
    cout << "Vector sorted ascending by integers: " << endl;
    print_vector(v);
    cout << endl;

    beginning = w.begin();
    ending = w.end();
    sort(beginning, ending, cmpdouble);
    cout << "Vector sorted descending by doubles: " << endl;
    print_vector(w);
    return 0;
}

double random( unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = ((MULTIPLIER*seed) + INCREMENT) % MODULUS;
    return double(seed)/double(MODULUS);
}

void copy_array_to_vector(int intarr[], double doublearr[], vector<values> &v)
{
    for(int i=0; i<SIZE; i++)
    {
        values node;
        node.m = intarr[i];
        node.x = doublearr[i];
        v.push_back(node);
    }
}

void print_vector(vector<values> v)
{
    cout << "m: ";
    for(int i=0; i<v.size(); i++)
    {
        int data = v[i].m;
        cout << setw(7) << data;
    }
    cout << endl;
    cout << "x: ";
    for(int i=0; i<v.size(); i++)
    {
        double data = v[i].x;
        cout << setw(7) << data;
    }
    cout << endl;
}

bool cmpint(const values& lhs, const values& rhs)
{
    return lhs.m < rhs.m;
}

bool cmpdouble(const values& lhs, const values& rhs)
{
    return lhs.x > rhs.x;
}
