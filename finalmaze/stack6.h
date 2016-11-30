//Class implementation of dynamic size stack.
//File: stack6.h 

#ifndef STACK_H
#define STACK_H

struct coords
{
    int x;
    int y;
};

class stack
{
    public: 
        stack();
        void initialize_stack(int size);
        void destroy_stack();
        coords pop();
        coords top();
        void push(coords element);
        bool is_empty();
        bool is_full();
    private:
        coords *data;
        int max_size;
        int stack_top_index;
};

#endif
