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
 * Controller is an abstract class that can be extended by checkout or
 * return controllers, for example.  It is intended to process transactions
 * of different types.  It includes the basic functionality of constructing and
 * destructing a controller, and executing a transaction.  
 */

#ifndef __Controller_H
#define __Controller_H

#include "../lib/Config.h"
#include "../lib/Request/CommandRequest.h"
#include "../Model/User.h"
#include "../Model/Book.h"
#include "../Collection/Users.h"
#include "../Collection/BooksFiction.h"
#include "../Collection/BooksPeriodical.h"
#include "../Collection/BooksYouth.h"

using namespace std;

class Controller {
  public:
    Controller(); // Constructor
    virtual ~Controller(); // Destructor
    virtual void exec(Request* request) = 0; // Execute a transaction.
  protected:
};

#endif
