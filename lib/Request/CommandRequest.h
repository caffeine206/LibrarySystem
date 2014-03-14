#ifndef __CommandRequest_H
#define __CommandRequest_H

#include <sstream>
#include <iostream>

#include "./Request.h"

class CommandRequest : public Request {
  public:
    CommandRequest();
    virtual ~CommandRequest();
    virtual void parse(string cmd);
  protected:
};

#endif
