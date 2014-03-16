#ifndef __InitController_H
#define __InitController_H

#include "./Controller.h"

class InitController : public Controller {
  public:
    InitController();
    void exec(Request* request);
  protected:
};

#endif
