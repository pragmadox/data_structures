#include <assert.h>
#include <stdlib.h>
#include "link_list.h"

template<class VARIABLE>
link_list<VARIABLE>::link_list()
{
    head = NULL;
    current = NULL;
    previous = NULL;
    list_length = 0;
}

template<class VARIABLE>
link_list<VARIABLE>::~link_list()
{
    node_ptr garbage;
    node_ptr probe = head;
    while(probe!=NULL)
    {
        garbage = probe;
        probe = probe->next;
        delete garbage;
    }
    list_length = 0;
    head = NULL;
    current = NULL;
    previous = NULL;
}

