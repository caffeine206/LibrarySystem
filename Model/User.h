#ifndef __User_H
#define __User_H

#include "./Model.h"

class User : public Model {
  public:
    User(int ID, string firstName, string lastName);
    getHistories();
  protected:
    histories Histories;
};

#endif
