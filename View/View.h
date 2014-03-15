#ifndef __View_H
#define __View_H

#include <map>
#include "../lib/Config.h"
#include "../Collection/Collection.h"

using namespace std;

class View {
  public:
    View() {}
    virtual ~View() {}
    virtual void render() = 0;
  protected:
};

#endif
