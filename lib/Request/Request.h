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

#ifndef __Request_H
#define __Request_H

#include <iostream>
#include <string>
#include <map>
#include "../Config.h"

using namespace std;

class Request {
  public:
    Request(); // Constructor
    virtual ~Request(); // Destructor
    // Returns the value associated with the key
    virtual string get(const string key) const;
    // Set the value associated with the key
    virtual void set(const string key, const string value);
    // Clears the map
    virtual void clear();
    // Returns the # of elements
    virtual int size();
    // number of commands
  protected:
    map<string, string> requests; // Request collection
};

#endif
