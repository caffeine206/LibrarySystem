#ifndef __Controller_H
#define __Controller_H

using namespace std;

class Controller {
  public:
  Controller(string command):info(command);
  virtual void exec();
  
  protected:
  string info;
};

#endif
