#include <limits.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <ctime>
#include "watch.h"

using namespace std;

vector<int> v;
unsigned int seed = (unsigned int)time(0);

double random(unsigned int&);
void push_vector(vector<int>&);
void insert_vector(vector<int>&);
void read_vector(vector<int>&);
void empty_vector(vector<int>&);

int main()
{  

Watch stop_watch1;
stop_watch1.start();
push_vector(v);
stop_watch1.stop();
cout << "Pushing ten thousand random integers by seeding with time and pushing them back onto the vector required: ";
cout << stop_watch1.seconds() << " seconds." << endl << endl;

empty_vector(v);
int size_of_v = v.size();
cout << "The size of the vector is: " << size_of_v << endl << endl;

Watch stop_watch2;
stop_watch2.start();
insert_vector(v);
stop_watch2.stop();
cout << "Pushing ten thosuand random integers by seeding with time and inserting them at the beginning of the vector required: ";
cout << stop_watch2.seconds() << " seconds." << endl << endl;

empty_vector(v);
size_of_v = v.size();
cout << "The size of the vector is: " << size_of_v << endl << endl;

Watch stop_watch3;
stop_watch3.start();
read_vector(v);
stop_watch3.stop();
cout << "Reading ten thousand random integers from a file and pushing them onto the vector required: ";
cout << stop_watch3.seconds() << " seconds." << endl;


return 0;
}

double random(unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = ((MULTIPLIER*seed) + INCREMENT) % MODULUS;
    return double(seed)/double(MODULUS);
}

void push_vector(vector<int> &v)
{
    int new_integer;
    for(int i=0; i<10000; ++i)
    {
        new_integer = int(1+10*random(seed));
        v.push_back(new_integer);
    }
}

void insert_vector(vector<int> &v)
{
    int new_integer;
    for(int i=0; i<10000; ++i)
    {
        new_integer = int(1+10*random(seed));
        v.insert(v.begin(), new_integer, new_integer+1);
    }
}

void read_vector(vector<int> &v)
{
    stringstream ss;
    int element;
    string line;
  
    fstream myfile("random.txt");
    if(myfile.is_open())
    {
        while(getline(myfile,line))
        {

            ss.clear();
            ss.str ("");
            ss << line;

            while(ss >> element)
            {
                v.push_back(element);
            }
        }
        myfile.close();
    }

    else
    {
        cout << "Unable to open file.";
    }

}

void empty_vector(vector<int> &v)
{
    while(v.size()>0)
        v.pop_back();
}