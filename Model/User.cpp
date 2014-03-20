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
#include "./User.h"

void User::setID(int id) {
    this->ID = id;
}

int User::getID() const {
    return this->ID;
}

void User::setName(string first, string last) {
    this->firstName = first;
    this->lastName = last;
}

string User::getFirstName() const {
    return this->firstName;
}

string User::getLastName() const {
    return this->lastName;
}

Histories& User::getHistories() {
    return this->histories;
}

Books& User::getBooks() {
    return this->books;
}

bool User::hasBook(const Book* book) const {
    if (this->books.find(book->key())) {
        return true;
    } else {
        return false;
    }
}

bool User::returnBook(const Book* book) {
    return this->books.remove(book->key());
}

void User::addHistory(string command, Book* book) {
    // Create History
    History* history = new History();
    history->setCommand(command);
    history->setBook(book);
    // Add to user history
    this->histories.append(history);
}

void User::addBook(Book* book) {
    // Add to UserBooks
    this->books.append(book);
}

string User::key() const {
    ostringstream out;
    out << right << setfill('0') << setw(Config::MAX_DIGIT_USERID) << this->ID;
    return out.str();
}

void User::print(ostream& out) const {
    out << endl
        << "*** Patron ID = "
        << left
        << setfill('0') << setw(4)
        << this->getID()
        << " "
        << this->getFirstName()
        << " "
        << this->getLastName()
        << endl;
}
