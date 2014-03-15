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

#include "./Request.h"

Request::Request() {}

Request::~Request() {}

string Request::get(const string key) const {
    if (key.size() > 0) {
        return requests.at(key);
    } else {
        // TODO(Sota): Add error handling
        cerr << "ERROR: Request::get(string) Invalid Key" << endl;
        return "";
    }
}

void Request::set(const string key, const string value) {
    if (key.size() > 0) {
        requests[key] = value;
    } else {
        // TODO(Sota): Add error handling
        cerr << "ERROR: Request::get(string) Invalid Key" << endl;
    }
}

void Request::clear() {
    requests.clear();
}

int Request::size() {
    return requests.size();
}

