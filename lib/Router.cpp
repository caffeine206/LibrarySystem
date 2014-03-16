
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

#include "./Router.h"

Router& Router::getInstance() {
    // Auto destroyed Singleton
    static Router instance;
    return instance;
}

Router::Router() {
    init();
}

Router::~Router() {
    clear();
}

void Router::start(Request* request) {
    InitController initCtr;
    initCtr.exec(request);
}

void Router::clear() {
    for (collectionMap::iterator it = mapCtr.begin();
         it != mapCtr.end(); ++it) {
        delete it->second;
    }
    mapCtr.clear();
}

void Router::init() {
    clear();

    // Add Checkout Controller
    CheckoutController* checkoutCtr = new CheckoutController();
    registerRoute(Config::CMD_CHECKOUT, checkoutCtr);

    // Add Return Controller
    ReturnController* returnCtr = new ReturnController();
    registerRoute(Config::CMD_RETURN, returnCtr);

    // Add History Controller
    HistoryController* historyCtr = new HistoryController();
    registerRoute(Config::CMD_HISOTRY, historyCtr);

    // Add Display Controller
    DisplayController* displayCtr = new DisplayController();
    registerRoute(Config::CMD_DISPLAY, displayCtr);
}

void Router::go(Request* request) {
    string key = request->get("command");
    if ( key.empty() || mapCtr.find(key) == mapCtr.end() ) { // not found
        cerr << "Error: Router::go() Invalid Command" << endl;
    } else { // found
        mapCtr[key]->exec(request);
    }
}

void Router::registerRoute(string route, Controller* ctr) {
    mapCtr[route] = ctr;
}

