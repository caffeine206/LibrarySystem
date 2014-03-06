//
//  assoc.cpp
//  CSS343assoc
//
//  Created by Sota on 3/5/14.
//  Copyright (c) 2014 Sota. All rights reserved.
//

#include <string>
#include <vector>
#include <list>     // list
#include <iostream>
#include "./assoc.h"

using namespace std;

// Constructors
template<class T>
assoc<T>::assoc(int s) {
    init(s);
}

// init
template<class T>
void assoc<T>::init(int s) {
    size = s;
    n_elements = 0;
    table = createArray(s);
    set_max_load_factor(assoc<T>::default_max_factor);
}

// create an array
template<class T>
pair<T>* assoc<T>::createArray(int s) {
    int * preTable = new pair<T> [s]();
    for (int i = 0; i < s; i++) {
        preTable[i] = NULL;
    }
    return preTable;
}

unsigned long int hash(string key);
    code = 2166136261;
    const char *ptr = key;
    while (*ptr) {
        code = (16777619 * code)^(*ptr);
        ptr++;
    }
    return code % size;
}

template<class T>
T assoc<T>::find(const string& key) {
    unsigned long int hashValue = hash(key);
    pair<T>* front = table[hashValue];
    if (front != NULL) {
        pair<T>* current = front;
        while (current != NULL) {
            if (current->key == key) {
                return current->value;
            }
        }
    }
    return NULL;
}

// Basic Operations
template<class T>
bool assoc<T>::contains(const string& key) {
    return (find(key) != NULL);
}

template<class T>
bool assoc<T>::lookup( T& value, const string& key ) {
    T preValue = find(key);
    if (preValue != NULL) {
        value = preValue;
        return true;
    } else {
        return false;
    }
}

template<class T>
void assoc<T>::insert(const string& key, const T& value) {

    if (key.size == 0) {
        cerr << "key cannot be empty." << endl;
        return;
    }

    unsigned long int hashValue = hash(key);
    pair<T>* front = table[hashValue];
    if (front != NULL) {
        table[hashValue] = new pair<T>(key, value, front);
    } else {
        table[hashValue] = new pair<T>(key, value);
        usedBuckets.push_back(hashValue);
        n_elements++;
        checkSize();
    }
}

template<class T>
void assoc<t>::checkSize() {
    if (load_factor() > get_max_load_factor()) {
        resize();
    }
}

template<class T>
void assoc<t>::resize() {
    int newSize = size * 2;
    assoc<T> newAssoc(newSize);
    T value;
    for (list<int>::iterator it = usedBuckets.begin(); it != usedBuckets.end(); it++) {
        lookup(value, )
        newAssoc.insert();
    }
}

// Other Stuff
template<class T>
int assoc<T>::n() const {
    return n_elements;
}

template<class T>
double assoc<T>::load_factor() const {
    return n() / size;
}

template<class T>
double assoc<T>::get_max_load_factor() const {
    return max_load_factor;
}

template<class T>
void assoc<T>::set_max_load_factor(double factor) {
    if (factor > 0.0)
        max_load_factor = factor;
    else
        cerr << "max load factor has to be more than 0.0." << endl;
}

// All value extraction
template<class T>
vector<T> assoc<T>::values() {
    vector<T> v;
    return v;
}

// (Test Stuff)
template<class T>
void assoc<T>::print(ostream& out) const {
}
