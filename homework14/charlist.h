/*
 * Jay Price
 * December 7, 2016
 * Data Structures
 *
 */

#ifndef CHARLIST_H
#define CHARLIST_H

class charlist
{
   public:
      charlist( );
      charlist(const charlist&source);
      ~charlist( );
      //member functions
      bool empty( );
      bool at_end( );
      int length( );
      void first( );
      void next( );
      int data( );
      void insert(const char&item);
      bool retrieve(char&item);
      bool remove(char&item);
      void print();
      int find_first(char item);
      int find_last(char item);
      void remove_matching(char item);
      char get_index(int);
      charlist& operator= (const charlist&source);
      
   private:
      struct node
      {
         char data;
         node *next;
      };
      typedef node *node_ptr;
      int list_length;
      node_ptr head, current, previous;
      node_ptr get_node(const char&item);
};

#endif
