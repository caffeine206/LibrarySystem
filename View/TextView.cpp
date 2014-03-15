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

#include <iomanip>  // setw, setFill,
#include "./TextView.h"

void TextView::headerFiction() const {
    *(this->out) << endl
         << "Fiction:"
         << endl
         << "+" << setfill('-') << setw(Config::OUTPUT_WIDTH_AVAIL + 1)
         << "+" << setw(Config::OUTPUT_WIDTH_AUTHOR + 1)
         << "+" << setw(Config::OUTPUT_WIDTH_TITLE + 1)
         << "+" << setw(Config::OUTPUT_WIDTH_YEAR + 1)
         << "+" << endl
         << left
         << setfill(' ') << setw(Config::OUTPUT_WIDTH_AVAIL + 1)
         << "|AVAIL"
         << left
         << setw(Config::OUTPUT_WIDTH_AUTHOR + 1)
         << "|AUTHOR"
         << left
         << setw(Config::OUTPUT_WIDTH_TITLE + 1)
         << "|TITLE"
         << left
         << setw(Config::OUTPUT_WIDTH_YEAR + 1)
         << "|YEAR|"
         << endl
         << setfill('-') << setw(Config::OUTPUT_WIDTH_AVAIL + 1)
         << "+" << setw(Config::OUTPUT_WIDTH_AUTHOR + 1)
         << "+" << setw(Config::OUTPUT_WIDTH_TITLE + 1)
         << "+" << setw(Config::OUTPUT_WIDTH_YEAR + 1)
         << "+" << "+" << endl;
}

void TextView::draw(const Fiction* book) const {
    *(this->out) << "| "
         << left
         << setfill(' ') << setw(Config::OUTPUT_WIDTH_AVAIL - 1)
         << book->getAvailableCount()
         << "|"
         << left
         << setw(Config::OUTPUT_WIDTH_AUTHOR)
         << string(book->getAuthor()).substr(0, Config::OUTPUT_WIDTH_AUTHOR)
         << "|"
         << left
         << setw(Config::OUTPUT_WIDTH_TITLE)
         << string(book->getTitle()).substr(0, Config::OUTPUT_WIDTH_TITLE)
         << "|"
         << left
         << setw(Config::OUTPUT_WIDTH_YEAR)
         << book->getYear()
         << "|"
         << endl
         << setfill('-') << setw(Config::OUTPUT_WIDTH_AVAIL + 1)
         << "+" << setw(Config::OUTPUT_WIDTH_AUTHOR + 1)
         << "+" << setw(Config::OUTPUT_WIDTH_TITLE + 1)
         << "+" << setw(Config::OUTPUT_WIDTH_YEAR + 1)
         << "+" << "+" << endl;
}

void TextView::welcome() {
    *(this->out)  << endl
                  << right
                  << setfill('*') << setw(80)
                  << "*"
                  << endl
                  << left
                  << setfill('*') << setw(20)
                  << "*"
                  << left
                  << setfill('*') << setw(60)
                  << "   WELCOME TO SHHH LIBRARY SYSTEM!!   "
                  << endl
                  << left
                  << setfill('*') << setw(80)
                  << "*"
                  << endl;
}

void TextView::setOstream(ostream* o) {
    this->out = o;
}


