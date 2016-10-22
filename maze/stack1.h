#include <iostream>
#incldue <iomanip>
#include <stdio.h>
#include <vector>
#define STACK_MAX 25;

class Stack
{
    public:
        stack(); //constructor
        ~stack() {} //destructor
        int stack_size();
        int is_empty();
        int is_full();
        int top();
        int pop();
        int push(int stack_element);
    private:
        int data[STACK_MAX];
        int current_size;
};

