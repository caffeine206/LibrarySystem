#ifndef __User_H
#define __User_H

#include "./Model.h"
#include "../Collection/Histories.h"
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
    virtual string key() const;
    Histories& getHistories();
    void print(ostream& out) const;
  protected:
    int ID;
    string firstName;
    string lastName;
    Histories histories;
};

#endif
