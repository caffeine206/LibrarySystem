#ifndef __IncorrectCommandException_H
#define __IncorrectCommandException_H

#include <exception>

class IncorrectCommandException: public exception
{
  virtual const char* what() const throw()
  {
    return "IncorrectCommandException happened";
  }
} IncorrectCommandException;


#endif
