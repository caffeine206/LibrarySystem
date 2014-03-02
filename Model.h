#ifndef __Model_H
#define __Model_H

#include <map>;
#include <string>;
#include "boost/variant.hpp"
typedef boost::variant<int, string> varientType;

using namespace std;

class Model {
 public:
    virtual Model() = 0;
    getById();
    string get(string key) {}
    int get(string key) {}
    set(string key, string value) {}
    set(string key, int value) {}
    save() {}
 protected:
    std::map< string, varientType > columns;
    Collection collection;
};

#endif
