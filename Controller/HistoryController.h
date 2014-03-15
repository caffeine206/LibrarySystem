#ifndef __HistoryController_H
#define __HistoryController_H

#include "./ShhhController.h"

class HistoryController : public ShhhController {
  public:
    HistoryController();
    void exec(Request* request);

  protected:
};

#endif
