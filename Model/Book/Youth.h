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
 * Youth is a type of book included in the SHHH library system.
 */

#ifndef __Youth_H
#define __Youth_H

#include "./NonPeriodical.h"

class Youth : public NonPeriodical {
 public:
    virtual void print(ostream& out) const; // Output for youth books
    virtual bool operator<(const Book & rhs) const; // Book comparison
 protected:
};

#endif
