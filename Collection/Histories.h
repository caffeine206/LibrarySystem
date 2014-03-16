#ifndef __Histories_H
#define __Histories_H

#include "./UnIndexed.h"
#include "../Model/History.h"

class Histories : public UnIndexed {
  public:
    // Insert function for collection
    void append(History* model);
  protected:
};

#endif
