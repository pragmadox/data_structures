//File: stack5.cpp
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
    new_data=(stack_element *)malloc(sizeof(stack_element)*size);
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
    if(is_full)
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

int stack::is_empty()
{
    return stack_top_index < 0;
}

int stack::is_full()
{
    return stack_top_index >= max_size-1;
}