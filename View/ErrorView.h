#ifndef __ErrorView_H
#define __ErrorView_H

class ErrorView : public TextView {
  public:
    virtual void render(Request* request = NULL);
  protected:
};

#endif
