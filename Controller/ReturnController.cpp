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
    // Fetch user to see if it's a valid user
    User* user = Users::fetchUser(request->get("user_id"));
    if (!user) {
        // Todo: Error handling
        cerr << "ERROR: ReturnController::exec() USER NOT FOUND" << endl;
        return;
    }

    // Fetch a book
    Book* book = Books::fetchBook(request);
    if (!book) {
        // Todo: Error handling
        cerr << "ERROR: ReturnController::exec() BOOK NOT FOUND" << endl;
        return;
    }

    if (book->returnBook()) { // True if succeed
        // Get the command
        string command = request->get("command");
        user->addHistory(command, book);
    } else {
        // Todo: Error handling
        cerr << "ERROR: ReturnController::exec() RETURN FAILD" << endl;
        return;
    }
}

