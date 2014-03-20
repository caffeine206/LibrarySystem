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
 * The DisplayController class is intended to handle output requests.  It extends
 * the controller class with the functionality of rendering a list view for different
 * collections.  
 */


#ifndef __DisplayController_H
#define __DisplayController_H

#include "./Controller.h"
#include "../View/ListView.h"

class DisplayController : public Controller {
  public:
    DisplayController(); // Constructor
    void exec(Request* request); // Executes an output request

  protected:
};

#endif
