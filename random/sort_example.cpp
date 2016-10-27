#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE=6;
double random( unsigned int &seed);
void print_array(int a[]);
void copy_array_to_vector(int a, vector<int> &v);
void print_vector(vector<int> v);
bool cmp(const int &m, const int &n);

int main()
{
    vector<int>::iterator beginning, ending;
    vector<int> v, w;
    int arr[SIZE] = {1, 11, 3, 3, 2, 6, 9, 7};
    copy_array_to_vector(array, v);
    w = v;
    print_vector(v);
    beginning = v.begin();
    ending = v.end();
    sort(beginning, ending);
    print_vector(v);
    print_vector(w);
    beginning = w.begin();
    ending = w.end();
    sort(beginning, ending, cmp);
    print_vector(w);
    return 0;
}

bool cmp(const int &m, const int &n)
{
    return m>n;
}