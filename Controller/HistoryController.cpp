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

#include "./HistoryController.h"

HistoryController::HistoryController() {}

void HistoryController::exec(Request* request) {
    HistoryView historyView;
    historyView.setOstream(&cout);
    historyView.render(request);
}

