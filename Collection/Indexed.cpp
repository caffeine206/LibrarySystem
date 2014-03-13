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

#include "./Indexed.h"

Indexed::~Indexed() {
    for (modelSet::iterator it = setModels.begin();
        it != setModels.end(); ++it) {
        delete *it;
    }
}

void Indexed::append(Model* model) {
    mapModels[model->key()] = model;
    setModels.insert(model);
    this->n++;
}

modelSet Indexed::getModels() const {
    return setModels;
}

Model* Indexed::find(const string key) {
    return mapModels[key];
}

modelSet::iterator Indexed::begin() const {
    return setModels.begin();
}

modelSet::iterator Indexed::end() const {
    return setModels.end();
}
