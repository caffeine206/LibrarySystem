#ifndef __Collection_H
#define __Collection_H

#include <algorithm>   // std::sort
#include <string>   // std::string
#include "../Model/Model.h"

using namespace std;

class Collection {
 public:
  virtual ~Collection();
  // ~Collection();

  // return sum of size[0..n]
  virtual int size() const;

 protected:
  // number of models
  int n;

  // Insert function for collection
  virtual void append(Model* model) = 0;
  Collection();
  Collection(Collection const&);
  void operator=(Collection const&);
};

#endif
