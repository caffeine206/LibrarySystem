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
    Books* fictionBooks = static_cast<Books *>(mapCollection["fiction"]);
    // Drawing the header
    this->headerFiction();
    // Drawing the data
    for (set<Model*>::iterator it = fictionBooks->begin();
        it != fictionBooks->end(); ++it) {
        this->draw(static_cast<Fiction *>(*it));
    }
}
