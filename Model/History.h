#ifndef __History_H
#define __History_H

#include "./Model.h"
#include "./Book.h"

class History : public Model {
  public:
    // History();
    void setCommand(const char commandType);
    void setBook(Book* book);
    char getCommand() const;
    Book& getBook() const;
    virtual string key() const {return NULL;}
    void print(ostream& out) const;
  protected:
    char command;
    Book* book;
};

#endif
