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

// Setter Functions

void History::setCommand(const string commandType) 
// Assigns the command type for the history to a given string
{
    this->command = commandType;
}

void History::setBook(Book* bookModel) 
// Assigns the book for the history to a given book
{
    this->book = bookModel;
}

// Getter Functions

string History::getCommand() const 
// Returns the command for this history entry
{
    return this->command;
}

Book& History::getBook() const 
// Returns the book for this history entry
{
    return *(this->book);
}

void History::print(ostream& out) const 
// Prints the output for this history entry
{
    out << left
        << setfill(' ') << setw(12)
        << this->getCommand()
        << this->getBook();
}

string History::typeOf() const
// Returns a type name
{
    return "History";

}
