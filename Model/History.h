#ifndef __History_H
#define __History_H

#include "./Model.h"
#include "./Book.h"

class History : public Model {
  public:
    // History();
    void setCommand(const string commandType);
    void setBook(Book* book);
    string getCommand() const;
    Book& getBook() const;
    virtual string key() const {return NULL;}
    void print(ostream& out) const;
  protected:
    string command;
    Book* book;
};

#endif
