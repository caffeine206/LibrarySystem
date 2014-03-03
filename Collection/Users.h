#ifndef __Users_H
#define __Users_H

#include "./Collection.h"

class Users : public Collection {
  public:
  Users();
  virtural void apend(Model&);
  bool isValidUser()
  protected:
};

#endif
