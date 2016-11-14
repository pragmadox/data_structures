/*
    Jay Price
    Data Structures
    Homework 9
    Date: November 10, 2016
    Due Date: November 14, 2016
    Description: Design a function 'get_structure' and 'print_structure' that will 
    assign value to fields f1 and f2 of the structure presented in the class.
*/

#include <iostream>
#include <iomanip>
#include <assert.h>
#include <stddef.h>
using namespace std;

struct structure;
typedef structure *structure_pointer;
structure_pointer get_structure(int, char);
void print_structure(structure_pointer);

struct structure
{
    int f1;
    char f2;
    structure_pointer f3, f4;
};

int main()
{
    structure_pointer s1, s2, s3;
    s1 = get_structure(3, '*');
    s2 = get_structure(6, '$');
    s3 = get_structure(9, '@');
    print_structure(s1);
    print_structure(s2);
    print_structure(s3);
    return 0;
}

structure_pointer get_structure(int n, char ch)
{
    structure_pointer s;
    s = new structure;
    assert(s!=NULL);
    s->f1=n;
    s->f2=ch;
    s->f3=NULL;
    s->f4=NULL;

    return s;       
}

void print_structure(structure_pointer s)
{
    assert(s!=NULL);
    cout << "----------------------" << endl;
    cout << "f1: " << s->f1 << endl;
    cout << "f2: " << s->f2 << endl;
    cout << "f3: " << s->f3 << endl;
    cout << "f4: " << s->f4 << endl;       
}