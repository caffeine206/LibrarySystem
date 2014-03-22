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
 * Model is an abstract class that can be extended by entities such as 
 * history, book, and user.  It has a common functionality of being able to
 * save and print, and it has a unique key for storing purposes.
 */

#ifndef __Model_H
#define __Model_H

// #include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>

#include "../lib/Config.h"
using namespace std;
// typedef boost::variant<int, string> varientType;


class Model {
 public:
  // Constructor
  Model() {}

  // Destructor
  virtual ~Model() {}

  virtual string key() const = 0;

  // Output functionality
  virtual void print(ostream& out) const = 0;
  friend ostream& operator<< (std::ostream &out,
                             const Model &model);

  // Returns a type of class (to make life easier)
  virtual string typeOf() const = 0;

  // Comparison
  virtual bool operator<(const Model & rhs) const;
 protected:
  // std::map< string, varientType > columns;
};

#endif
