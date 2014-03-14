#ifndef __TextView_H
#define __TextView_H

#include <iostream>
#include <iomanip>  //setw, setFill,
#include "./View.h"

class TextView : public View{
  public:
    virtual void render();
  protected:
    // Helper function for displaying a raw of a book information.
    // The reason why we are not overriding operator<< for each class is
    // because we do not want to implement any view related tasks in
    // a Model class as it violates MVC design principles.
    // Thus, any output related implementation should be in View.
    void toStringFiction(ostream& out, const Fiction* book) const;
    void toStringYouth(ostream& out, const Youth* book) const;
    void toStringPeriodial(const Fiction* fiction) const;
};

#endif
