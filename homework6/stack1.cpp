/* 
    Jay Price
    Data Structures
    Homework 6
    October 20, 2016
*/

//File: stack1.cpp
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "stack1.h"

Stack::Stack()
{
    current_size = -1;
}

int Stack::stack_size()
{
    return current_size+1;
}

int Stack::is_empty()
{
    if(current_size == -1)
        return 1;
    else
        return 0;
}

int Stack::is_full()
{
    if(current_size == STACK_MAX)
        return 1;
    else   
        return 0;
}

int Stack::top()
{
    return data[current_size];
}

int Stack::pop()
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

int Stack::push(int stack_element)
{
    if(!is_full())
    {
        current_size = current_size+1;
        data[current_size] = stack_element;
    }
    else
        printf("Could not insert data. Stack is full.\n");
}