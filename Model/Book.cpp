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
 * Book is an abstract class containing common information and functionailty for all book types,
 * including title, year, availability, output, and the ability to checkout or return it
 */

#include "./Book.h"

// Constructors

Book::Book() : title(""), year(0), availableCount(0), hardCopyCount(0) 
// Initializes a book with empty title, 0 for year, 0 available, and 0 hard copies
{
}

Book::Book(int available, int hardcopy) : availableCount(available), hardCopyCount(hardcopy) 
// Initializes a book with a given number available, and a given number of hard copies available
{
}

// Getter Functions

string Book::getTitle() const 
// Returns the title of the book
{
    return title;
}

int Book::getAvailableCount() const 
// Returns the number of available books
{
    return availableCount;
}
int Book::getHardCopyCount() const 
// Returns the number of hard copies available
{
    return hardCopyCount;
}

int Book::getYear() const 
// Returns the year of publication for the book
{
    return year;
}

// Setter Functions

void Book::setTitle(string str) 
// Sets the title for a given book to a given string
{
    this->title = str;
}

void Book::setYear(int y) 
// Sets the year of publication to a given year
{
    this->year = y;
}

bool Book::checkout() 
// Pre: Book must be available, else returns error
// Post: Checks out the book and reduces the number available by 1
{
    if (availableCount > 0) {
        availableCount--;
        return true;
    }
    return false;
}

bool Book::returnBook() 
// Pre: Return must not exceed max number of books in library, else returns error
// Post: Returns a book and increaes the number available by 1
{
    if (availableCount < getHardCopyCount()) {
        availableCount++;
        return true;
    }
    return false;
}

ostream& operator<< (ostream& out, const Book& book) 
// Prints out output for current book
{
    book.print(out);
    return out;
}

string Book::typeOf() const
// Returns a type name
{
    return "Book";

}

