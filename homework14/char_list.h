//File: char_list.h 

#ifndef CHAR_LIST_H

class char_list
{
    publc:
        char_list();
        char_list(const char_list $source);
        ~char_list();
        //Member functions:
        bool empty();
        bool at_end();
        int length();
        void first();
        void next();
        int data();
        void insert(const char &item);
        bool retrieve(char &item);
        bool remove(char &item);
        char_list &operator = (const char_list &source);
    
    private:
        struct node
        {
            char data;
            node *next;
        };
        typedef node *node_ptr;
        int list_length;
        node_ptr head, current, previous;
        node_ptr get_node(const char &item);
}
#define CHAR_LIST_H
#endif
        

}