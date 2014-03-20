
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
 *
 * Router class is used to route requests to the necessary controller.
 * It contains the functionality to initialize requests, execute requests,
 * iterate over controllers, and establish routes to controllers.
 */

#include "./Router.h"

Router& Router::getInstance() 
// Create a static router instance
{
    // Auto destroyed Singleton
    static Router instance;
    return instance;
}

Router::Router() 
// Constructor
{
    init();
}

Router::~Router() 
// Destructor
{
    clear();
}

void Router::start(Request* request) 
// Sends an initialization request to the initController to start the
// library system
{
    InitController initCtr;
    initCtr.exec(request);
}

void Router::clear() 
// Helper function for the destructor
// Deletes the map containing controllers
{
    for (ctrMap::iterator it = mapCtr.begin();
         it != mapCtr.end(); ++it) {
        delete it->second;
    }
    mapCtr.clear();
}

void Router::init() 
// Initializes the different controllers to prepare the system for requests
{
    clear();

    // Add Checkout Controller
    CheckoutController* checkoutCtr = new CheckoutController();
    registerRoute(Config::CMD_CHECKOUT, checkoutCtr);

    // Add Return Controller
    ReturnController* returnCtr = new ReturnController();
    registerRoute(Config::CMD_RETURN, returnCtr);

    // Add History Controller
    HistoryController* historyCtr = new HistoryController();
    registerRoute(Config::CMD_HISTORY, historyCtr);

    // Add Display Controller
    DisplayController* displayCtr = new DisplayController();
    registerRoute(Config::CMD_DISPLAY, displayCtr);
}

void Router::go(Request* request) 
// Pre: Command request must be valid, else it will error or return nothing
// Post: Sends a request to the respective controller
{
    string key = request->get("command");
    if (key.empty()) { // Ignore empty command
        return;
    }
    ctrMap::const_iterator it = mapCtr.find(key); // Look for the command
    if (it == mapCtr.end()) { // Invalid command
        cerr << "Error:: Command:: "
             << "Sorry, I don't recognise your command." << endl;
    } else { // Valid command
        it->second->exec(request);
    }
}

void Router::registerRoute(string route, Controller* ctr) 
// Adds a route to the router's mapping
{
    mapCtr[route] = ctr;
}

