/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * The ReturnController class is intended to handle return transactions.
 * It extends the Controller class with the functionality of being able to 
 * execute a return request, validate a book and user, and then update
 * the user history and book collection to reflect the return.  
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

#include "./ReturnController.h"

// Constructor
ReturnController::ReturnController() {}

void ReturnController::exec(Request* request) 
// Execute a return request
// Pre: The book type, book, and user must be valid, else returns an error
// Post: Updates the user history, user, and book collection with the return
// transaction.  
{
    // Check the book type
    if (request->get("type") != Config::TYPE_HARDCOPY) {
        cerr << "ERROR: Checkout:: " // Invalid type
             << "Sorry, we don't have type ["
             << request->get("type")
             << "]." << endl
             << "Currently, we have only hardcopies.";
        return;
    }
    // Fetch user to see if it's a valid user
    User* user = Users::fetchUser(request->get("user_id"));
    if (!user) { // Invalid user
        // Todo: Error handling
        cerr << "ERROR: Checkout::" <<
        "Sorry, we coudn't find the user ["
        << request->get("user_id")
        << "]." << endl;
        return;
    }

    // Fetch a book
    Book* book = Books::fetchBook(request);
    if (!book) { // Invalid book
        cerr << "ERROR: Checkout:: "
             << "Sorry, we couldn't find the book." << endl;
        return;
    }

    if (!user->hasBook(book)) {
        cerr << "ERROR: Return:: " // User does not have book checked out
             << "Sorry, you cannot return a book that you don't have." << endl;
        return;
    }

    if (book->returnBook()) { // True if succeed
        // Get the command
        string command = request->get("command");
        user->addHistory(command, book); // Update history for user
        user->returnBook(book); // Remove book from user account
    } else {
        cerr << "ERROR: Return:: " // Checkout failed
             << "The book might not be ours."
             << "Please check it with our librarian" << endl;
        return;
    }
}

