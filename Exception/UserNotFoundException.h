#ifndef __UserNotFoundException_H
#define __UserNotFoundException_H

#include <exception>

class UserNotFoundException: public exception
{
  virtual const char* what() const throw()
  {
    return "UserNotFoundException happened";
  }
} UserNotFoundException;

#endif
