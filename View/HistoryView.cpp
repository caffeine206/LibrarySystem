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

HistoryView::HistoryView(ostream* o) : View::View(o) {}

void HistoryView::render(Request* request) {
    User* user = Users::fetchUser(request->get("user_id"));
    Histories& histories = user->getHistories();
    // Show user information
    *(this->out) << *(user);

    // Drawing the data
    for (list<Model*>::iterator it = histories.begin();
        it != histories.end(); ++it) {
        History* history = static_cast<History *>(*it);
        string cmd = history->getCommand();
        *(this->out)
             << left
             << setfill(' ') << setw(10)
             << ((cmd == Config::CMD_RETURN) ? "Return":
                (cmd == Config::CMD_CHECKOUT) ? "CheckOut" : "")
             << history->getBook();
    }
}
