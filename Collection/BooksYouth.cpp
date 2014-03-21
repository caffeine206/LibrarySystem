/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * BooksYouth <singleton> is a collection of youth books.
 * It includes the functionality of adding a book to the youth collection.  
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

#include "./BooksYouth.h"

BooksYouth& BooksYouth::getInstance()
// Initialize a static instance of a youth collection
{
    // Auto destroyed Singleton
    static BooksYouth instance;
    return instance;
}

void BooksYouth::append(Youth* book)
// Add a youth book to the youth collection
{
    // Call superclass function
    Indexed::append(book);
}
