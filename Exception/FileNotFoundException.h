#ifndef __FileNotFoundException_H
#define __FileNotFoundException_H

#include <exception>

class FileNotFoundException: public exception
{
  virtual const char* what() const throw()
  {
    return "FileNotFoundException happened";
  }
} FileNotFoundException;


#endif
