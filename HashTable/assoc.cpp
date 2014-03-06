//
//  assoc.cpp
//  CSS343assoc
//
//  Created by Sota on 3/5/14.
//  Copyright (c) 2014 Sota. All rights reserved.
//

#include "assoc.h"

// Constructors
template<class T>
assoc<T>::assoc();

// Destructor
template<class T>
assoc<T>::~assoc();

// Basic Operations
template<class T>
bool assoc<T>::contains( const string& key );
template<class T>
T assoc<T>::lookup( const string& key );
template<class T>
void assoc<T>::insert( const string& key, const T& value );

// Other Stuff
template<class T>
int assoc<T>::n() const;
template<class T>
double assoc<T>::load_factor() const {
}
template<class T>
double assoc<T>::get_max_load_factor() const;
template<class T>
void assoc<T>::set_max_load_factor( double factor );

// All value extraction
vector<T> values();

// (Test Stuff)
template<class T>
void assoc<T>::print( ostream& out ) const;

int test_assoc(int, int);