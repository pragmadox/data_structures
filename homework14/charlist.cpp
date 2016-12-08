/*
 * Jay Price
 * December 7, 2016
 * Data Structures
 *
 */

#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "charlist.h"

using namespace std;

charlist::charlist()
{
      head = NULL;
      current = NULL;
      previous = NULL;
      list_length = 0;
}

charlist::charlist(const charlist &list)
{
      node_ptr probe = list.head;
      while (probe != NULL)
      {
            insert(probe->data);
            next();
            probe = probe->next;
      }
}

charlist::~charlist()
{
      node_ptr garbage;
      node_ptr probe = head;
      while (probe != NULL)
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

charlist &charlist::operator=(const charlist &list)
{
      node_ptr probe = list.head;
      while (probe != NULL)
      {
            insert(probe->data);
            next();
            probe = probe->next;
      }
      return *this;
}

bool charlist::empty()
{
      return (list_length == 0);
}

int charlist::length()
{
      return (list_length);
}

bool charlist::at_end()
{
      if (current == NULL)
            return (true);
      else
      {
            if (current != NULL && (current->next) == NULL)
                  return (true);
            else
                  return (false);
      }
}

void charlist::next()
{
      if (current != NULL)
      {
            previous = current;
            current = current->next;
      }
}

void charlist::first()
{
      current = head;
      previous = NULL;
}

void charlist::insert(const char &item)
{
      node_ptr new_node = get_node(item);
      new_node->next = current;
      if (current == head)
            head = new_node;
      else
            previous->next = new_node;
      current = new_node;
      ++list_length;
}

bool charlist::remove(char &item)
{
      node_ptr old_node = current;
      bool success = true;
      if (current == NULL)
            success = false;
      else
      {
            item = current->data;
            if (current == head)
                  head = current->next;
            else
                  previous->next = current->next;
            current = current->next;
            delete old_node;
            --list_length;
      }
      return (success);
}

bool charlist::retrieve(char &item)
{
      bool success = true;
      if (current == NULL)
            success = false;
      else
            item = current->data;
      return (success);
}

charlist::node_ptr charlist::get_node(const char &item)
{
      node_ptr temp = new node;
      assert(temp != NULL);
      temp->data = item;
      temp->next = NULL;
      return (temp);
}

void charlist::print()
{
      char item;
      bool success;
      cout << "Contents of list: ";
      if (!empty())
      {
            first();
            while (!at_end())
            {
                  success = retrieve(item);
                  cout << item << ' ';
                  next();
            }
            success = retrieve(item);
            cout << item << endl;
      }
      first();
}

int charlist::find_last(char search)
{
      bool in_list = false;
      char element;
      bool success;
      int index = -1;
      first();
      for (int i = 0; i < list_length; i++)
      {
            success = retrieve(element);
            if (element == search)
            {
                  in_list = true;
                  in_list = false;
                  index = i;
                  next();
            }
            else
                  next();
      }

      if (index >= 0)
            cout << "The character '" << search << "' was found in the list." << endl;
      else
      {
            cout << search << " was not found in the list." << endl;
            exit(1);
      }
      first();
      return (index);
}

int charlist::find_first(char search)
{
      bool in_list = false;
      char element;
      bool success;
      int index = 0;
      first();

      while (!at_end())
      {
            success = retrieve(element);
            if (element == search)
            {
                  in_list = true;
                  break;
            }
            else
            {
                  index++;
                  next();
            }
      }
      retrieve(element);
      if (element == search)
            in_list = true;

      if (in_list == true)
            cout << "The character '" << search << "' was found in the list." << endl;
      else
      {
            cout << search << " was not found in the list." << endl;
            exit(1);
      }
      first();
      return (index);
}

char charlist::get_index(int index)
{
      char element;
      first();
      int i = 0;
      while (i < list_length)
      {
            if (i != index)
            {
                  next();
                  i++;
            }
            else if (i == index)
            {
                  retrieve(element);
                  return (element);
                  exit(0);
            }
      }
      cout << "Cannot retrieve item. Index unavailable." << endl;
      exit(1);
}

void charlist::remove_matching(char search)
{
      bool in_list = false;
      char element;
      int count = 0;
      first();

      while (!at_end())
      {
            retrieve(element);
            if (element == search)
            {
                  in_list = true;
                  remove(element);
                  count++;
            }
            else
                  next();
      }
      retrieve(element);
      if (element == search)
      {
            in_list = true;
            remove(element);
            count++;
      }

      if (in_list == true)
            cout << "The character '" << search << "' was found in the list and removed " << count << " times." << endl;
      else
      {
            cout << "The character '" << search << "' was not found in the list." << endl;
            exit(1);
      }
      first();
}