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
 * 
 * Periodical is a type of book included in the SHHH library system.
 */

#ifndef __Periodical_H
#define __Periodical_H

#include "../Book.h"

class Periodical : public Book {
 public:
    Periodical();
    void setMonth(int month); // Assigns month for periodical
    int getMonth() const; // Returns month of periodical
    virtual string key() const; // Unique key for the periodical
    // virtual bool operator<(const Model & rhs) const;
    virtual bool operator<(const Model & rhs) const; // Book comparison
    // Std:ostream Operator << overload
    virtual void print(ostream& out) const; // Output for periodical books
 protected:
    int month;
};

#endif
