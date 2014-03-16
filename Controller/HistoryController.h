#ifndef __HistoryController_H
#define __HistoryController_H

#include "./Controller.h"
#include "../View/HistoryView.h"

class HistoryController : public Controller {
  public:
    HistoryController();
    void exec(Request* request);

  protected:
};

#endif
