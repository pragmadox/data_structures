#include <iostream>
#include <iomanip>
#include <assert.h>
#include <stdlib.h>
using namespace std;

typedef char *character_pointer;

character_pointer p1;
character_pointer p2;

int main()
{
    p1 = new char;
    if(p1!=NULL)
    {
        cout << "Enter character that will be pointed to by p1: ";
        cin >> *p1;
    }
    else 
        cout << "Error: No dynamic memory available.";
    
    p2 = new char;
    assert(p2!=NULL);
    *p2 = 'p';
    cout << "*p1= " << *p1 << "  *p2 = " << *p2 << endl;
    *p2 = *p1;
    *p1 = 'm';
    p2 = p1;
    cout << "*p1= " << *p1 << "  *p2 = " << *p2 << endl; 

}