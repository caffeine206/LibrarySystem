
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

Router::Router() {
    init();
}

Router::~Router() {
    for (collectoinMap::iterator it = mapCtr.begin(); it != mapCtr.end(); ++it)
        delete it->second;
}

void Router::init() {
    mapCtr.clear();
    mapCtr[Config::CMD_CHECKOUT] = new CheckOutController();
    mapCtr[Config::CMD_RETURN] = new ReturnController();
    mapCtr[Config::CMD_HISOTRY] = new HistoryController();
}

bool Router::go(Request* request) {
    mapCtr[route]->exec(request);
}

void Router::registerRoute(string route, Controller* ctr) {
    mapCtr[route] = ctr;
}

