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

#include "./InitialView.h"
#include "../lib/Router.h"

InitialView::InitialView(ostream* o) : View::View(o) {}

void InitialView::render(Request* request) {
    this->welcome();
    Router& router = Router::getInstance();
    CommandRequest commandRequest;
    string line;
    while (getline(cin, line)) {
        commandRequest.parse(line);
        router.go(&commandRequest);
    }
}

void InitialView::welcome() {
    *(this->out)  << endl
                  << right
                  << setfill('*') << setw(80) 
                  << "*"
                  << endl
                  << left
                  << setfill('*') << setw(20)
                  << "*"
                  << left
                  << setfill('*') << setw(60)
                  << "   WELCOME TO SHHH LIBRARY SYSTEM!!   "
                  << endl
                  << left
                  << setfill('*') << setw(80)
                  << "*"
                  << endl;
}
