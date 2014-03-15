#ifndef __CheckoutController_H
#define __CheckoutController_H

#include "./ShhhController.h"

class CheckoutController : public ShhhController {
  public:
    CheckoutController();
    void exec(Request* request);
  protected:
};

#endif
