#ifndef __HistoryController_H
#define __HistoryController_H

#include "./ShhhController.h"
#include "../View/HistoryView.h"

class HistoryController : public ShhhController {
  public:
    HistoryController();
    void exec(Request* request);

  protected:
};

#endif
