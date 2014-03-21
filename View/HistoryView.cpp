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
#include <set>
#include "./HistoryView.h"

HistoryView::HistoryView(ostream* o) : View::View(o) {}

void HistoryView::render(Request* request) {
    User* user = Users::fetchUser(request->get("user_id"));

    if (!user) {
        cerr << "ERROR: History:: "
             << "Sorry, we couldn't find the user ["
             << request->get("user_id") << "]." << endl;
        return;
    }

    // Show user information
    *(this->out) << *(user) << endl;

    Books& books = user->getBooks();
    if (books.size() == 0) {
        *(this->out)
            << "The patron currently does not have any books." << endl;
    } else {
        *(this->out) << "Following items are currently checked out:" << endl;
    }

    // Drawing the data
    for (set<Model*>::iterator it = books.begin();
        it != books.end(); ++it) {
        Book* book = static_cast<Book *>(*it);
        *(this->out) << *(book);
    }

    Histories& histories = user->getHistories();

    *(this->out) << endl << "Patron History:" << endl;

    if (histories.size() == 0) {
        *(this->out)
            << "The patron currently does not have any history." << endl;
    } else {
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
}
