#ifndef __Controller_H
#define __Controller_H

#include "../lib/Config.h"
#include "../lib/Request/CommandRequest.h"
#include "../Model/User.h"
#include "../Model/Book.h"
#include "../Collection/Users.h"
#include "../Collection/BooksFiction.h"
#include "../Collection/BooksPeriodical.h"
#include "../Collection/BooksYouth.h"

using namespace std;

class Controller {
  public:
    Controller();
    virtual ~Controller();
    virtual void exec(Request* request) = 0;
  protected:
};

#endif
