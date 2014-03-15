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

#include "./Book.h"

Book::Book() : title(""), year(0), availableCount(0), hardCopyCount(0) {
}

Book::Book(int available, int hardcopy) : availableCount(available), hardCopyCount(hardcopy) {
}

string Book::getTitle() const {
    return title;
}

int Book::getAvailableCount() const {
    return availableCount;
}
int Book::getHardCopyCount() const {
    return hardCopyCount;
}

int Book::getYear() const {
    return year;
}

void Book::setTitle(string str) {
    this->title = str;
}

void Book::setYear(int y) {
    this->year = y;
}

bool Book::rentOut() {
    if (availableCount > 0) {
        availableCount--;
        return true;
    }
    // Todo:: Exception
    cerr << "Error::No book is left" << endl;
    return false;
}

bool Book::returnBook() {
    if (availableCount < getHardCopyCount()) {
        availableCount++;
        return true;
    }
    // Todo:: Exception
    cerr << "Error::More book is returned" << endl;
    return false;
}
