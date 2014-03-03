#ifndef __User_H
#define __User_H

#include "./Model.h"
#include "../Collection/Histories"

class User : public Model {
  public:
    User(int userId, string firstName, string lastName);
    Histories getHistories();
  protected:
    Histories histories;
};

#endif
