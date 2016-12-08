/*  
    Jay Price
    Data Structures
    Homework 13
    Due Date: December 5, 2016
    Date: December 1, 2016
    Description: Test the template class using an integer and char stack.
    File: templatestackdriver2.cpp
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

int main( )
{
    stack<int> intstack;

    cout << "is_empty = " << intstack.is_empty() << endl;
    cout << "is_full = " << intstack.is_full() << endl;

    intstack.initialize_stack(10);

    cout << "is_empty = " << intstack.is_empty( ) << endl;
    cout << "is_full = " << intstack.is_full( ) << endl;

    cout << fixed << right << setprecision(3);

    int i = 0;

    while(!intstack.is_full())
    {
        cout << setw(3) << ++i << ". ";
        int number = random(seed)*10;
        cout << "New random integer = " << setw(7) << number;
        cout << endl;
        intstack.push(number);
    }

    cout << "-------------------------------------------" << endl;
    cout << "Removing elements from the stack: " << endl;

    i = 0;
    while(!intstack.is_empty())
    {
        cout << setw(3) << ++i << ". ";
        int element = intstack.pop();
        cout << setw(7) << element;
        cout << endl;
    }
    
    cout << endl << "Creating a character stack and testing functions: " << endl; 
    stack<char> charstack;

    cout << "is_empty = " << charstack.is_empty() << endl;
    cout << "is_full = " << charstack.is_full() << endl;

    charstack.initialize_stack(10);

    cout << "is_empty = " << charstack.is_empty( ) << endl;
    cout << "is_full = " << charstack.is_full( ) << endl;

    cout << fixed << right << setprecision(3);

        i = 0;

    while(!charstack.is_full())
    {
        cout << setw(3) << ++i << ". ";
        int character = random(seed)*26;
        char new_character = character + 'a';
        cout << "New random integer = " << setw(7) << new_character;
        cout << endl;
        charstack.push(new_character);
    }

    cout << "-------------------------------------------" << endl;
    cout << "Removing elements from the stack: " << endl;

    i = 0;
    while(!charstack.is_empty())
    {
        cout << setw(3) << ++i << ". ";
        char element = charstack.pop();
        cout << setw(7) << element;
        cout << endl;
    }
    return(0);
}

double random(unsigned int&seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;
    return (double) seed / double (MODULUS);
}