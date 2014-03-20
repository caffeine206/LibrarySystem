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
 * Nonperiodical extends the functionality of a book by including a special output 
 * format and sorting comparison method, as well as a way to set and access
 * a respective author.
 */

#include "./NonPeriodical.h"

// Constructs a new NonPeriodical with given number of copies
NonPeriodical::NonPeriodical()
    :Book::Book(Config::HARDCOPY_NONPERIODICAL,
                Config::HARDCOPY_NONPERIODICAL) {
}

string NonPeriodical::getAuthor() const 
// Returns the author associated with the periodical
{
    return author;
}

void NonPeriodical::setAuthor(string str) 
// Assigns the author of the periodical to a given name
{
    this->author = str;
}

string NonPeriodical::key() const 
// Unique storage key for nonperiodical
{
    ostringstream out;
    out << this->author << this->title;
    return out.str();
}
