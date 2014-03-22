/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
* View class is an output repeentaion of information.
 * This is an abstract class.
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

#include "./View.h"

View::View(ostream* o)
// Constructor to set defualt ostream
{
    setOstream(o);
}

void View::setOstream(ostream* o)
// Setter for ostream
{
    this->out = o;
}
