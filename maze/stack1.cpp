//File: stack1.cpp
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "stack1.h"

stack::stack()
{
    current_size = -1;
}

int stack::stack_size()
{
    return current_size+1;
}

int stack::is_empty()
{
    if(current_size == -1)
        return 1;
    else
        return 0;
}

int stack::is_full()
{
    if(current_size == STACK_MAX)
        return 1;
    else   
        return 0;
}

int stack::top()
{
    return data[current_size];
}

int stack::pop()
{
    int stack_element;
    if(!is_empty())
    {
        stack_element = data[current_size];
        current_size = current_size-1;
        return stack_element;
    }
    else
        printf("Could not retrieve data. Stack is empty.\n");
}

int stack::push(int stack_element)
{
    if(!is_full())
    {
        current_size = current_size+1;
        data[current_size] = stack_element;
    }
    else
        printf("Could not insert data. Stack is full.\n")
}