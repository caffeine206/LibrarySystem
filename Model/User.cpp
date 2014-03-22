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

// Setter functions

void User::setID(int id) 
// Assigns the user id to the given number
{
    this->ID = id;
}


int User::getID() const 
// Returns the user id currently assigned to the user
{
    return this->ID;
}

void User::setName(string first, string last) 
// Sets the first and last name of the user to the given names
{
    this->firstName = first;
    this->lastName = last;
}

// Getter functions

string User::getFirstName() const 
// Returns the first name of the user
{
    return this->firstName;
}

string User::getLastName() const 
// Returns the last name of the user
{
    return this->lastName;
}

Histories& User::getHistories() 
// Returns the collection of history entries associated with the user
{
    return this->histories;
}

Books& User::getBooks() 
// Returns the books currently associated with the user
{
    return this->books;
}

// User status and action functions

bool User::hasBook(const Book* book) const 
// Checks of the user currently has a given book checked out
{
    if (this->books.find(book->key())) {
        return true;
    } else {
        return false;
    }
}

bool User::returnBook(const Book* book) 
// Returns the given book currently checked out by the user
{
    return this->books.remove(book->key());
}

void User::addHistory(string command, Book* book) 
// Adds a history entry to the user history for a given book and given command,  
// such as checkout or return
{
    // Create History
    History* history = new History();
    history->setCommand(command);
    history->setBook(book);
    // Add to user history
    this->histories.append(history);
}

void User::addBook(Book* book) 
// Adds a book to the list of current books associated with the user
{
    // Add to UserBooks
    this->books.append(book);
}

// Output and storage functions

string User::key() const 
// Creates a unique key for the user for storage purposes
{
    ostringstream out;
    out << right << setfill('0') << setw(Config::MAX_DIGIT_USERID) << this->ID;
    return out.str();
}

void User::print(ostream& out) const 
// Prints out the user's information, including ID and their full name
{
    out << endl
        << "*** Patron ID = "
        << right
        << setfill('0') << setw(4)
        << this->getID()
        << " "
        << this->getFirstName()
        << " "
        << this->getLastName()
        << endl;
}

string User::typeOf() const
// Returns a type name
{
    return "User";

}


bool User::operator<(const Model & rhs) const 
// Overloaded operator for comparison
// Pre: sort by user ID
// Post: returns true if lhs comes before rhs, false otherwise
{
    // cast rhs to User
    const User& rhsCopy = static_cast<const User &>(rhs);
    if (this->ID < rhsCopy.ID) { 
        return true;
    }
    return false;
}
