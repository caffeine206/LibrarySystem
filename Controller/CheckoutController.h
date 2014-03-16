#ifndef __CheckoutController_H
#define __CheckoutController_H

#include "./Controller.h"

class CheckoutController : public Controller {
  public:
    CheckoutController();
    void exec(Request* request);
  protected:
};

#endif
