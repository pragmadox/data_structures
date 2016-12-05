//File: linklist.h 

//Template version of a link-list 
#ifndef LINK_LIST_H
#define LINK_LIST_H

template<class VARIABLE>

class link_list
{
    public:
        link_list();
        link_list(const link_list<VARIABLE> &source);
        ~link_list();
        bool empty();
        bool at_end();
        int length();
        void first();
        void next();
        VARIABLE data();
        void insert(const VARIABLE &item);
        bool retrieve(VARIABLE &item);
        bool remove(VARIABLE &item);
        link_list<VARIABLE> &operator = (const link_list<VARIABLE> &source);

    private:
        struct node
        {
            VARIABLE data;
            node *next;
        };
        typedef node *node_ptr;
        int list_length;
        node_ptr head, current, previous;
        node_ptr get_node(const VARIABLE &item);
};

#endif