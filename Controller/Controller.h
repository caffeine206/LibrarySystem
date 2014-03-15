#ifndef __Controller_H
#define __Controller_H

#include "../lib/Config.h"
#include "../lib/Request/Request.h"
using namespace std;

class Controller {
  public:
    Controller();
    virtual ~Controller();
    virtual void exec(Request* request) = 0;
  protected:
};

#endif
