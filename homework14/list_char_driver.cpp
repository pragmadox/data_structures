/*
 * Jay Price
 * Data Structures Final
 * December 12, 2016
 * Data Structures
 *
 */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "list_char.h"

using namespace std;

unsigned int seed = (unsigned int)time(0);

void print(list_char&);
double random(unsigned int&);
bool search_list(list_char&, char);

main( )
{
   list_char list;
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
