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
  Model();
  ~Model() {}
  // void getById();
  // Todo make get(key)
  // string getS(string key);
  // int getI(string key);
  // void set(string key, string value);
  // void set(string key, int value);
  void save();
  virtual string key() = 0;
 protected:
  // std::map< string, varientType > columns;
};

#endif
