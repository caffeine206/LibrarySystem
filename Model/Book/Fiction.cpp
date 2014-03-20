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
 * Fiction extends the functionality of a book by including a special output 
 * format and sorting comparison method
 */

#include "./Fiction.h"

// Output for Fiction
void Fiction::print(ostream& out) const {
    out << left
        << setfill(' ') << setw(Config::OUTPUT_WIDTH_AUTHOR)
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

// Overloaded operator for fiction comparison
// Pre: sort by author, then by title
// Post: returns true if this book comes before rhs book, false otherwise
bool Fiction::operator<(const Model& rhs) const {
    // cast rhs book to Fiction
    const Fiction& rhsCopy = static_cast<const Fiction &>(rhs);
    // make authors lower case for comparison purposes
    string lhsAuthor = Util::toLowerCase(this->author);
    string rhsAuthor = Util::toLowerCase(rhsCopy.author);
    if (lhsAuthor < rhsAuthor) {// Author is earlier
        return true;
    } else if (lhsAuthor == rhsAuthor) {
        // make titles lower case for comparison purposes
        if (Util::toLowerCase(this->title) < Util::toLowerCase(rhsCopy.title)) {
            return true;
        }
    }
    return false;
}
