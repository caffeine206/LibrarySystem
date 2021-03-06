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
 * Fiction is a type of book included in the SHHH library system.
 */

#ifndef __Fiction_H
#define __Fiction_H

#include "./NonPeriodical.h"

class Fiction : public NonPeriodical {
 public:
    virtual void print(ostream& out) const; // Output for fiction books
    virtual bool operator<(const Model & rhs) const; // Book comparison
    virtual string key() const; // Unique key for the Fiction

    // Returns a type of the class
    virtual string typeOf() const;
 protected:
};

#endif
