/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * Indexed is an abstract type of collection that has to be indexed for 
 * sorting purposes. It is used to store a collection of models, such as users 
 * and books. It includes the basic functionality of adding to the collection,
 * destructing the collection, removing from the collection, and viewing or 
 * accessing the collection.
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */
#include <set>
#include "./Indexed.h"

Indexed::Indexed() : need2Destruct(true) {
}

// Destructor
Indexed::~Indexed() {
    if (need2Destruct) {
        for (Indexed::modelSet::iterator it = setModels.begin();
            it != setModels.end(); ++it) {
            if (*it) {
                delete *it;
            }
        }
        setModels.clear();
    }
}

void Indexed::append(Model* model)
// Add a model to the indexed collection.
{
    mapModels[model->key()] = model;
    setModels.insert(model); // insert the model
    this->n++; // increment number of models in collection
}

Indexed::modelSet Indexed::getModels() const
// Returns the list of models currently in the collection
{
    return setModels;
}

Model* Indexed::find(const string key) const
// Pre: Model being searched for must have valid search key, else returns 
// empty key error.
// Post: Returns the given model at key, else false if it cannot be found
{
    if (key.empty()) { // Improper search key
        cerr << "ERROR: Indexed::find() Empty Key" << endl;
        return NULL;
    }

    // Iterate over collection and locate key
    modelMap::const_iterator it = mapModels.find(key);
    if (it == mapModels.end()) { // not found
        return NULL;
    } else { // found
        return it->second;
    }
}

bool Indexed::remove(const string key)
// Pre: Model being searched for must have valid search key, else returns 
// empty key error.
// Post: Returns true if removal is successful, false otherwise
{
    // Iterate over collection and locate key
    modelMap::iterator it = mapModels.find(key);
    if ( key.empty() || it == mapModels.end() ) { // not found
        cerr << "ERROR: Indexed::remove() Invalid Key" << endl;
        return false;
    } else { // found; remove key
        setModels.erase(it);
        mapModels.erase(it);
        this->n--; // decrement number of models in collection
        return true;
    }
}

Indexed::modelSet::iterator Indexed::begin() const
// Location to start at when iterating over models in collection
{
    return setModels.begin();
}

Indexed::modelSet::iterator Indexed::end() const
// Location to end at when iterating over models in collection
{
    return setModels.end();
}

