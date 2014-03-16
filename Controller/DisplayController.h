#ifndef __DisplayController_H
#define __DisplayController_H

#include "./Controller.h"
#include "../View/ListView.h"

class DisplayController : public Controller {
  public:
    DisplayController();
    void exec(Request* request);

  protected:
};

#endif
