#ifndef __BookController_H
#define __BookController_H

#include "./ShhhController.h"

class BookController : public ShhhController {
  public:
  protected:
    Book* fetchBook(Request* request);
    void updateHistory(char command, User* user, Book* book);
};

#endif
