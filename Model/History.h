#ifndef __History_H
#define __History_H

#include "./Model.h"

class History : public Model {
  public:
    History(string command, int user_id, int category_id, int book_id);
  protected:
};

#endif
