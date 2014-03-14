#ifndef __TextView_H
#define __TextView_H

#include <iostream>
#include "./View.h"
#include "../Model/Book/Fiction.h"
#include "../Model/Book/Youth.h"
#include "../Model/Book/Periodical.h"
#include "../Model/History.h"

class TextView : public View {
  public:
    virtual ~TextView() {}
    virtual void render() {}
    
    // Helper function for displaying a raw of a book information.
    // The reason why we are not overriding operator<< for each class is
    // because we do not want to implement any view related tasks in
    // a Model class as it violates MVC design principles.
    // Thus, any output related implementation should be in View.
    void headerFiction() const;
    void headerPeriodical() const;
    void headerYouth() const;
    void headerHistory() const;
    void draw(const Fiction* book) const;
    void draw(const Youth* book) const;
    void draw(const Periodical* book) const;
    void draw(const History* history) const;
  protected:
};

#endif
