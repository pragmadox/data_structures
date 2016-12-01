//Class implementation of dynamic size stack.
//File: stack6.h 

#ifndef STACK_H
#define STACK_H

template <class variable>

class stack
{
    public: 
        stack();
        void initialize_stack(int size);
        void destroy_stack();
        variable pop();
        variable top();
        void push(variable element);
        bool is_empty();
        bool is_full();
    private:
        variable *data;
        int max_size;
        int stack_top_index;
};

#endif
