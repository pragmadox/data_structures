/*
 * Jay Price
 * December 7, 2016
 * Data Structures
 *
 */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "charlist.h"

using namespace std;

unsigned int seed = time(0);

void print(charlist&);
double random(unsigned int&);
bool search_list(charlist&, char);

main( )
{
   charlist list;
   char item;
   int size;
   bool success;
   char search_char;
   
   cout << "Test list insertions:" << endl;

   do
   {
      cout << "Enter number of characters to insert: ";
      cin >> size;
   } while (size < 2);

   for (int i = 0; i < size; ++i)
      list.insert(char('b' + ('k' - 'b' + 1) * random(seed)));

   list.print();

   cout << "Enter character to search for in list: ";
   cin >> search_char;

   int index;
   index = list.find_first(search_char);
   cout << "The list index for the first time that character appears is: " << index << endl;
   index = list.find_last(search_char);
   cout << "The list index for the last time that character appears is: " << index << endl;

   cout << "Test retrieving a particular index." << endl;
   char element;
   element = list.get_index(index);
   cout << "The character at index " << index << " is: " << element << endl;
   index = 5;
   element = list.get_index(index);
   cout << "The character at index " << index << " is: " << element << endl;
   index = 10;
   element = list.get_index(index);
   cout << "The character at index " << index << " is: " << element << endl;
   index = 50;
   element = list.get_index(index);
   cout << "The character at index " << index << " is: " << element << endl;

   char search;
   cout << endl << "Enter the character to remove from the list: ";
   cin >> search;
   cout << endl;
   list.remove_matching(search);
   list.print();

}

double random(unsigned int&seed)
{
   const int MODULUS = 15749;
   const int MULTIPLIER = 69069;
   const int INCREMENT = 1;
   seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;
   return (double) seed / (double) MODULUS;
}
