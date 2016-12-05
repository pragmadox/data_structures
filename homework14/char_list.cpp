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

void char_list::next()
{
    if(current!=NULL)
    {
        previous = current;
        current = current->next;
    }
}

void char_list::first()
{
    current = head;
    previous = NULL;
}

void char_list::insert(const char &item)
{
    node_ptr new_node=get_node(item);
    new_node->next = current;
    if(current==head)
        head = new_node;
        else
            previous->next = new_node;
    current = new_node;
    ++list_length; 
}

bool char_list::remove(char &item)
{
    node_ptr old_node = current;
    bool success = TRUE;
    if(current=NULL)
        success = FALSE;
        else
        {
            item = current->data;
            if(current==head)
                head = current->next;
                else
                    previous->next = current->next;
            current = current->next;
            delete old_node;
            --list_length;
        }
    return sucess;
}

bool char_list::retrieve(char &item)
{
    bool success=TRUE;
    if(current==NULL)
        success=FALSE;
        else
            item=current->data;
    return sucess;
}

char_list::node_ptr char_list::get_node(const char &item)
{
    node_ptr temp = new_node;
    assert(temp!=NULL)
    temp->data = item;
    temp->next = NULL;
    return temp;
}

