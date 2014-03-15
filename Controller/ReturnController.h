#ifndef __ReturnController_H
#define __ReturnController_H

#include "./BookController.h"

class ReturnController : public BookController {
  public:
    ReturnController();
    void exec(Request* request);
  protected:
};

#endif
