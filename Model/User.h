#ifndef __User_H
#define __User_H

#include "./Model.h"
#include "../Collection/Histories.h"
#include "../Collection/UserBooks.h"
#include "./Book.h"

class User : public Model {
  public:
//    User();
    void setID(int id);
    void setName(string first, string last);
    int getID() const;
    string getFirstName() const;
    string getLastName() const;
    void addHistory(string command, Book* book);
    void addBook(Book* book);
    virtual string key() const;
    Histories& getHistories();
    bool returnBook(const Book* book);
    bool hasBook(const Book* book) const;
    void print(ostream& out) const;
  protected:
    int ID;
    string firstName;
    string lastName;
    Histories histories;
    UserBooks books;
};

#endif
