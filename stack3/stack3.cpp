/* 
    Jay Price
    Data Structures
    November 2, 2016
    Stack version 3
    Description: Stack implementation using arrays with dynamically allocated size.
    File: stack3.cpp
*/

#include <stdio.h>
#include <stdlib.h> //for dynamic allocation
#include <assert.h>
#include "stack3.h"


void Stack::initialize_stack(stack *stack_pointer, int max_size)
{
    stack_element *new_data;
    new_data = (stack_element *)malloc(sizeof(stack_element)*max_size);
    assert(new_data!=NULL);
    stack_pointer -> data=new_data;
    stack_pointer -> max_size=max_size;
    stack_pointer -> stack_top_index=-1;
}

void Stack::destroy_stack(stack *stack_pointer)
{
    //get rid of array
    free(stack_pointer -> data);
    stack_pointer -> data=NULL;
    stack_pointer -> max_size=0;
    stack_pointer -> stack_top_index=-1;
}