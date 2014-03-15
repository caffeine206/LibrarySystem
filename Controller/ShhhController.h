#ifndef __ShhhController_H
#define __ShhhController_H

#include "./Controller.h"
#include "../Collection/Users.h"
#include "../Model/User.h"
#include "../Model/History.h"
#include "../Collection/BooksFiction.h"
#include "../Collection/BooksPeriodical.h"
#include "../Collection/BooksYouth.h"
#include "../Model/Book.h"

class ShhhController : public Controller {
  public:
  protected:
    User* fetchUser(string user_id);
};

#endif
