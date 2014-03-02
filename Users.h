#ifndef __Users_H
#define __Users_H

#include "./Model.h"

class User : public Model {
  public:
    User(int library_id, string lastname,
         string firstname) {}

	Histories getHistories();  
  protected:
  	Histories hisotries;
};

#endif
