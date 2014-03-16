/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 *
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

typedef map<string, Model*> modelMap;
typedef set<Model*> modelSet;

class Indexed : public Collection {
 public:
    Indexed();
    virtual ~Indexed();

    // Return list of models
    virtual set<Model*> getModels() const;

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
