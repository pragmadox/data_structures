/*
      Jay Price
      Data Structures Final
      December 12, 2016
      File: list_char.h
*/

#ifndef LIST_CHAR_H
#define LIST_CHAR_H

class list_char
{
    public:
        list_char();
        list_char(const list_char &source);
        ~list_char();
        //member functions
        bool empty();
        bool at_end();
        int length();
        void first();
        void next();
        int data();
        void insert(const char &item);
        bool retrieve(char &item);
        bool snip(char &item);
        void print();
        int find_first(char item);
        int find_last(char item);
        void remove(char item);
        char get_index(int);
        list_char &operator=(const list_char &source);

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
};

#endif
