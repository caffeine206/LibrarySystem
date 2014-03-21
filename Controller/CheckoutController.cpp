/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * CheckoutController is a controller class designed to take care of the
 * process of a user checking out books from the library.  It includes
 * the basic functionality of taking in a request, validating the user
 * and book, and updating the system with the checkout.  
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 *
 */

#include "./CheckoutController.h"

// Constructor
CheckoutController::CheckoutController() {}

void CheckoutController::exec(Request* request) 
// Pre: Book type, user, and book must be valid, else returns error
// Post: Validates the book type, user, and book, and then updates
// the user history and book with the transaction.  
{
    // Check the book type
    if (request->get("type") != Config::TYPE_HARDCOPY) { // type is invalid
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
        cerr << "ERROR: Checkout:: " // user does not exist
             << "Sorry, we couldn't find the user ["
             << request->get("user_id") << "]." << endl;
        return;
    }

    // Fetch a book
    Book* book = Books::fetchBook(request);
    if (!book) { // book is invalid
        cerr << "ERROR: Checkout:: "
             << "Sorry, we couldn't find the book." << endl;
        return;
    }

    if (user->hasBook(book)) { // user already has book checked out
        cerr << "ERROR: Checkout:: "
             << "Sorry, you cannot checkout the same book twice." << endl;
        return;
    }

    if (book->checkout()) { // True if succeed
        // Get the command
        string command = request->get("command");
        user->addHistory(command, book); // add transaction to history
        user->addBook(book); // add book to user history
    } else {
        cerr << "ERROR: Checkout:: "
             << "Sorry, the book is currently not avalable."
             << endl;
        return;
    }
}
