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
 * ArgumentRequest is a parser for argument requests that absorbs text
 * and passes the information onto the router.  It takes in a standardized form
 * of text.  
 */

#ifndef __ArgumentRequest_H
#define __ArgumentRequest_H

#include <sstream>
#include <iostream>

#include "./Request.h"

class ArgumentRequest : public Request {
  public:
    ArgumentRequest(); // Constructor
    ~ArgumentRequest(); // Destructor
    void parse(int argc, char** argv); // Parse an argument request
  protected:
};

#endif
