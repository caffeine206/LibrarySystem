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

// using std::string;
// using std::vector;
// using std::ostream;
// using std::list;
// using std::cout;
// using std::cerr;
// using std::endl;
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
typename assoc<T>::pair** assoc<T>::createArray(int s) {
    pair ** preTable = new pair*[s];
    for (int i = 0; i < s; i++) {
        preTable[i] = NULL;
    }
    return preTable;
}

template<class T>
unsigned long int assoc<T>::hash(string key) {
    code = 2166136261;
    const char *ptr = key.c_str();
    while (*ptr) {
        code = (16777619 * code)^(*ptr);
        ptr++;
    }
    return code % size;
}

template<class T>
T assoc<T>::find(const string& key) {
    unsigned long int hashValue = hash(key);
    pair* front = table[hashValue];
    // cout << "Searching key:" << key << " ...." << endl;
    if (front) {
        pair* current = front;
        while (current) {
            // cout << "current->key:" << current->key << endl;
            if (current->key == key) {
                // cout << "key:" << key << " Found!" << endl;
                return current->value;
            }
            current = current->next;
        }
    }
    // cout << "***********key:" << key << " not found" << endl;
    return static_cast<T>(NULL);
}

// Basic Operations
template<class T>
bool assoc<T>::contains(const string& key)
// POST: a condition where key.size == 0 returns false.
{
    if (key.size() == 0) {
        return false;
    }
    return (find(key) != static_cast<T>(NULL));
}

template<class T>
bool assoc<T>::lookup( T& value, const string& key ) {
    T preValue = find(key);
    if (preValue != static_cast<T>(NULL)) {
        value = preValue;
        return true;
    } else {
        return false;
    }
}

template<class T>
void assoc<T>::insert(const string& key, const T& value) {

    // cout << "key:" << key << endl;

    if (key.size() == 0) {
        cerr << "key cannot be empty." << endl;
        return;
    }

    unsigned long int hashValue = hash(key);

    // cout << "size:" << size << endl;
    // cout << "hashValue:" << hashValue << endl;

    pair* front = table[hashValue];
    if (front) {
        // cout << "Added Front" << endl;
        table[hashValue] = new pair(key, value, front);
        // cout << "Added:" << key << endl;
    } else {
        // cout << "Created " << endl;
        table[hashValue] = new pair(key, value);
        n_elements++;
        checkSize();
        // cout << "Created:" << key << endl;
    }
    pairList.push_back(table[hashValue]);

    // cout << "vector size:" << pairList.size() << endl;

}

template<class T>
void assoc<T>::checkSize() {
    if (load_factor() > get_max_load_factor()) {
        resize();
    }
}

template<class T>
void assoc<T>::resize() {
    int newSize = size * 2;
    assoc<T> newAssoc(newSize);
    T value;
    for (typename list<pair*>::iterator it = pairList.begin(); it != pairList.end(); it++) {
        lookup(value, (*it)->key);
        newAssoc.insert((*it)->key, value);
    }
    delete [] table;
    table = newAssoc.table;
    n_elements = newAssoc.n_elements;
    size = newAssoc.size;
    pairList = newAssoc.pairList;
}

// Other Stuff
template<class T>
int assoc<T>::n() const {
    return pairList.size();
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
    T value;
    for (typename list<pair*>::iterator it = pairList.begin(); it != pairList.end(); it++) {
        lookup(value, (*it)->key);
        v.push_back(value);
    }
    return v;
}

// (Test Stuff)
template<class T>
void assoc<T>::print(ostream& out) const {
}
