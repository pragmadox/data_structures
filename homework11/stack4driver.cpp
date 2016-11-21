//File: stack4driver.cpp
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack4.h"

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
    initialize_stack(&stack1, strlen(user_string));
    /*Traverse the string and put each
    character on the stack.
    */
    for(traverse=user_string; *traverse!='\0'; traverse++)
        push(&stack1, *traverse);
    /* Demonstrate the top function.
    */
    cout << "The top of the stack is: ";
    cout << top(&stack1) << endl;

    cout << "The top of the stack is: ";
    cout << top(&stack1) << endl;

    cout << "Popped characters are: ";
    while(!isempty(&stack1))
        cout << setw(2) << pop(&stack1);
    destroy_stack(&stack1);
    cout << endl;
    return 0;
}