#ifndef __Books_H
#define __Books_H

#include "./Indexed.h"
#include "../Model/Book.h"

class Books : public Indexed {
 public:
    void append(Book* model);
 protected:
};

#endif
