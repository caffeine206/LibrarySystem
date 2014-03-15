#ifndef __View_H
#define __View_H

#include <map>
#include "../lib/Config.h"
#include "../Collection/Collection.h"
#include "../lib/Request/Request.h"

using namespace std;

class View {
  public:
    View() {}
    virtual ~View() {}
    virtual void render(Request* request = NULL) = 0;
  protected:
};

#endif
