//Class implementation of dynamic size stack.
//File: stack5.h 

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
