//File: stack4.cpp
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include "stack4.h"

using namespace std;

void initialize_stack(stack *stack_pointer, int max_size)
{
    stack_element *new_data;
    new_data = (stack_element*)malloc(sizeof(stack_element)*max_size);
    if(new_data==NULL)
    {
        cerr << "Insufficient memory to initialize stack." << endl;
        exit(1);
    }
    stack_pointer->data=new_data;
    stack_pointer->max_size=max_size;
    stack_pointer->stack_top_index=-1;
}

void destroy_stack(stack *stack_pointer)
{
    free(stack_pointer->data);
    stack_pointer->data=NULL;
    stack_pointer->max_size=0;
    stack_pointer->stack_top_index=-1;
}

void push(stack *stack_pointer, stack_element element)
{
    if(is_full(stack_pointer))
    {
        cerr << "Cannot push on stack. Stack is full." << endl;
        exit(1);
    }
    stack_pointer->data[++stack_pointer->stack_top_index]=element;
}

stack_element pop(stack *stack_pointer)
{
    if(is_empty(stack_pointer))
    {
        cerr << "Cannot pop from stack. Stack is empty." << endl;
        exit(1);
    }
    return stack_pointer->data[stack_pointer->stack_top_index--];
}

int is_empty(stack *stack_pointer)
{
    return stack_pointer->stack_top_index;
}

int is_full(stack *stack_pointer)
{
    return stack_pointer->stack_top_index>=stack_pointer->max_size-1;
}
