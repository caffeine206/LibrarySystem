#ifndef __Collection_H
#define __Collection_H

#include <algorithm>    // std::sort
#include <list>         // std::list
#include "../Model/Model.h"

using namespace std;

class Collection {
public:
  Collection();

  // Insert function for single collection
  virtural void append(Model&);

  // Insert function for multiple collection
  virtural void append(int key, Model&);

  // Sort function for single collection
  void sort(void (*f)(const Model&));

  // Sort function for multiple collection
  void sort(int index, void (*f)(const Model&));

  // return sum of size[0..n]
  int size();

  // return size of models[n]
  int size(int n);

  // Return list of models
  list<Model> getModels(int n = 0);

  Model& find(string);

  //Optional
  void save();
protected:
  // array of sizes for each vectors
  int *size;

  // Collections can contain multiple lists
  // and This list are for display
  // By defualt, list[0] will be used
  list<Model> **models;

  // hashtable for search
  map<string key, Model&> searchMap;

  int primary_id = 1;

  // Add key-value to the map
  void createIndex(string, Model&);
};

#endif
