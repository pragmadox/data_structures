/*
    Jay Price
    Data Structures Final
    December 12, 2016
    File: list_char_driver.cpp
*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include "list_char.h"

using namespace std;

unsigned int seed = (unsigned int)time(0);
double random(unsigned int &);

main()
{
    list_char list;
    char item;
    int size;

    cout << "Test empty function:" << endl;
    if(list.empty())
        cout << "The list is empty." << endl << endl;
    else
        cout << "The list is not empty." << endl << endl;

    cout << "Test list insertions:" << endl;
    do
    {
        cout << "Enter number of characters to insert: ";
        cin >> size;
    } while (size < 2);

    for (int i = 0; i < size; ++i)
        list.insert(char('a' + ('z' - 'b') * random(seed)));

    list.print();
    cout << endl << "Test the length function: " << endl;
    int length = list.length();
    cout << "The length of the list is: " << length << endl << endl;

    cout << "Test empty function:" << endl;
    if(list.empty())
        cout << "The list is empty." << endl << endl;
    else
        cout << "The list is not empty." << endl << endl;

    char search;
    cout << "Enter the character to remove from the list: ";
    cin >> search;
    cout << endl;
    list.remove(search);
    list.print();
    cout << endl;

    cout << "Testing the find_first() function:" << endl;
    cout << "Enter the search character: ";
    cin >> search;
    cout << endl;
    int index = list.find_first(search);
    cout << endl;

    cout << "Testing the find_last() function:" << endl;
    list.print();
    cout << "Enter the search character: ";
    cin >> search;
    cout << endl;
    index = list.find_last(search);
    cout << endl;

    cout << "Testing the get_index() function: " << endl;
    list.print();
    cout << "Pick a list index at which to return the character: ";
    cin >> index;
    char result = list.get_index(index);
    cout << "The character at index " << index << " is: " << result << endl;
    cout << "Pick another list index at which to return the character: ";
    cin >> index;
    result = list.get_index(index);
    cout << "The character at index " << index << " is: " << result << endl;


}



double random(unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;
    return (double)seed / (double)MODULUS;
}
