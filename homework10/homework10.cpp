/*
    Jay Price
    Data Structures
    Homework 9
    Date: November 10, 2016
    Due Date: November 14, 2016
    Description: Create a recursive pointer-based function
    that populates a tree with random integer values, sorting 
    at each branch - less than or equal left - greater than right.
*/


#include <limits.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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

    p = head;
    cout << "The value of 'head' is: " << endl;
    cout << setw(width) << right << head->int_data << endl;
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
    cout << endl;
    width = width/2;
        if(p->left!=NULL)
        cout << setw(width) << right << p->left->int_data;
            else cout << setw(width) << right << " ";
        if(p->right!=NULL)
        cout << setw(width) << right << p->right->int_data;
            else cout << setw(width) << right << " ";
        cout << endl;
    width = width/2;
        if(p->left->left!=NULL)
        cout << setw(width) << right << p->left->left->int_data;
            else cout << setw(width) << right << " ";
        if(p->left->right!=NULL)
        cout << setw(width) << right << p->left->right->int_data;
            else cout << setw(width) << right << " ";
        if(p->right->left!=NULL)
        cout << setw(width) << right << p->right->left->int_data;
            else cout << setw(width) << right << " ";
        if(p->right->right!=NULL)
        cout << setw(width) << right << p->right->right->int_data;
            else cout << setw(width) << right << " ";
        cout << endl;
    width = width/2;
        if(p->left->left->left)
        cout << setw(width) << right << p->left->left->left->int_data;
            else cout << setw(width) << right << " ";
        if(p->left->left->right)
        cout << setw(width) << right << p->left->left->right->int_data;
            else cout << setw(width) << right << " ";
        if(p->left->right->left)
        cout << setw(width) << right << p->left->right->left->int_data;
            else cout << setw(width) << right << " ";
        if(p->left->right->right)
        cout << setw(width) << right << p->left->right->right->int_data;
            else cout << setw(width) << right << " ";
        if(p->right->right->left)
        cout << setw(width) << right << p->right->right->left->int_data;
            else cout << setw(width) << right << " ";
        if(p->right->right->right)
        cout << setw(width) << right << p->right->right->right->int_data;
            else cout << setw(width) << right << " ";
        cout << endl;
}