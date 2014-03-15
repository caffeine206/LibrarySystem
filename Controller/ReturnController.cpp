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
    User* user = this->fetchUser(request->get("user_id"));
    // Fetch a book
    Book* book = this->fetchBook(request);
    if (book && book->returnBook()) { // True if succeed
        // Get the command
        string command = request->get("command");
        this->updateHistory(command[0], user, book);
    }
}

