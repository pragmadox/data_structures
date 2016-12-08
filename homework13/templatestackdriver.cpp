/*  
    Jay Price
    Data Structures
    Homework 13
    Due Date: December 5, 2016
    Date: December 1, 2016
    Description: Demonstrate the driver class from class with a struct of x and y coordinates.
    File: templatestackdriver.cpp
*/
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "templatestack.h"

using namespace std;

unsigned int seed = 7;

double random(unsigned int&seed);

typedef struct
{
   double x, y;
} point;

int main( )
{
<<<<<<< HEAD
    int i;
    char ch;
    point p;
    stack<point> s;

    cout << "is_empty = " << s.is_empty( ) << endl;
    cout << "is_full = " << s.is_full( ) << endl;

    s.initialize_stack(10);

    cout << "is_empty = " << s.is_empty( ) << endl;
    cout << "is_full = " << s.is_full( ) << endl;

    cout << fixed << right << setprecision(3);

    i = 0;

    while(!s.is_full( ))
    {
        cout << setw(3) << ++i << ". ";
        p.x = random(seed);
        p.y = random(seed);
        cout << "p.x = " << setw(5) << p.x;
        cout << " p.y = " << setw(5) << p.y;
        cout << endl;
        s.push(p);
    }

    i = 0;
    while(!s.is_empty( ))
    {
        cout << setw(3) << ++i << ". ";
        p = s.pop( );
        cout << "p.x = " << setw(5) << p.x;
        cout << " p.y = " << setw(5) << p.y;
        cout << endl;
    }
    return(0);
=======
   int i;
   char ch;
   point p;
   stack<point> s;

   cout << "is_empty = " << s.is_empty() << endl;
   cout << "is_full = " << s.is_full() << endl;

   s.initialize_stack(10);

   cout << "is_empty = " << s.is_empty( ) << endl;
   cout << "is_full = " << s.is_full( ) << endl;

   cout << fixed << right << setprecision(3);

   i = 0;

   while(!s.is_full())
   {
      cout << setw(3) << ++i << ". ";
      p.x = random(seed);
      p.y = random(seed);
      cout << "p.x = " << setw(7) << p.x;
      cout << "    p.y = " << setw(7) << p.y;
      cout << endl;
      s.push(p);
   }

   cout << "-------------------------------------------" << endl;
   cout << "Removing elements from the stack: " << endl;

   i = 0;
   while(!s.is_empty())
   {
      cout << setw(3) << ++i << ". ";
      p = s.pop( );
      cout << "p.x = " << setw(7) << p.x;
      cout << "    p.y = " << setw(7) << p.y;
      cout << endl;
   }

   return(0);
>>>>>>> cdfce2dbbdd2f72c5348b3cfd7aee4ba31bc3822
}

double random(unsigned int&seed)
{
   const int MODULUS = 15749;
   const int MULTIPLIER = 69069;
   const int INCREMENT = 1;
   seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;
   return (double) seed / double (MODULUS);
}

