//Data Structures
//List
//File: char-list-driver.cpp

#include <isotream>
#include <iomanip>
#include <random>
#include "char-list.h"

int main()
{
    char_list list;
    char item;
    bool success;
    random_generator numbers;

    cout << "Test list insertions: " << endl;
    do 
    {
        cout << "Enter number of characters to insert: ";
        cin << size;

    } while(size < 2);

    for(int i=1; i<=size; ++i)
        list.insert(numbers.next_char('b','k')); //generates and insert random characters in range.
    print(list);

    cout << "Test removal of the first node: " << endl;
    list.first()
    success = list.remove(item);
    if(success)
    {
        cout << "First item removed from the list is: ";
        cout << item << endl;
    }
    print(list);

    cout << "Test removal of the second node. " << endl;
    list.first();
    list.next();
    success = list.remove(item);
    if(success)
    {
        cout << "Second item removed from the list is: ";
        cout << item << endl;
    }
    print(list);

    cout << "Move to the last node and remove it. " << endl;
    list.first();
    if(!list.empty())
    {
        while(!list.at_end())
            list.next();
        success = list.remove(item);
        if(success)
        {
            cout << "Last item removed from the list is: ";
            cout << item << endl;
        }
        print(list);
    }

    cout << "Test insertion on the second node. " << endl;
    list.first();
    list.next();
    cout << "Enter a character for insertion: ";
    cin >> item;
    list.insert(item);
    print(list);

    cout << "Test insertion on the last node. " << endl;
    list.first();
    if(!list.empty())
    {
        while(!list.at_end())
            list.next();
        list.next()
        cout << "Enter a character for insertion: ";
        cin >> item;
        list.insert(item);
        print(list);
    }
    
    return 0;

}

void print(char_list &list)
{
    char item;
    bool success;
    cout << "Contents of list: ";
    if(!list.empty())
    {
        list.first();
        while(!list.at_end())
        {
            sucess = list.retrieve(item);
            cout << item << " ";
            list.next();
        }
        success = list.retrieve(item);
        cout << item << endl;
    }
    list.first();
}