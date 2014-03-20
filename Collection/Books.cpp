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
 * Books represents a collection of book objects, organized by a unique key for
 * every given book.  It includes functionality for fetching all the books in the
 * system for a given category, or to find a single given book.  
 */

#include "./Books.h"
#include "./BooksFiction.h"
#include "./BooksPeriodical.h"
#include "./BooksYouth.h"

Books& Books::getInstance() 
// Initializes a static instance of a book collection
{
    // Auto destroyed Singleton
    static Books instance;
    return instance;
}

Books& Books::fetchBooks(string category) 
// Pre: Letter must represent a category of book included in the library system,
// else returns an invalid category error
// Post: Returns the entire collection of books for a given category
{
    if (category == Config::CAT_PERIODICAL) { // Periodical
        return static_cast<Books &>(BooksPeriodical::getInstance());
    } else if (category == Config::CAT_YOUTH) { // Youth
        return static_cast<Books &>(BooksYouth::getInstance());
    } else if (category == Config::CAT_FICTION) { // Fiction
        return static_cast<Books &>(BooksFiction::getInstance());
    }

    // Todo: Error handling for bookKey
    cerr << "ERROR: Books::fetchBooks INVALID CATEGORY" << endl;
    // Return a reference to a empty books
    return Books::getInstance();
}

Book* Books::fetchBook(Request* request) 
// Pre: Book request must be valid, else returns invalid book key error
// Post: Returns the book specified in the request from the current collection
// in the system
{
    // Get cateogory
    string category = request->get("category");

    Books& books = Books::fetchBooks(category);

    // Get cateogory
    string bookKey;
    if (category == Config::CAT_PERIODICAL) { // Periodical
        bookKey = request->get("year");
        bookKey += request->get("month");
        bookKey += request->get("title");
    } else {
        bookKey = request->get("author");
        bookKey += request->get("title");
    }

    if (bookKey.size() == 0) {
        // Todo: Error handling for bookKey
        cerr << "ERROR: ReturnController::exec() INVALID BOOK KEY" << endl;
        return NULL;
    }

    // Look for the book
    Book* book = static_cast<Book *>(books.find(bookKey));
    if (!book) {
        // Todo: Error handling for bookKey
        cerr << "ERROR: ReturnController::exec() INVALID BOOK" << endl;
        return NULL;
    }
    return book;
}

