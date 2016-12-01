/*  
    Jay Price
    Data Structures
    Homework 12
    Due Date: December 1, 2016
    Date: November 25, 2016
    Description: 
    - Read a string from input 
    - Push characters from the string on s1
    - Pop characters from s1
    - Output them to the screen
    Use the class-based implementation of the stack defined in class.
    File: stack5.cpp
*/

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include "stack5.h"

using namespace std;

stack::stack()
{
    data = NULL;
    max_size = 0;
    stack_top_index = -1;
}

void stack::initialize_stack(int size)
{
    stack_element *new_data;
    new_data=(stack_element *)malloc(sizeof(stack_element)*max_size);
    if(new_data==NULL)
    {
        cerr << "Insufficient memory." << endl;
        exit(1);
    }
    data = new_data;
    max_size = size;
    stack_top_index = -1;
}

void stack::destroy_stack()
{
    free(data);
    data = NULL;
    max_size = 0;
    stack_top_index = -1;
}

void stack::push(stack_element element)
{
    if(is_full())
    {
        cerr << "Cannot push data. Stack is full." << endl;
        exit(1);
    }
    data[++stack_top_index]=element;
}

stack_element stack::pop()
{
    if(is_empty())
    {
        cerr << "Cannot pop data. Stack is empty." << endl;
        return(1);
    }
    return data[stack_top_index--];
}

stack_element stack::top()
{
    if(is_empty())
    {
        cerr << "Cannot return the top element of the stack. Stack is empty." << endl;
        return(1);
    }
    return data[stack_top_index];
}

bool stack::is_empty()
{
    return stack_top_index < 0;
}

bool stack::is_full()
{
    return stack_top_index >= max_size-1;
}