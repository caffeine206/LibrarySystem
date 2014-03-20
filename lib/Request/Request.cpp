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
 * Request is an abstract class that can be extended by command or argument 
 * requests.  It contains the basic functionality such as creating or deleting
 * a request, holding a set of requests, locating given requests, or reporting
 * the size of the request collection.  
 */

#include "./Request.h"

// Constructor
Request::Request() {}

// Destructor
Request::~Request() {}

string Request::get(const string key) const 
// Locates a given request by its key
// Returns the key if found, or an empty string if not found
{
    if ( key.empty() || requests.find(key) == requests.end() ) { // not found
        return "";
    } else { // found
        return requests.at(key);
    }
}

void Request::set(const string key, const string value) 
// Pre: If entry is not found, it does nothing
// Post: Locates a request entry and changes the value
{
    if (!key.empty()) {
        requests[key] = value;
    }
}

void Request::clear() 
// Destructor helper: deletes all request entries
{
    requests.clear();
}

int Request::size() 
// Returns the number of requests in the collection
{
    return requests.size();
}

