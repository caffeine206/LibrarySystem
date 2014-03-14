#ifndef __View_H
#define __View_H

using namespace std;

#include <map>
#include "../lib/Config.h"
#include "../Collection/Collection.h"

typedef map<string, Collection*> collectoinMap;

class View {
  public:
    View() {}
    virtual ~View() {}
    virtual void render() = 0;
    virtual void setCollection(string key, Collection* collection);
    virtual void setOstream(ostream* out);
  protected:
    collectoinMap mapCollection;
    ostream* out;
};

#endif
