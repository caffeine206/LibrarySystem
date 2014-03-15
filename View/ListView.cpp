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

#include <set>
#include "./ListView.h"

void ListView::render() {
    // Fiction rendering
    BooksFiction& booksFiction = BooksFiction::getInstance();
    // Drawing the header
    this->headerFiction();
    // Drawing the data
    for (set<Model*>::iterator it = booksFiction.begin();
        it != booksFiction.end(); ++it) {
        this->draw(static_cast<Fiction *>(*it));
    }
}
