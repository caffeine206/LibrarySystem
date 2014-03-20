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

#ifndef __Collection_H
#define __Collection_H

#include <algorithm>   // std::sort
#include <string>   // std::string
#include "../Model/Model.h"

using namespace std;

class Collection {
 public:
  // Destructor
  virtual ~Collection();
  // ~Collection();

  // return sum of size[0..n]
  virtual int size() const; // Returns the current size of the collection

 protected:
  int n; // number of models

  virtual void append(Model* model) = 0; // Add a model to the collection
  Collection(); // Constructor
  Collection(Collection const&); // Copy constructor
  void operator=(Collection const&); // Comparison
};

#endif
