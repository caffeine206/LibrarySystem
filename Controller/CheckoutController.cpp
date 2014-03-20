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

#include "./CheckoutController.h"

CheckoutController::CheckoutController() {}

void CheckoutController::exec(Request* request) {
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
        cerr << "ERROR: Checkout:: "
             << "Sorry, we couldn't find the user ["
             << request->get("user_id") << "]." << endl;
        return;
    }

    // Fetch a book
    Book* book = Books::fetchBook(request);
    if (!book) {
        cerr << "ERROR: Checkout:: "
             << "Sorry, we couldn't find the book." << endl;
        return;
    }

    if (user->hasBook(book)) {
        cerr << "ERROR: Checkout:: "
             << "Sorry, you cannot checkout the same book twice." << endl;
        return;
    }

    if (book->checkout()) { // True if succeed
        // Get the command
        string command = request->get("command");
        user->addHistory(command, book);
        user->addBook(book);
    } else {
        cerr << "ERROR: Checkout:: "
             << "Sorry, we couldn't process the checkout."
             << "Please try it again later." << endl;
        return;
    }
}
