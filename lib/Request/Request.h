#ifndef __Request_H
#define __Request_H

#include <iostream>
#include <string>
#include <map>
#include "../Config.h"

using namespace std;

class Request {
  public:
    Request();
    virtual ~Request();
    virtual void parse(string) = 0;
    // Returns the value associated with the key
    virtual string get(const string key) const;
    // Set the value associated with the key
    virtual void set(const string key, const string value);
    // Clears the map
    virtual void clear();
    // Returns the # of elements
    virtual int size();
    // number of commands
  protected:
    map<string, string> requests;
};

#endif
