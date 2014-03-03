#ifndef __Router_H
#define __Router_H

#include "../Controller/CheckOutController.h"
#include "../Controller/HistoryController.h"
#include "../Controller/ReturnController.h"

class Router {
  public:
    void registerRoute(string rounte, callback);
  private:
  

};

#endif
