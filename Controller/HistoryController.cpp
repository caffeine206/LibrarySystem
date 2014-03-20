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
 * The HistoryController class is intended to handle history transaction requests.
 * It extends the Controller class with the functionality of being able to render
 * a collection of individual histories into standard output.  
 */

#include "./HistoryController.h"

HistoryController::HistoryController() {}

void HistoryController::exec(Request* request) 
// Execute a history request
{
    HistoryView historyView;
    historyView.setOstream(&cout);
    historyView.render(request); // output the request
}

