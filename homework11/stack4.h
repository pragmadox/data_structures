/*  
    Jay Price
    Data Structures
    Homework 11
    Due Date: November 21, 2014
    Date: November 21, 2014
    Description: Add a 'top' function for the stack that returns the top element without removing it.
    File: stack4.h
*/

#ifndef STACK_H
#define STACK_H

typedef char stack_element;
typedef struct 
{
    stack_element *data;
    int max_size;
    int stack_top_index;
} stack;

void initialize_stack(stack *stack_pointer, int max_size);
void destroy_stack(stack *stack_pointer);
void push(stack *stack_pointer, stack_element element);
stack_element pop(stack *stack_pointer);
int isempty(stack *stack_pointer);
int is_full(stack *stack_pointer);
stack_element top(stack *stack_pointer);

#endif