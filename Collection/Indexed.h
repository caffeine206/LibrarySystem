/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * Indexed is an abstract type of collection that has to be indexed for 
 * sorting purposes. It is used to store a collection of models, 
 * such as users and books. It includes the basic functionality of adding 
 * to the collection, destructing the collection, removing from the 
 * collection, and viewing or accessing the collection.
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

#ifndef __Indexed_H
#define __Indexed_H

#include <map>         // std::map
#include <set>         // std::set

#include "./Collection.h"

struct model_compare
// Comparison function for sorting models
{
    bool operator() (const Model* lhs, const Model* rhs) const {
        return *lhs < *rhs;
    }
};

// typedef of map for quickly accessing models
typedef map<string, Model*> modelMap;

// typedef of set for ordered sorting of models
typedef set<Model*, model_compare> modelSet;

class Indexed : public Collection {
 public:
    Indexed();
    virtual ~Indexed();

    // Return list of models
    virtual modelSet getModels() const;

    // Return a pointer to the model.
    virtual Model* find(const string key) const;

    // Remove an element at key
    virtual bool remove(const string key);

    // Functions to iterate through the set of models
    virtual modelSet::iterator begin() const;
    virtual modelSet::iterator end() const;

    // Optional
    // virtual void save();

    // Insert function for collection
    virtual void append(Model* model);

 protected:
    // Binary tree for sort
    modelSet setModels;

    // hashtable for search
    modelMap mapModels;

    // Set false if you don't need to destruct
    bool need2Destruct;
};

#endif
