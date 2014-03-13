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

#include "./User.h"

void User::setID(int id) {
    this->ID = id;
}

int User::getID() {
    return this->ID;
}

void User::setName(string first, string last) {
    this->firstName = first;
    this->lastName = last;
}

string User::getFirstName() {
    return this->firstName;
}

string User::getLastName() {
    return this->lastName;
}

Histories& User::getHistories() {
    return this->histories;
}
void User::addHistory(History* history) {
    this->histories.append(history);
}

string User::key() {
    ostringstream out;
    out << this->ID;
    return out.str();
}