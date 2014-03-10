/**
 * Programming Assignment #4 HashTable<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/7/2014<br>
 *
 * <p>
 * HashTable implementation
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

#ifndef __assoc_H
#define __assoc_H

#include <vector>
#include <list>

using std::string;
using std::vector;
using std::ostream;
using std::list;

template<class T> class assoc {
 public:
  /* An internal structure is needed for the key/value pairs */
  struct pair {
    string key;   // key (always a string)
    T      value; // value associated with the key
    pair  *next;  // next in the chain (omit for open addressing)

    // Default constructor (if needed)
    pair() : key(), value(), next(NULL) {}

    // Basic constructor: sets the three fields
    pair( const string& key, T value, pair* next = NULL )
      : key(key), value(value), next(next) {}
  };


  /* Constructors */

  // intialializes the table to the given size
  assoc( int s = 4 );

  // (The destructor is omitted)


  /* Basic operations */

  // Tests for containment of the given key in this table
  bool contains( const string& key );

  // Searches for the value associated with key in this table.
  // If it is found, value is set to the associated value and true
  // is returned; otherwise false is returned and value is unmodified.
  bool lookup( T& value, const string& key );
  // T lookup( const string& key ); // (original signature)

  // Associates value with key in this table,
  // replacing any existing association.
  void insert( const string& key, const T& value );


  /* Other operations */

  // Returns the total number of key/value pairs in this table
  int n() const;

  // Returns the load factor: the ratio of the number of pair to the table size
  double load_factor() const;

  // Returns the maximum allowable load factor.  If the actual load factor
  // exceeds this, the table will be resized.
  void set_max_load_factor( double factor );

  // Returns the current maximum load factor
  double get_max_load_factor() const;


  // All value extraction: the returned vector contains the value for each
  // key/value pair stored in this table.
  vector<T> values();

  // (Test Stuff)
  void print( ostream& out ) const;
  friend int test_assoc(int, int);

 private:
  // Max load factor
  double max_load_factor;

  // Array for table
  pair ** table;

  // List of pairs
  list<pair*> pairList;

  // size of array
  int size;

  // Initialize table
  void init (int s);

  // Create array
  pair** createArray(int s);

  // Magic prime number
  unsigned long int code;

  // Hash function
  unsigned long int hash(string key);

  // Check current load factor
  void checkSize();

  // Resize array and rehash values
  void resize();
};

#include "assoc.cpp"
#endif
