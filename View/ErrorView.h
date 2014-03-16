#ifndef __ErrorView_H
#define __ErrorView_H

#include "./View.h"

class ErrorView : public View {
  public:
    virtual void render(Request* request = NULL);
  protected:
};

#endif
