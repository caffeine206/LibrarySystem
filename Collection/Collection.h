#ifndef __Collection_H
#define __Collection_H

#include <algorithm>   // std::sort
#include <map>         // std::map
#include <set>         // std::set
#include <utility>     // std::pair
#include "../Model/Model.h"

using namespace std;

class Model;

typedef map<string, Model*> modelMap;
typedef pair<string, Model*> modelPair;
typedef set<Model*> modelSet;

class Collection {
 public:
  Collection();

  ~Collection();

  // Insert function for collection
  virtual void append(Model* model);

  // return sum of size[0..n]
  virtual int size();

  // Return list of models
  virtual set<Model*> getModels();

  virtual Model* find(string);

  // Optional
  // virtual void save();

 protected:
  // number of models
  int n;

  // Binary tree for sort
  modelSet setModels;

  // hashtable for search
  modelMap mapModels;
};

#endif
