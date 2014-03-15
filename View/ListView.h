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

#ifndef __ListView_H
#define __ListView_H

#include "./TextView.h"
#include "../Collection/BooksFiction.h"
#include "../Collection/BooksPeriodical.h"
#include "../Collection/BooksYouth.h"

class ListView : public TextView {
  public:
    void render();
  protected:
};

#endif
