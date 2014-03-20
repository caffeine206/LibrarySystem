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
 * BooksYouth is a collection of youth books.  
 */

#ifndef __BooksYouth_H
#define __BooksYouth_H

#include "./Books.h"
#include "../Model/Book/Youth.h"

class BooksYouth : public Books {
 public:
    static BooksYouth& getInstance(); // Initialize a youth book collection
    void append(Youth* book); // Add a youth book to the collection
 protected:
};

#endif
