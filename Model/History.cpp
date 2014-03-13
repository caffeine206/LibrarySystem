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

void History::setCommand(const char commandType) {
    this->command = commandType;
}

void History::setBook(Book* bookModel) {
    this->book = bookModel;
}

char History::getCommand() const {
    return this->command;
}

Book* History::getBook() const {
    return this->book;
}
