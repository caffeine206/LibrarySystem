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
 * BooksPeriodical is a collection of periodical books.  
 */

#ifndef __BooksPeriodical_H
#define __BooksPeriodical_H

#include "./Books.h"
#include "../Model/Book/Periodical.h"

class BooksPeriodical : public Books {
 public:
    static BooksPeriodical& getInstance(); // Initialize a periodical collection
    void append(Periodical* book); // Add a book to the periodical collection
 protected:
};

#endif
