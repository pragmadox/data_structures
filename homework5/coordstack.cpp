#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>

using namespace std;

const int MAXSIZE = 25;

struct coords
{
    int x;
    int y;
};

coords path[MAXSIZE];
int current_size = -1;

int is_empty()
{
    if( current_size == -1)
        return 1;
        else 
            return 0;
}

int is_full()
{
    if( current_size == MAXSIZE)
        return 1;
        else
            return 0;
}

coords top()
{
    if(!is_empty())
        return path[current_size];
    else
        printf("Could not retrieve data. path is empty.\n");
}

coords pop()
{
    coords data;
    if(!is_empty())
    {
        data = path[current_size];
        current_size = current_size - 1;
        return data;
    }
    else
        printf("Could not retrieve data. path is empty.\n");
}

void push(coords data)
{
    if(!is_full())
    {
        current_size = current_size + 1;
        path[current_size] = data;
    }
    else
        printf("Could not insert data. path is full.\n");
}

int main()
{


    coords local_data;
    //example for testing push function and 'is_full' function
    for( int i=1; i<20; i++)
    {
        local_data.x = 15;
        local_data.y = 12;
        push(local_data);
    }

    //for testing top function when not empty
    for( int i=1; i<20; i++)
    {
        coords last_element = top();
        cout << last_element.x << endl;
        cout << last_element.y << endl;
    }
    //for testing pop function and 'is_empty' function
    for( int i=1; i<5; i++)
        pop();

    //for testing top function when empty
    coords last_element = top();
    cout << last_element.x << " " << last_element.y;

}

//There were some runtime errors from the code in class that I corrected.
//You already explained in class the limitations of this path implementation.
//It limits the user to only one path structure. A class is needed.