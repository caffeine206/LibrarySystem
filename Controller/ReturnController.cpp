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
 *
 * The ReturnController class is intended to handle return transactions.
 * It extends the Controller class with the functionality of being able to 
 * execute a return request, validate a book and user, and then update
 * the user history and book collection to reflect the return.  
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
        cerr << "ERROR: Return::" <<
        "Sorry, we coudn't find the user ["
        << request->get("user_id")
        << "]." << endl;
        return;
    }

    // Fetch a book
    Book* book = Books::fetchBook(request);
    if (!book) { // Invalid book
        cerr << "ERROR: Return:: "
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
        cerr << "ERROR: Checkout:: " // Checkout failed
             << "Sorry, we couldn't process the return."
             << "Please try it again later." << endl;
        return;
    }
}

