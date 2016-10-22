//File stack1driver.cpp
#include <iostream>
#include <iomanip>
#include "stack1.h"

unsigned int seed = 17;
double random(unsigned int &seed);
using namespace std;

int main()
{
    stack s_1;
    cout << "s_1.is_empty() = " << s_1.is_empty() << endl;
    cout << "s_1.stack_size() = " << s_1.stack_size() << endl;
    int local_data;

    for(int i=0; i<10; ++i)
    {
        local_data = int(10*random(seed));
        cout << setw(5) << local_data << endl;
        s_1.push(local_data);
    }

    printf("Element at the top of the stack is: %d\n", s_1.top());
    printf("Stack elements are: \n");
    while(!s_1.is_empty())
    {
        int local_data = s_1.pop();
        printf("%7d\n", local_data);
    }

    printf("Stack full: %s\n", s_1.is_full()? "true":"false");
    printf("Stack empty: %s\n", s_1.is_empty()? "true":"false");
    return 0;
}