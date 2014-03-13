#ifndef __UnIndexed_H
#define __UnIndexed_H

#include "Collection.h"
#include <list>

typedef list<Model*> modelList;

class UnIndexed : public Collection {
  public:
    ~UnIndexed();
    // Insert function for collection
    virtual void append(Model* model);

    // Return list of models
    virtual modelList getModels() const;

    // Functions to iterate through the set of models
    virtual modelList::iterator begin();
    virtual modelList::iterator end();
  protected:
    modelList listModel;

};

#endif
