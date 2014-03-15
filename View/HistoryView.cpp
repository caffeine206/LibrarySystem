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
#include <list>
#include "./HistoryView.h"

void HistoryView::render(Request* request) {
    User* user = Users::fetchUser(request->get("user_id"));
    Histories& histories = user->getHistories();

    *(this->out) << "HistoryView!" << endl;

    *(this->out) << endl
                 << "*** Patron ID = "
                 << left
                 << setfill('0') << setw(4)
                 << user->getID() << " "
                 << user->getFirstName()
                 << user->getLastName()
                 << endl;

    // Drawing the data
    for (list<Model*>::iterator it = histories.begin();
        it != histories.end(); ++it) {
        History* history = static_cast<History *>(*it);

        *(this->out) << "| "
             << left
             << setfill(' ') << setw(12)
             << request->get("command")
             << history->getBook();
    }
}
