#ifndef __Model_H
#define __Model_H

#include <map>
#include <string>
#include "boost/variant.hpp"

using namespace std;
typedef boost::variant<int, string> varientType;


class Model {
public:
  Model();
  void getById();
  // Todo make get(key)
  string getS(string key);
  int getI(string key);
  void set(string key, string value);
  void set(string key, int value);
  void save();
protected:
  std::map< string, varientType > columns;
  Collection collection;
};

#endif