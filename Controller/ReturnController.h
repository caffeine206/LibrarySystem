#ifndef __ReturnController_H
#define __ReturnController_H

#include "./Controller.h"

class ReturnController : public Controller {
  public:
    ReturnController();
    void exec(Request* request);
  protected:
};

#endif
