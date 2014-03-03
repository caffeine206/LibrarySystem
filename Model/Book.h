#ifndef __Book_H
#define __Book_H

#include "./Model.h"

class Book : public Model {
 public:
    Book(string author, string title,
         string categoryID, int month, int year, int available, int copies);
  bool isBookAvailable();
  bool checkout();
 protected:
};

#endif
