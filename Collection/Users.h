#ifndef __Users_H
#define __Users_H

#include "./Indexed.h"

class Users : public Indexed {
  public:
  Users();
  virtural void apend(Model&);
  bool isValidUser()
  protected:
};

#endif
