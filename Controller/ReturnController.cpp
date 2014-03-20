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

#include "./ReturnController.h"

ReturnController::ReturnController() {}

void ReturnController::exec(Request* request) {
    // Check the book type
    if (request->get("type") != Config::TYPE_HARDCOPY) {
        cerr << "ERROR: Checkout:: "
             << "Sorry, we don't have type ["
             << request->get("type")
             << "]." << endl
             << "Currently, we have only hardcopies.";
        return;
    }
    // Fetch user to see if it's a valid user
    User* user = Users::fetchUser(request->get("user_id"));
    if (!user) {
        // Todo: Error handling
        cerr << "ERROR: Return::" <<
        "Sorry, we coudn't find the user ["
        << request->get("user_id")
        << "]." << endl;
        return;
    }

    // Fetch a book
    Book* book = Books::fetchBook(request);
    if (!book) {
        cerr << "ERROR: Return:: "
             << "Sorry, we couldn't find the book." << endl;
        return;
    }

    if (!user->hasBook(book)) {
        cerr << "ERROR: Return:: "
             << "Sorry, you cannot return a book that you don't have." << endl;
        return;
    }

    if (book->returnBook()) { // True if succeed
        // Get the command
        string command = request->get("command");
        user->addHistory(command, book);
        user->returnBook(book);
    } else {
        cerr << "ERROR: Checkout:: "
             << "Sorry, we couldn't process the return."
             << "Please try it again later." << endl;
        return;
    }
}

