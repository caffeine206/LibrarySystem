/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * BooksFiction <singleton> is a collection for storing all the fiction 
 * books in the system.
 * It includes the functionality of adding a fiction book into the system.  
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

#include "./BooksFiction.h"

BooksFiction& BooksFiction::getInstance() 
// Create a static instance of a fiction book collection
{
    // Auto destroyed Singleton
    static BooksFiction instance;
    return instance;
}

void BooksFiction::append(Fiction* book) 
// Adds a book to the fiction book collection
{
    // Call superclass function
    Indexed::append(book);
}
