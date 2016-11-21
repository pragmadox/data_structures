/*
    Jay Price
    Data Structures
    Quiz 3
    Date: November 21, 2016
*/

#include <limits.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <stddef.h>

using namespace std;

unsigned int seed = (unsigned int)time(0);
struct structure;
typedef structure *structure_pointer;
double random(unsigned int&);
structure_pointer get_structure();
void print_structure(structure_pointer);
void build_structure(structure_pointer, structure_pointer);

struct structure
{
    int int_data;
    structure_pointer next;
};

int main()
{
    structure_pointer head;
    head = get_structure();
    cout << "The value of head is: ";
    cout << head->int_data << endl;
    structure_pointer p;
    for(int i=0; i<10; i++)
    {
        p = head;
        structure_pointer new_value;
        new_value = get_structure();
        cout << "The new value is: " << new_value->int_data << endl;
        build_structure(new_value,p);
    }

    cout << "The values in reverse are: ";
    p = head;
    print_structure(p);
    cout << endl;

}

double random( unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = ((MULTIPLIER*seed) + INCREMENT) % MODULUS;
    return double(seed)/double(MODULUS);
}


structure_pointer get_structure()
{
    int local_data = int(20*random(seed));
    structure_pointer s;
    s = new structure;
    assert(s!=NULL);
    s->int_data=local_data;
    s->next=NULL;
    return s;       
}

void build_structure(structure_pointer new_value, structure_pointer p)
{
    if(p->next==NULL)
        p->next=new_value;
        else
        {
            p=p->next; 
            build_structure(new_value,p);
        }
}

void print_structure(structure_pointer p)
{ 
    structure_pointer place_holder;
    place_holder = p; 
    if(p->next!=NULL)
        print_structure(p->next);
    cout << setw(4) << place_holder->int_data;
}