#ifndef __Indexed_H
#define __Indexed_H

#include <map>         // std::map
#include <set>         // std::set
#include <utility>     // std::pair

#include "./Collection.h"

typedef map<string, Model*> modelMap;
typedef pair<string, Model*> modelPair;
typedef set<Model*> modelSet;

class Indexed : public Collection {
 public:
    ~Indexed();

    // Return list of models
    virtual set<Model*> getModels() const;

    // Return a pointer to the model.
    virtual Model* find(const string key);

    // Functions to iterate through the set of models
    virtual modelSet::iterator begin() const;
    virtual modelSet::iterator end() const;

    // Optional
    // virtual void save();

 protected:
    // Insert function for collection
    virtual void append(Model* model);

    // Binary tree for sort
    modelSet setModels;

    // hashtable for search
    modelMap mapModels;
};

#endif
