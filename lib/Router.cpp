
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

Router::Router(Request* request) {
    init(request);
}

Router::~Router() {
    clear();
}

void Router::clear() {
    for (collectoinMap::iterator it = mapCtr.begin();
         it != mapCtr.end(); ++it) {
        delete it->second;
    }
    mapCtr.clear();
}

void Router::init(Request* request) {
    clear();

    // Add Checkout Controller
    CheckoutController* checoutCtr = new CheckoutController();
    registerRoute(Config::CMD_CHECKOUT, checoutCtr);

    // Add Return Controller
    ReturnController* returnCtr = new ReturnController();
    registerRoute(Config::CMD_RETURN, returnCtr);

    // Add History Controller
    HistoryController* historyCtr = new HistoryController();
    registerRoute(Config::CMD_HISOTRY, historyCtr);

    InitController initCtr;
    initCtr.exec(request);
}

void Router::go(Request* request) {
    mapCtr[request->get("command")]->exec(request);
}

void Router::registerRoute(string route, Controller* ctr) {
    mapCtr[route] = ctr;
}

