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
 *
 * Unindexed is an abstract type of collection that should not be indexed.  
 * It is used to store a collection of models, such as histories.  
 * It includes the basic functionality of adding to the collection, destructing the 
 * collection, and viewing or accessing the collection.
 */

#ifndef __UnIndexed_H
#define __UnIndexed_H

#include "Collection.h"
#include <list>

typedef list<Model*> modelList;

class UnIndexed : public Collection {
  public:
    // Destructor
    ~UnIndexed(); 

    // Return list of models
    virtual modelList getModels() const;

    // Functions to iterate through the set of models
    virtual modelList::iterator begin();
    virtual modelList::iterator end();
  protected:
    // Insert function for collection
    virtual void append(Model* model);

    modelList listModel;

};

#endif
