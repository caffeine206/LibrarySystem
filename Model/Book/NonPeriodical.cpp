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

#include "./NonPeriodical.h"

NonPeriodical::NonPeriodical() :
    availableCount(Config::HARDCOPY_NONPERIODICAL),
    hardCopyCount(Config::HARDCOPY_NONPERIODICAL) {
}

string NonPeriodical::getAuthor() {
    return author;
}

void NonPeriodical::setAuthor(string str) {
    this->author = str;
}

string NonPeriodical::key() {
    ostringstream out;
    out << this->author << this->title << this->year;
    return out.str();
}
