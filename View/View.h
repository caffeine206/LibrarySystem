#ifndef __View_H
#define __View_H

using namespace std;

#include "../lib/Config.h"

class View {
  public:
    virtual ~View();
    virtual void render() = 0;
  protected:
};

#endif
