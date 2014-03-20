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
 * Youth extends the functionality of a book by including a special output 
 * format and sorting comparison method
 */

#include "./Youth.h"

// Output for youth book
void Youth::print(ostream& out) const {
    out << left
        << setfill(' ') << setw(Config::OUTPUT_WIDTH_TITLE)
        << string(this->getTitle()).substr(0, Config::OUTPUT_WIDTH_TITLE)
        << " "
        << left
        << setw(Config::OUTPUT_WIDTH_AUTHOR)
        << string(this->getAuthor()).substr(0, Config::OUTPUT_WIDTH_AUTHOR)
        << " "
        << left
        << setw(Config::OUTPUT_WIDTH_YEAR)
        << this->getYear()
        << " "
        << endl;
}

// Overloaded operator for comparison
// Pre: sort by title, then by author
// Post: returns true if this book comes before rhs book, false otherwise
bool Youth::operator<(const Youth & rhs) const {
    // make titles lower case for comparison purposes
    string lhsTitle = Util::toLowerCase(this->title);
    string rhsTitle = Util::toLowerCase(rhs.title);
    if (lhsTitle < rhsTitle) { // Title is earlier
        return true;
    } else if (lhsTitle == rhsTitle) {
        // make authors lower case for comparison purposes
        string lhsAuthor = Util::toLowerCase(this->author);
        string rhsAuthor = Util::toLowerCase(rhs.author);
        if (lhsAuthor < rhsAuthor) { // Author is earlier
            return true;
        } 
    }
    return false;
}
