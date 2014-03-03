#ifndef __View_H
#define __View_H

using namespace std
#include <map>
#include <string>

class View {
  public:
  virtual void render() = 0;
  protected:
  string keys[];
  map<string key, string value[]> displayValues;
};

#endif
