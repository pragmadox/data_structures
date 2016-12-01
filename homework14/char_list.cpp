//File: char_list.cpp
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include "char_list.h"

using namespace std;

char_list::char_list()
{
    head = NULL;
    current = NULL;
    previous = NULL;
    list_length = 0;
}

char_list::char_list(const char_list &list)
{
    node_ptr probe=list.head;
    while(probe!=NULL)
    {
        insert(probe->data);
        next();
        probe = probe->next;
    }
}

char_list::~char_list()
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

char_list &char_list::operator = (const char_list list)
{
    node_ptr probe = list.head;
    while(probe!=NULL)
    {
        insert(probe->data);
        next();
        probe = probe->next;
    }
    return *this;
}

bool char_list::empty()
{
    return list_length == 0;
}

int char_list::length()
{
    return list_length;
}

bool char_list::at_end()
{
    if(current==NULL)
        return TRUE;
        else
            if(current!=NULL&&(current->next)==NULL)
                return TRUE;
                else 
                    return FALSE;
}