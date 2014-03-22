
/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * Router class is used to route requests to the necessary controller.
 * It contains the functionality to initialize requests, execute requests,
 * iterate over controllers, and establish routes to controllers.
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
#include "../Controller/InitController.h"
#include "../Controller/DisplayController.h"

using namespace std;

typedef map<string, Controller*> ctrMap;

class Router {
  public:
    static Router& getInstance(); // Initialize the router
    Router(Request* request); // Constructor
    ~Router(); // Destructor
    void start(Request* request); // Initialize the system
    void go(Request* request); // Send a request to respective controller
  private:
    void init(); // Initialize the router
    void clear(); // Delete all mappings
    void registerRoute(string route, Controller* ctr); // Create a mapping
    // to a controller
    ctrMap mapCtr; // Map of controllers
    Router(); // Default constructor
    Router(Router const&); // Copy constructor
};

#endif
