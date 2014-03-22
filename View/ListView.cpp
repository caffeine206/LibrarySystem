/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * Display a list of books.
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

#include <set>
#include "./ListView.h"

// Construcor
ListView::ListView(ostream* o) : View::View(o) {}

void ListView::render(Request* request)
// Show a list of books for each category
{
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

void ListView::headerFiction() const
// Render a table header for fiction
{
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

void ListView::headerYouth() const
// Render a table header for youth
{
    *(this->out) << endl
         << "Youth:" << endl
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

void ListView::headerPeriodical() const
// Render a table header for periodical
{
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

void ListView::draw(const Books& books) const
// Render a row of book with availablity.
{
    // Drawing the data
    for (set<Model *>::iterator it = books.begin();
        it != books.end(); ++it) {
            // Cast the model to book
            Book* book = static_cast<Book *>(*it);
            // Output the book
            *(this->out) << " "
                 << left
                 << setfill(' ') << setw(Config::OUTPUT_WIDTH_AVAIL)
                 << book->getAvailableCount()
                 << *book;
    }
}
