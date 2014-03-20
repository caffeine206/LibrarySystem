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
 * The CommandRequest class extends the request class with the basic
 * functionality of being able to parse commands, such as checkout or
 * return.  
 */

#ifndef __CommandRequest_H
#define __CommandRequest_H

#include <sstream>
#include <iostream>

#include "./Request.h"

class CommandRequest : public Request {
  public:
    CommandRequest(); // Constructor
    virtual ~CommandRequest(); // Destructor
    virtual void parse(string cmd); // Parse a command
  protected:
};

#endif
