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

#include "./BookController.h"

Book* BookController::fetchBook(Request* request) {
    // Get cateogory
    string category = request->get("category");
    if (!clMap[category]) {
        // Todo: Error handling for category
        cerr << "ERROR: ReturnController::exec() INVALID CATEGORY ID" << endl;
        return NULL;
    }
    Books* books = static_cast<Books *>(clMap[category]);

    // Get cateogory
    string bookKey;
    if (category == "P") { // Periodical
        bookKey = request->get("year");
        bookKey += request->get("month");
        bookKey += request->get("title");
    } else {
        bookKey = request->get("title");
        bookKey += request->get("author");
    }
    if (bookKey.size() == 0) {
        // Todo: Error handling for bookKey
        cerr << "ERROR: ReturnController::exec() INVALID BOOK KEY" << endl;
        return NULL;
    }
    // Look for the book
    Book* book = static_cast<Book *>(books->find(bookKey));
    if (!book) {
        // Todo: Error handling for bookKey
        cerr << "ERROR: ReturnController::exec() INVALID BOOK" << endl;
        return NULL;
    }
    return book;
}

void BookController::updateHistory(char command, User* user, Book* book) {
    // Create History
    History* history = new History();
    history->setCommand(command);
    history->setBook(book);
    // Add a history to user
    user->addHistory(history);
}
