#ifndef __BooksPeriodical_H
#define __BooksPeriodical_H

#include "./Books.h"
#include "../Model/Book/Periodical.h"

class BooksPeriodical : public Books {
 public:
    static BooksPeriodical& getInstance();
    void append(Periodical* book);
 protected:
};

#endif
