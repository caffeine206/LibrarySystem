#ifndef __CheckoutController_H
#define __CheckoutController_H

#include "./BookController.h"

class CheckoutController : public BookController {
  public:
    CheckoutController();
    void exec(Request* request);
  protected:
};

#endif
