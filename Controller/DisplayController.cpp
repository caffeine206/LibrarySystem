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
 */

#include "./DisplayController.h"

DisplayController::DisplayController() {}

void DisplayController::exec(Request* request) {
    // Create list view
    ListView listView(&cout);
    listView.render(request);
}

