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
 * The ReturnController class is intended to handle return transactions.
 * It extends the Controller class with the functionality of being able to 
 * execute a return request, validate a book and user, and then update
 * the user history and book collection to reflect the return.  
 */

#ifndef __ReturnController_H
#define __ReturnController_H

#include "./Controller.h"

class ReturnController : public Controller {
  public:
    ReturnController(); // Constructor
    void exec(Request* request); // Execute a return request
  protected:
};

#endif
