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

#include "./View.h"

View::View() {}
View::~View() {}

View::View(ostream* o) {
    setOstream(o);
}

void View::setOstream(ostream* o) {
    this->out = o;
}
