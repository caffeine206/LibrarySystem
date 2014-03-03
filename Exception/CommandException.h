#ifndef __CommandException_H
#define __CommandException_H

#include <exception>

class CommandException: public exception
{
  virtual const char* what() const throw()
  {
    return "CommandException happened";
  }
} CommandException;


#endif
