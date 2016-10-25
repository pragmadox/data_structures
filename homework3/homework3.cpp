/* 
    Jay Price
    Data Structures
    Homework 3
    October 13, 2016
*/

#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

const int MAXSIZE = 8;
int stack[MAXSIZE];
int current_size = -1;
unsigned int seed = 17;

int is_empty()
{
    if(current_size == -1)
        return 1;
        else 
            return 0;
}

int is_full()
{
    if(current_size == MAXSIZE)
        return 1;
        else
            return 0;
}

int top()
{
    if(!is_empty())
        return stack[current_size];
    else
        printf("Could not retrieve data. Stack is empty.\n");
}

int pop()
{
    int data;
    if(!is_empty())
    {
        data = stack[current_size];
        current_size = current_size - 1;
        return data;
    }
    else
        printf("Could not retrieve data. Stack is empty.\n");
}

int push(int data)
{
    if(!is_full())
    {
        current_size = current_size + 1;
        stack[current_size] = data;
    }
    else
        printf("Could not insert data. Stack is full.\n");
}

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

    int local_data;
    //example for testing push function and 'is_full' function
    for( int i=1; i<20; i++)
    {
        local_data = int(10*random(seed));
        push(local_data);
    }

    //for testing top function when not empty
    int last_element = top();
    cout << last_element << endl;

    //for testing pop function and 'is_empty' function
    for( int i=1; i<20; i++)
        pop();

    //for testing top function when empty
    last_element = top();
    cout << last_element;

}

//There were some runtime errors from the code in class that I corrected.
//You already explained in class the limitations of this stack implementation.
//It limits the user to only one stack structure. A class is needed.