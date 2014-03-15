#ifndef __BooksFiction_H
#define __BooksFiction_H

#include "./Books.h"
#include "../Model/Book/Fiction.h"

class BooksFiction : public Books {
 public:
    static BooksFiction& getInstance();
    void append(Fiction* book);
 protected:
};

#endif
