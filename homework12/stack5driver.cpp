/*  
    Jay Price
    Data Structures
    Homework 12
    Due Date: December 1, 2016
    Date: November 25, 2016
    Description: 
    - Read a string from input 
    - Push characters from the string on s1
    - Pop characters from s1
    - Output them to the screen
    Use the class-based implementation of the stack defined in class.
    File: stack5driver.cpp
*/

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack5.h"

using namespace std;

int main()
{
    stack stack1;
    const char *traverse; //pointer used to traverse the user string.
    const char *user_string; //string entered by the user;
    cout << setw(23) << "Enter a string: ";
    string str;
    getline(cin, str);
    user_string = str.c_str();
    stack1.initialize_stack(strlen(user_string));
    /*Traverse the string and put each
    character on the stack.
    */
    for(traverse=user_string; *traverse!='\0'; traverse++)
        stack1.push(*traverse);
    /* Demonstrate the top function.
    */
    cout << "The top of the stack is: ";
    cout << stack1.top() << endl;

    cout << "The top of the stack is: ";
    cout << stack1.top() << endl;

    cout << "Popped characters are: ";
    while(!stack1.is_empty())
        cout << setw(2) << stack1.pop();
    stack1.destroy_stack();
    cout << endl;
    return 0;
}