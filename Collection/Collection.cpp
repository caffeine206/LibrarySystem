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

#include "./Collection.h"

Collection::Collection() {
}

Collection::~Collection() {
    for (modelSet::iterator it = setModels.begin();
        it != setModels.end(); ++it) {
        delete *it;
    }
}

void Collection::append(Model* model) {
    mapModels.insert(modelPair(model->key(), model));
    setModels.insert(model);
    n++;
}

int Collection::size() {
    return n;
}


modelSet Collection::getModels() {
    return setModels;
}

Model* Collection::find(string) {
    return NULL;
}
