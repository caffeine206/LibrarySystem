#ifndef __Books_H
#define __Books_H

#include "./Indexed.h"
#include "../Model/Book.h"
#include "../lib/Request/Request.h"

class Books : public Indexed {
 public:
    static Books& getInstance();
    static Books& fetchBooks(string category);
    static Book* fetchBook(Request* request);
 protected:
};

#endif
