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

#include "./Model.h"

// Standard output for model
ostream& operator<< (ostream& out, const Model& model) {
    model.print(out);
    return out;
}

// Standard comparison for sorting
bool Model::operator<(const Model & rhs) const {
    return true;
}
