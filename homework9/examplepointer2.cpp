/*
    Design a function 'get_structure' and 'print_structure' that will assign value to fields f1 and f2 
    of the structure presented in the class.
    Due Date: November 14, 2016

    Example:
    s1 = new structure;
    structure_pointer get_structure(int n, char ch);
    void print_structure(structure_pointer p);
    s1 = get_structure(3, '*')

*/

#include <iostream>
#include <iomanip>
#include <assert.h>
#include <stddef.h>
using namespace std;

struct structure;
typedef structure *structure_pointer;

struct structure
{
    int f1;
    char f2;
    structure_pointer f3, f4;
};

int main()
{
    structure_pointer s1, s2;
    s1 = new structure;
    s2 = new structure;
    if(s1!=NULL)
    {
        s1->f1=4;
        s1->f2='a';
        s1->f3=s2;
        s1->f4=NULL;
    }
    else 
        cout << "Error: No dynamic memory available.";

    assert(s2!=NULL);
    s2->f1=9;
    s2->f2='i';
    s2->f3=NULL;
    s2->f4=NULL;
    cout << "Enter integer: ";
    cin >> (*s1).f1;
    cout << "s1->f1 = " << s1->f1 << endl;
    cout << "s1->f2 = " << s1->f2 << endl;
    cout << "s1->f3 = " << s1->f3 << endl;
    cout << "s1->f4 = " << s1->f4 << endl;
    s2 = new structure;
    cout << "s1->f3->f1 = " << s1->f3->f1 << endl;
}