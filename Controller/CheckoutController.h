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
 * CheckoutController is a controller class designed to take care of the
 * process of a user checking out books from the library.  It includes
 * the basic functionality of taking in a request, validating the user
 * and book, and updating the system with the checkout.  
 */

#ifndef __CheckoutController_H
#define __CheckoutController_H

#include "./Controller.h"

class CheckoutController : public Controller {
  public:
    CheckoutController(); // Constructor
    void exec(Request* request); // Execute checkout and update system
  protected:
};

#endif
