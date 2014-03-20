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

#include "./UnIndexed.h"

UnIndexed::~UnIndexed() 
// Destructor
{
    // Iterate over list of models and delete each pointer
    for (modelList::iterator it = listModel.begin();
        it != listModel.end(); ++it) {
        delete *it;
    }
}

void UnIndexed::append(Model* model) 
// Add a model to the model collection
{
    listModel.push_back(model);
    this->n++;
}

modelList UnIndexed::getModels() const 
// Returns the collection of models
{
    return listModel;
}

modelList::iterator UnIndexed::begin() 
// Location to start at when iterating over models in collection
{
    return listModel.begin();
}

modelList::iterator UnIndexed::end() 
// Location to end at when iterating over models in collection
{
    return listModel.end();
}
