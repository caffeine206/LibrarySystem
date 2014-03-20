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
 * The InitController class is intended to initialize the library system from
 * external input.  It extends the Controller class with the functionality of 
 * parsing data from a standardized input text file, and then intializing
 * the library system.  
 */

#ifndef __InitController_H
#define __InitController_H

#include "./Controller.h"

class InitController : public Controller {
  public:
    InitController(); // Constructor
    void exec(Request* request); // Execute an initialization request
  protected:
};

#endif
