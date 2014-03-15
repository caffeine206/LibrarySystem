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

Periodical::Periodical()
    :Book::Book(Config::HARDCOPY_NONPERIODICAL,
                Config::HARDCOPY_NONPERIODICAL) {
}

void Periodical::setMonth(int month) {
    this->month = month;
}

int Periodical::getMonth() const {
    return month;
}

string Periodical::key() const {
    ostringstream out;
    out << this->year << this->month << this->title;
    return out.str();
}

bool Periodical::operator<(const Periodical & rhs) const {
    if (this->year < rhs.year) {
        return true;
    } else if (this->year == rhs.year) {
        if (this->month < rhs.month) {
            return true;
        } else if (this->title < rhs.title) {
            return true;
        }
    }
    return false;
}

void Periodical::print(ostream& out) const {
    out << left
        << setw(Config::OUTPUT_WIDTH_YEAR)
        << this->getYear()
        << " "
        << setw(Config::OUTPUT_WIDTH_MONTH)
        << this->getMonth()
        << " "
        << left
        << setw(Config::OUTPUT_WIDTH_TITLE)
        << string(this->getTitle()).substr(0, Config::OUTPUT_WIDTH_TITLE)
        << " "
        << endl;
}
