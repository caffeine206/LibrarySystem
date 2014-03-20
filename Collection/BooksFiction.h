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
 * BooksFiction is a collection for storing all the fiction books in the system.
 */

#ifndef __BooksFiction_H
#define __BooksFiction_H

#include "./Books.h"
#include "../Model/Book/Fiction.h"

class BooksFiction : public Books {
 public:
    static BooksFiction& getInstance(); // Initialize a fiction book collection
    void append(Fiction* book); // Add a fiction book to the collection
 protected:
};

#endif
