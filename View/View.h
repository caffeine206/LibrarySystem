#ifndef __View_H
#define __View_H

#include <map>
#include <string>
using namespace std;

class View {
  public:
  virtual void render() = 0;
  protected:
  string keys[];
  map<string key, string value[]> displayValues;
};

#endif
