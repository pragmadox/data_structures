/* 
    Jay Price
    Data Structures
    Quiz 2
    November 3, 2016
*/

//File stack1driver.cpp
#include <iostream>
#include <iomanip>
#include "stack1.h"
#include <time.h>

using namespace std;

unsigned int seed = (unsigned int)time(0);

double random(unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = ((MULTIPLIER*seed) + INCREMENT) % MODULUS;
    return double(seed)/double(MODULUS);
}

int main()
{
    Stack first_stack;
    Stack second_stack;
    Stack third_stack;
    int local_data;
    cout << "First stack: " << endl;

    for(int i=0; i<10; ++i)
    {
        local_data = int(10*random(seed));
        cout << setw(5) << local_data;
        first_stack.push(local_data);
    }
    cout << endl;

    while(!first_stack.is_empty())
    {
        local_data = first_stack.pop();
        second_stack.push(local_data);
    }
    cout << endl; 

   while(!second_stack.is_empty())
    {
        local_data = second_stack.pop();
        third_stack.push(local_data);
    } 

    while(!first_stack.is_empty())
        first_stack.pop();
    
    cout << "First stack reversed: " << endl;
    for(int i=0; i<10; ++i)
    {
        local_data = third_stack.pop();
        cout << setw(5) << local_data;
        first_stack.push(local_data);
    }
    cout << endl;

    return 0;
}