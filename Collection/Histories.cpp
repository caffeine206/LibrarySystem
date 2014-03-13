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

#include "./Histories.h"

Histories::~Histories() {
    for (modelList::iterator it = listModel.begin();
        it != listModel.end(); ++it) {
        delete *it;
    }
}

void Histories::append(Model* model) {
    listModel.push_back(model);
    this->n++;
}

modelList Histories::getModels() const {
    return listModel;
}

modelList::iterator Histories::begin() {
    return listModel.begin();
}

modelList::iterator Histories::end() {
    return listModel.end();
}
