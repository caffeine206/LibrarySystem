//
//  assoc.h
//  CSS343assoc
//
//  Created by Sota on 3/5/14.
//  Copyright (c) 2014 Sota. All rights reserved.
//

#ifndef __CSS343assoc__assoc__
#define __CSS343assoc__assoc__

#include <iostream>
#include <vector>

using namespace std;

template<class T> class assoc {
public:
  // An internal structure is needed for the key/value pairs
  struct pair {
    string key;
    T      value;
    pair  *next;

    pair() : key(), value(), next(NULL) {}
    pair( const string& key, T value, pair* next = NULL )
    : key(key), value(value), next(next) {}
  };

  // Constructors
  assoc( int s = 4 );

  // Destructor
  ~assoc();

  // Basic Operations
  bool contains( const string& key );
  T lookup( const string& key );
  void insert( const string& key, const T& value );

  // Other Stuff
  int n() const;
  double load_factor() const;
  double get_max_load_factor() const;
  void set_max_load_factor( double factor );

  // All value extraction
  vector<T> values();

  // (Test Stuff)
  void print( ostream& out ) const;

  friend int test_assoc(int, int);
};

#endif /* defined(__CSS343assoc__assoc__) */
