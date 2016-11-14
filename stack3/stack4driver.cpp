//File: stack4driver.cpp
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack4.h"

using namespace std;

const char *get_c_string();

int main()
{
    stack stack1;
    const char *traverse; //pointer used to traverse the user string.
    const char *user_string; //string entered by the user;
    cout << setw(23) << "Enter a string: ";
    user_string = get_c_string();
    initialize_stack(&stack1, strlen(user_string));
    /*Traverse the string and put each
    character on the stack.
    */
    for(traverse=user_string; *traverse!='\0'; traverse++)
        push(&stack1, *traverse);
    /* Pop each of the characters 
    off the stack and print them out.
    */
    cout << "Popped characters are: ";
    while(!is_empty(&stack1))
        cout << setw(2) << pop(&stack1);
    destroy_stack(&stack1);
    cout << endl;
    return 0;
}

//Foolproof way to get a a C-string from C++ input
//not exactly in the spirit of C.
//suffers from memory leak.
const char *get_c_string()
{
    string str;
    getline(cin, str);
    const char *s = str.c_str();
    return s;
}