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

#include "./BooksPeriodical.h"

BooksPeriodical& BooksPeriodical::getInstance() {
    // Auto destroyed Singleton
    static BooksPeriodical instance;
    return instance;
}

void BooksPeriodical::append(Periodical* book) {
    // Call superclass function
    Indexed::append(book);
}
