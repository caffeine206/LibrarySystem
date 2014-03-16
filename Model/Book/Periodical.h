/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * 
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

#ifndef __Periodical_H
#define __Periodical_H

#include "../Book.h"

class Periodical : public Book {
 public:
    Periodical();
    ~Periodical() {}
    void setMonth(int month);
    int getMonth() const;
    virtual string key() const;
    // virtual bool operator<(const Model & rhs) const;
    bool operator<(const Periodical & rhs) const;
    // Std:ostream Operator << overload
    virtual void print(ostream& out) const;
 protected:
    int month;
};

#endif
