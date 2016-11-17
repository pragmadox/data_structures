/*
    Jay Price
    Data Structures
    Homework 10
    Date: November 10, 2016
    Due Date: November 14, 2016
    Description: Create a recursive pointer-based function
    that populates a tree with random integer values, sorting 
    at each branch - less than or equal left - greater than right.
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
void print_structure(structure_pointer, int);
void build_structure(structure_pointer, structure_pointer);

struct structure
{
    structure_pointer left;
    int int_data;
    structure_pointer right;
};

int main()
{
    structure_pointer head;
    head = get_structure();
    cout << "The value of head is: ";
    cout << head->int_data << endl;

    int width = 64;
    structure_pointer p;
    for(int i=0; i<10; i++)
    {
        p = head;
        structure_pointer new_value;
        new_value = get_structure();
        cout << "The new value is: " << new_value->int_data << endl;
        build_structure(new_value,p);
    }

    print_structure(p, width);

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
    s->left=NULL;
    s->int_data=local_data;
    s->right=NULL;
    return s;       
}

void build_structure(structure_pointer new_value, structure_pointer p)
{
    if(new_value->int_data>=p->int_data)
    {
        if(p->left==NULL)
            p->left=new_value;
            else
            {
                p=p->left;
                build_structure(new_value,p);
            }
    }
        else
        {
            if(p->right==NULL)
                p->right=new_value;
                else
                {
                    p=p->right;
                    build_structure(new_value,p);
                }

        }   
}

void print_structure(structure_pointer p, int width)
{
    cout << setw(width) << right << p->int_data;
    width = width/2;
    structure_pointer place_holder;
    place_holder = p;
    if(p->left!=NULL)
    {
        p=p->left;
        print_structure(p,width);
        p=place_holder;
    }
    else
        cout << setw(width) << right << "";
    if(p->right!=NULL)
    {
        p=p->right;
        print_structure(p,width);
        p=place_holder;
    }
    else
    {
        cout << setw(width) << right << "";
    }
    cout << endl;
   
}