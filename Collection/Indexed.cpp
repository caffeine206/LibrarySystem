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

Indexed::Indexed() : need2Destruct(true) {}

Indexed::~Indexed() {
    if (need2Destruct) {
        for (modelSet::iterator it = setModels.begin();
            it != setModels.end(); ++it) {
            if (*it) {
                delete *it;
            }
        }
        setModels.clear();
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

Model* Indexed::find(const string key) const {
    if (key.empty()) {
        // TODO(Sota): Add error handling
        cerr << "ERROR: Indexed::find() Empty Key" << endl;
        return NULL;
    }

    modelMap::const_iterator it = mapModels.find(key);
    if (it == mapModels.end()) { // not found
        // TODO(Sota): Add error handling
        cerr << "ERROR: Indexed::find() Not found" << endl;
        return NULL;
    } else { // found
        return it->second;
    }
}

bool Indexed::remove(const string key) {
    modelMap::iterator it = mapModels.find(key);
    if ( key.empty() || it == mapModels.end() ) { // not found
        // TODO(Sota): Add error handling
        cerr << "ERROR: Indexed::remove() Invalid Key" << endl;
        return false;
    } else { // found
        setModels.erase(it->second);
        mapModels.erase(it);
        return true;
    }
}

modelSet::iterator Indexed::begin() const {
    return setModels.begin();
}

modelSet::iterator Indexed::end() const {
    return setModels.end();
}
