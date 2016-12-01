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
    File: stack5.h
*/

#ifndef STACK_H
#define STACK_H

typedef char stack_element;

class stack
{
    public: 
        stack();
        void initialize_stack(int size);
        void destroy_stack();
        stack_element pop();
        stack_element top();
        void push(stack_element element);
        bool is_empty();
        bool is_full();
    private:
        stack_element *data;
        int max_size;
        int stack_top_index;
};

#endif
