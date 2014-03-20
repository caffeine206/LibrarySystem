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
 *
 * Periodical extends the functionality of a book by including a special output
 * format, its own sorting comparison method, a unique key by which to search   
 * for it, and a month of publication
 */

#include "./Periodical.h"

// Constructor
Periodical::Periodical()
    :Book::Book(Config::HARDCOPY_PERIODICAL,
                Config::HARDCOPY_PERIODICAL) {
}

void Periodical::setMonth(int month) 
// Sets periodical's month to given value
{
    this->month = month;
}

int Periodical::getMonth() const 
// Returns the month of the periodical
{
    return month;
}

string Periodical::key() const 
// Returns the unique key for this periodical
// Key includes year, month, and title
{
    ostringstream out;
    out << this->year << this->month << this->title;
    return out.str();
}

bool Periodical::operator<(const Model & rhs) const 
// Overloaded operator for periodical comparison
// Pre: sort by date, then by title
// Post: returns true if this book comes before rhs book, false otherwise
{
    // cast rhs book to Periodical
    const Periodical& rhsCopy = static_cast<const Periodical &>(rhs);
    if (this->year < rhsCopy.year) { // year is smaller
        return true;
    } else if (this->year == rhsCopy.year) { 
        if (this->month < rhsCopy.month) { // month is smaller
            return true;
        } else { 
            // make titles lower case for comparison purposes
            string lhsTitle = Util::toLowerCase(this->title);
            string rhsTitle = Util::toLowerCase(rhsCopy.title);
            if (lhsTitle < rhsTitle) { // title is earlier
                return true;
            }
        }
    }
    return false;
}

void Periodical::print(ostream& out) const 
// Output for periodical
{
    out << left
        << setfill(' ') << setw(Config::OUTPUT_WIDTH_YEAR)
        << this->getYear()
        << " "
        << right
        << setw(Config::OUTPUT_WIDTH_MONTH)
        << this->getMonth()
        << " "
        << left
        << setw(Config::OUTPUT_WIDTH_TITLE)
        << string(this->getTitle()).substr(0, Config::OUTPUT_WIDTH_TITLE)
        << " "
        << endl;
}
