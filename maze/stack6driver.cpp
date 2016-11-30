//File: stack5driver.cpp
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack6.h"

using namespace std;

int main()
{
    stack stack1;
    
    stack1.initialize_stack(10);
    
    coords first_point;
    first_point.x = 0;
    first_point.y = 0;

    stack1.push(first_point);

    stack1.push(first_point);


    stack1.push(first_point);
    coords second_point;
    second_point.x = 35;
    second_point.y = 24;
    stack1.push(second_point);
    stack1.push(second_point);
    stack1.push(second_point);
    stack1.push(second_point);
   

    cout << "Popped characters are: ";
    while(!stack1.is_empty())
    {
        coords new_data;
        new_data = stack1.pop();
        cout << setw(2) << new_data.x << ", " << new_data.y << endl;
    }
    stack1.destroy_stack();
    cout << endl;
    return 0;
}