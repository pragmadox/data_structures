/* 
    Jay Price
    Quiz 2
    November 3, 2016
*/

//File: stack1.h
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <time.h>

const int STACK_MAX=25;

class Stack
{
    public:
        Stack(); //constructor
        ~Stack() {} //destructor
        int stack_size();
        int is_empty();
        int is_full();
        int top();
        int pop();
        int push( int stack_element);
    private:
        int data[STACK_MAX];
        int current_size;
};

