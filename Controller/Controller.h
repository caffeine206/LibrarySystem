#ifndef __Controller_H
#define __Controller_H

#include <map>
#include "../lib/Config.h"
#include "../Collection/Collection.h"
using namespace std;

typedef map<string, Collection*> collectoinMap;

class Controller {
  public:
    Controller();
    virtual ~Controller();
    virtual void exec() = 0;
    virtual void setCollection(string key, Collection* collection);
  protected:
    collectoinMap clMap;
};

#endif
