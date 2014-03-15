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

#include "./BooksFiction.h"

BooksFiction& BooksFiction::getInstance() {
    // Auto destroyed Singleton
    static BooksFiction instance;
    return instance;
}

void BooksFiction::append(Fiction* book) {
    // Call superclass function
    Indexed::append(book);
}
