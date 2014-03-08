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


#include <string>
#include <vector>
#include <list>     // list
#include <iostream>

using namespace std;

// Constructors
template<class T>
assoc<T>::assoc(int s) 
// Pre: s must be greater than 0
// Post: Constructs a new assoc object
{
    init(s); // call the initializer
}

// Helper Functions
template<class T>
void assoc<T>::init(int s) 
// Helper function for intializing a new assoc object
// Pre: s must be greater than 0, else will set to default size
// Post: Initializes a new assoc object
{
    if (s < 1) { // invalid size
        s = default_size;
        cerr << "size set to default due to invalid size" << endl;
    }
    size = s;
    n_elements = 0;
    table = createArray(s); // call create array helper
    set_max_load_factor(assoc<T>::default_max_factor);
}

template<class T>
typename assoc<T>::pair** assoc<T>::createArray(int s)
// Helper function for creating a new table
// Pre: s must be greater than 0, else program breaks
// Post: Initializes a new table with NULL values
{
    pair ** preTable = new pair*[s];
    for (int i = 0; i < s; i++) {
        preTable[i] = NULL;
    }
    return preTable;
}

template<class T>
unsigned long int assoc<T>::hash(string key) 
// Helper function for generating a hash value for a key
// Pre: Key should not be empty, else it will generate the
// same value each time
// Post: Returns a hash value for a key
{
    code = 2166136261; // magic prime number
    const char *ptr = key.c_str();
    while (*ptr) {
        code = (16777619 * code)^(*ptr);
        ptr++;
    }
    return code % size;
}

template<class T>
T assoc<T>::find(const string& key) 
// Helper function for locating a key in the table
// Pre: Key must not be empty, else returns NULL
// Post: Returns the associated value of the given key, or
// NULL if not found
{
    if (key.size() == 0) { // key is empty
        return static_cast<T>(NULL);
    }
    // get hash value for the key
    unsigned long int hashValue = hash(key);

    pair* front = table[hashValue];
    if (front) { // a pair exists at the key
        pair* current = front;
        while (current) { // traverse the linked pairs
            if (current->key == key) {
                // return the value if it matches
                return current->value; 
            }
            current = current->next;
        }
    }
    return static_cast<T>(NULL); // key not found
}

template<class T>
void assoc<T>::checkSize() 
// Helper function for checking if the table's size needs
// to be increased
// Post: If load factor has been reached, call resize helper
{
    if (load_factor() > get_max_load_factor()) {
        resize();
    }
}

template<class T>
void assoc<T>::resize() 
// Helper function for resizing the table
// Post: Doubles the size of the array and rehashes the contents
{
    int newSize = size * 2;
    pair ** tmpTable = createArray(newSize);
    int tmp_n_elements;

    // Iterate over the list of active pairs and rehash them into new
    // array
    for (typename list<pair*>::iterator it = pairList.begin(); it != pairList.end(); it++) {
        unsigned long int hashValue = hash((*it)->key);
        pair* front = tmpTable[hashValue];
        if (front) {
            tmpTable[hashValue] = new pair((*it)->key, (*it)->value, front);
        } else {
            tmpTable[hashValue] = new pair((*it)->key, (*it)->value);
            tmp_n_elements++;
        }
    }

    // assign new values and delete old table
    delete [] table;
    table = tmpTable;
    n_elements = tmp_n_elements;
    size = newSize;
}

// Basic Operations
template<class T>
bool assoc<T>::contains(const string& key)
// Returns whether or not a given key is contained in 
// the table
// Pre: Key must not be empty, else returns false
// Post: returns true if key is contained in table,
// false otherwise
{
    return (find(key) != static_cast<T>(NULL));
}

template<class T>
bool assoc<T>::lookup( T& value, const string& key ) 
// Finds a given key in the table
// Pre: Key must not be empty, else returns false
// Post: Returns true and updates the given value to the associated
// value of the key if the key is contained in the table, 
// false otherwise
{
    T preValue = find(key); // call the find helper function
    if (preValue != static_cast<T>(NULL)) { // key exists
        value = preValue; // update given value
        return true;
    } else { // key not found
        return false;
    }
}

template<class T>
void assoc<T>::insert(const string& key, const T& value) 
// Inserts a given key value pair into the table
// Pre: Key must not be empty, else outputs error and
// nothing happens
// Post: Updates table, list of active pairs, and number
// of elements with the new key value pair. Also resizes
// if max load factor is surpassed.
{
    if (key.size() == 0) { // key is empty
        cerr << "key cannot be empty." << endl;
        return;
    }
    // get hash value for given key
    unsigned long int hashValue = hash(key);

    pair* front = table[hashValue];
    if (front) { // key already exists
        table[hashValue] = new pair(key, value, front);
    } else { // make new key here
        table[hashValue] = new pair(key, value);
        n_elements++; // update number of elements
        checkSize(); // check if load factor is surpassed
    }
    // add to list of active pairs
    pairList.push_back(table[hashValue]); 
}

// Other Stuff
template<class T>
int assoc<T>::n() const 
// Returns the number of pairs in the table
{
    return pairList.size();
}

template<class T>
double assoc<T>::load_factor() const 
// Returns the current ratio of keys to the size of the array
{
    return n_elements / size;
}

template<class T>
double assoc<T>::get_max_load_factor() const 
// Returns the highest ratio of keys to the size of
// array allowed before resizing
{
    return max_load_factor;
}

template<class T>
void assoc<T>::set_max_load_factor(double factor) 
// Adjusts the highest ratio of keys to the size of array
// allowed before resizing
// Pre: Factor must be greater than 0, else outputs error
// Post: Updates max load factor to given factor
{
    if (factor > 0.0)
        max_load_factor = factor;
    else
        cerr << "max load factor has to be more than 0.0." << endl;
}

// All value extraction
template<class T>
vector<T> assoc<T>::values() 
// Function for extracting all values from the table
// Pre: Table must contain values, else returns empty list
// Post: Returns list of all values currently in the table
{
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
