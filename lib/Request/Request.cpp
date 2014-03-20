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
    if ( key.empty() || requests.find(key) == requests.end() ) { // not found
        return "";
    } else { // found
        return requests.at(key);
    }
}

void Request::set(const string key, const string value) {
    if (!key.empty()) {
        requests[key] = value;
    }
}

void Request::clear() {
    requests.clear();
}

int Request::size() {
    return requests.size();
}

