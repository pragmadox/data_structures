//File: stack4.h 
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
int is_empty(stack *stack_pointer);
int is_full(stack *stack_pointer);

#endif