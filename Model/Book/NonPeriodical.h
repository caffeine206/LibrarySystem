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
 * NonPeriodical extends book by adding information unique to nonperiodicals,
 * such as an author, and a different way of storing and outputting information
 * about the periodical.
 */

#ifndef __NonPeriodical_H
#define __NonPeriodical_H

#include "../Book.h"

class NonPeriodical : public Book {
 public:
    // Constructor
    NonPeriodical();

    // Getter functions
    virtual string getAuthor() const;

    // Setter functions
    virtual void setAuthor(string str);

    virtual bool operator<(const Model & rhs) const {return true;}

    // Returns a type of the class
    virtual string typeOf() const;
 protected:
    string author; // Author of nonperiodical
};

#endif
