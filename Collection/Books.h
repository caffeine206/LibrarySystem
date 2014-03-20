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
 * Books represents a collection of book objects.
 */
#ifndef __Books_H
#define __Books_H

#include "./Indexed.h"
#include "../Model/Book.h"
#include "../lib/Request/Request.h"

class Books : public Indexed {
 public:
    static Books& getInstance(); // New book collection instance
    static Books& fetchBooks(string category); // Fetch all books in a category
    static Book* fetchBook(Request* request); // Fetch one book from the collection
 protected:
};

#endif
