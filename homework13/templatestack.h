/*  
    Jay Price
    Data Structures
    Homework 13
    Due Date: December 5, 2016
    Date: December 1, 2016
    Description: Test the template class using an integer and char stack.
    File: templatestack.h
*/
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template <class variable>
class stack
{
   public:
      stack( )
      {
         variable *data = NULL;
         max_size = 0;
         stack_top_index = -1;
      }

      ~stack( ) {}

      void initialize_stack(int size)
      {
         variable *new_data;
         new_data = (variable*)malloc(sizeof(variable)*size);
         if (new_data == NULL)
         {
            cerr << "Insufficient memory to initialize stack." << endl;
            exit(1);
         }
         data = new_data;
         max_size = size;
         stack_top_index = -1;
      }
      void destroy_stack( )
      {
         free(data);
         data = NULL;
         max_size = 0;
         stack_top_index = -1;
      }

      void push(variable element)
      {
         if(is_full())
         {
            cerr << "Can't push on stack (it is full)." << endl;
            exit(1);
         }
         data[++stack_top_index] = element;
      }

      variable pop()
      {
         if (is_empty())
         {
            cerr << "Can't pop from stack (it is empty)." << endl;
            exit(1);
         }
         return(data[stack_top_index--]);
      }

      bool is_empty()
      {
         return(stack_top_index < 0);
      }

      bool is_full()
      {
         return(stack_top_index >= max_size - 1);
      }

   private:
      variable *data;
      int max_size;
      int stack_top_index;
};

#endif