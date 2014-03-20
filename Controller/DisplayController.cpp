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

#include "./DisplayController.h"

// Constructor
DisplayController::DisplayController() {}

void DisplayController::exec(Request* request) 
// Executes a output request
{
    // Create list view
    ListView listView(&cout);
    listView.render(request); // output the request
}

