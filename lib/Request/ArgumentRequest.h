#ifndef __ArgumentRequest_H
#define __ArgumentRequest_H

#include <sstream>
#include <iostream>

#include "./Request.h"

class ArgumentRequest : public Request {
  public:
    ArgumentRequest();
    ~ArgumentRequest();
    void parse(int argc, char** argv);
  protected:
};

#endif
