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

#include "./History.h"

void History::setCommand(const string commandType) {
    this->command = commandType;
}

void History::setBook(Book* bookModel) {
    this->book = bookModel;
}

string History::getCommand() const {
    return this->command;
}

Book& History::getBook() const {
    return *(this->book);
}

void History::print(ostream& out) const {
    out << left
        << setfill(' ') << setw(12)
        << this->getCommand()
        << this->getBook();
}
