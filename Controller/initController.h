#ifndef __InitController_H
#define __InitController_H

#include "./ShhhController.h"

class InitController : public ShhhController {
  public:
    InitController();
    void exec(Request* request);
  protected:
};

#endif
