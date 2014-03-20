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

#include "./Fiction.h"

// Output for Fiction
void Fiction::print(ostream& out) const {
    out << left
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

// Overloaded operator for fiction comparison
// Sort by author, then by title
// Returns true if this book comes before rhs book, false otherwise
bool Fiction::operator<(const Fiction & rhs) const {
    if (this->author < rhs.author) {
        return true;
    } else if (this->author == rhs.author) {
        if (this->title < rhs.title) {
            return true;
        } 
    }
    return false;
}
