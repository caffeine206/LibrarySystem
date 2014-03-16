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

#include <set>
#include "./ListView.h"

ListView::ListView(ostream* o) : View::View(o) {}

void ListView::render(Request* request) {
    // Fiction rendering
    this->headerFiction();
    this->draw(BooksFiction::getInstance());

    // Periodical rendering
    this->headerPeriodical();
    this->draw(BooksPeriodical::getInstance());

    // Youth rendering
    this->headerYouth();
    this->draw(BooksYouth::getInstance());
}

void ListView::headerFiction() const {
    *(this->out) << endl
         << "Fiction:" << endl
         << left << setfill(' ') << setw(Config::OUTPUT_WIDTH_AVAIL)
         << "AVAIL"
         << " "
         << left << setw(Config::OUTPUT_WIDTH_AUTHOR)
         << "AUTHOR"
         << " "
         << left << setw(Config::OUTPUT_WIDTH_TITLE)
         << "TITLE"
         << " "
         << left << setw(Config::OUTPUT_WIDTH_YEAR)
         << "YEAR" << endl;
}

void ListView::headerYouth() const {
    *(this->out) << endl
         << "Yourh:" << endl
         << left << setfill(' ') << setw(Config::OUTPUT_WIDTH_AVAIL)
         << "AVAIL"
         << " "
         << left << setw(Config::OUTPUT_WIDTH_TITLE)
         << "TITLE"
         << " "
         << left << setw(Config::OUTPUT_WIDTH_AUTHOR)
         << "AUTHOR"
         << " "
         << left << setw(Config::OUTPUT_WIDTH_YEAR)
         << "YEAR" << endl;
}

void ListView::headerPeriodical() const {
    *(this->out) << endl
         << "Periodical:" << endl
         << left << setfill(' ') << setw(Config::OUTPUT_WIDTH_AVAIL)
         << "AVAIL"
         << " "
         << left << setw(Config::OUTPUT_WIDTH_YEAR)
         << "YEAR"
         << " "
         << left << setw(Config::OUTPUT_WIDTH_MONTH)
         << "MO"
         << " "
         << left << setw(Config::OUTPUT_WIDTH_TITLE)
         << "TITLE" << endl;
}

void ListView::draw(const Books& books) const {
    // Drawing the data
    for (set<Model *>::iterator it = books.begin();
        it != books.end(); ++it) {
            Book* book = static_cast<Book *>(*it);
            *(this->out) << " "
                 << left
                 << setfill(' ') << setw(Config::OUTPUT_WIDTH_AVAIL)
                 << book->getAvailableCount()
                 << *book;
    }
}
