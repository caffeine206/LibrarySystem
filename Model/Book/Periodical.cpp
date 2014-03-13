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

#include "./Periodical.h"

Periodical::Periodical() {
}

void Periodical::setMonth(int month) {
    this->month = month;
}

int Periodical::getMonth() {
    return month;
}

string Periodical::key() {
    char buffer [255];
    snprintf ( buffer, sizeof(buffer), "%d%d", this->month, this->year);
    string key(buffer);
    key = this->title + key;
    return key;
}
