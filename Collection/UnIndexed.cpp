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

#include "./UnIndexed.h"

UnIndexed::~UnIndexed() {
    for (modelList::iterator it = listModel.begin();
        it != listModel.end(); ++it) {
        delete *it;
    }
}

void UnIndexed::append(Model* model) {
    listModel.push_back(model);
    this->n++;
}

modelList UnIndexed::getModels() const {
    return listModel;
}

modelList::iterator UnIndexed::begin() {
    return listModel.begin();
}

modelList::iterator UnIndexed::end() {
    return listModel.end();
}
