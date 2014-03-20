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
 * BooksPeriodical is a collection of periodical books.  It includes
 * the functionality of adding a book to the periodical collection.  
 */

#include "./BooksPeriodical.h"

BooksPeriodical& BooksPeriodical::getInstance() 
// Create a static instance of a periodical book collection
{
    // Auto destroyed Singleton
    static BooksPeriodical instance;
    return instance;
}

void BooksPeriodical::append(Periodical* book) 
// Add a periodical to the book collection
{
    // Call superclass function
    Indexed::append(book);
}
