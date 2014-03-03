#ifndef __Collection_H
#define __Collection_H

#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include "../Model/Model.h"

using namespace std;

class Collection {
public:
  Collection();
  void apend(Model&);
  // Sort functioin for single collection
  void sort(void (*f)(const Model&));
  // Sort function for multiple collection
  void sort(int index, void (*f)(const Model&));
  Model[] getModels();
  Model& find(string);
  //Optional
  void save();
protected:
  // It can make multiple vectors
  // This vectors are for display
  vector<Model> **models;

  //
  map<string key, Model&> searchMap;

  int primary_id = 1;

  // Add key-value to the map
  void createIndex(string, Model&);
};

#endif
