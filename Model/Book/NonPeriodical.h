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

#ifndef __NonPeriodical_H
#define __NonPeriodical_H

#include "../Book.h"

class NonPeriodical : public Book {
 public:
    NonPeriodical();
    string getAuthor();
 protected:
    int author;
};

#endif
