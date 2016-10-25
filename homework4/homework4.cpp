/*
    Jay Price
    Data Structures
    Homework 4
    October 19, 2016
*/

#include<limits.h>
#include<iostream>
#include<vector>
#include<iomanip>
#include<stdio.h>
#include<time.h>

using namespace std;

struct vector_node
{
    int sum;
    vector<int> row_vector;
};

vector<vector_node> v;
unsigned int seed = (unsigned int)time(0);
int minimum_sum;

double random(unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = ((MULTIPLIER*seed) + INCREMENT) % MODULUS;
    return double(seed)/double(MODULUS);
}

void fill_vector(vector<vector_node> &v, int &minimum_sum)
{
    int new_integer, node_vector_size;
    minimum_sum = INT_MAX;
    for(int row=0; row<v.size(); ++row)
    {
        node_vector_size= int(1+10*random(seed));
        v[row].sum=0;
        for(int column=0; column<node_vector_size; ++column)
        {
            new_integer = int(11*random(seed));
            v[row].row_vector.push_back(new_integer);
            v[row].sum+=new_integer;
        }
        if(v[row].sum < minimum_sum)
            minimum_sum = v[row].sum;
    }
}

void print_vector( vector<vector_node> v)
{
    for(int row=0; row<v.size(); ++row)
    {
        cout << "Sum = " << setw(4) << v[row].sum << ": ";
        for(int column=0; column < v[row].row_vector.size(); ++column)
            cout << setw(4) << v[row].row_vector[column];
        cout << endl;
    }
    cout << "-------------------------------------" << endl;
}

void trim_vector( vector<vector_node> &v, int minimum_sum)
{
    int iterate = v.size();
    int offset = 0;
    for(int row=0; row<iterate; ++row)
    {
        if(v[offset].sum != minimum_sum)
           v.erase(v.begin()+offset);         
        else
            offset++;
    }
}

int main()
{
    int minimum_sum;
    int vector_size=int(5+21*random(seed));
    vector<vector_node> v(vector_size);
    fill_vector(v, minimum_sum);
    print_vector(v);
    trim_vector(v, minimum_sum);
    print_vector(v);
}