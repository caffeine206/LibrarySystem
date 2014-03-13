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

Book::Book() : title(""), year(0) {
}

string Book::getTitle() {
    return title;
}

int Book::getYear() {
    return year;
}

void Book::setTitle(string str) {
    this->title = str;
}

void Book::setYear(int y) {
    this->year = y;
}
