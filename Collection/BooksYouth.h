#ifndef __BooksYouth_H
#define __BooksYouth_H

#include "./Books.h"
#include "../Model/Book/Youth.h"

class BooksYouth : public Books {
 public:
    static BooksYouth& getInstance();
    void append(Youth* book);
 protected:
};

#endif
