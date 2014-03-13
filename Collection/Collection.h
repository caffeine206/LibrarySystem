#ifndef __Collection_H
#define __Collection_H

#include <algorithm>   // std::sort
#include <string>   // std::string
#include "../Model/Model.h"

using namespace std;

class Model;

class Collection {
 public:
  Collection();
  virtual ~Collection();
  // ~Collection();

  // Insert function for collection
  virtual void append(Model* model) = 0;

  // return sum of size[0..n]
  virtual int size() const;

 protected:
  // number of models
  int n;
};

#endif
