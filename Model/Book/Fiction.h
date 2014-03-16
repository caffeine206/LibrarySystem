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

#ifndef __Fiction_H
#define __Fiction_H

#include "./NonPeriodical.h"

class Fiction : public NonPeriodical {
 public:
    virtual void print(ostream& out) const;
 protected:
};

#endif
