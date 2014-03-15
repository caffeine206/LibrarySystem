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

NonPeriodical::NonPeriodical()
    :Book::Book(Config::HARDCOPY_NONPERIODICAL,
                Config::HARDCOPY_NONPERIODICAL) {
}

string NonPeriodical::getAuthor() const {
    return author;
}

void NonPeriodical::setAuthor(string str) {
    this->author = str;
}

string NonPeriodical::key() const {
    ostringstream out;
    out << this->author << this->title;
    return out.str();
}

void NonPeriodical::print(ostream& out) const {
    out << left
         << setfill(' ') << setw(Config::OUTPUT_WIDTH_AVAIL - 1)
         << this->getAvailableCount()
         << " "
         << left
         << setw(Config::OUTPUT_WIDTH_AUTHOR)
         << string(this->getAuthor()).substr(0, Config::OUTPUT_WIDTH_AUTHOR)
         << " "
         << left
         << setw(Config::OUTPUT_WIDTH_TITLE)
         << string(this->getTitle()).substr(0, Config::OUTPUT_WIDTH_TITLE)
         << " "
         << left
         << setw(Config::OUTPUT_WIDTH_YEAR)
         << this->getYear()
         << " "
         << endl;
}
