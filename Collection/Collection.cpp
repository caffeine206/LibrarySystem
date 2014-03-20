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
 * Collection is an abstract class that can be extended by different types
 * of collections, such as histories, users, and books.  It is meant for holding
 * a collection of models.  It includes the basic functionality of constructing a 
 * collection and returning the size of the collection.
 */

#include "./Collection.h"

Collection::Collection(): n(0) 
// Default constructor
{
}

// Destructor
Collection::~Collection(){}

int Collection::size() const 
// Returns the current size of the collection
{
    return n;
}
