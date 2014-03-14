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

void View::setCollection(string key, Collection* collection) {
    clMap[key] = collection;
}
void View::setOstream(ostream* o) {
    out = o;
}

