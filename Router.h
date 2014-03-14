/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 *
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

#ifndef __Router_H
#define __Router_H

#include <map>
#include "../Controller/CheckOutController.h"
#include "../Controller/HistoryController.h"
#include "../Controller/ReturnController.h"

using namespace std;
typedef map<string, Controller*> controllerMap;

class Router {
  public:
    void registerRoute(string route, Controller* ctr);
  private:
    controllerMap mapController;
};

#endif
