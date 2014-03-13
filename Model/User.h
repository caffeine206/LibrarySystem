#ifndef __User_H
#define __User_H

#include "./Model.h"
#include "../Collection/Histories.h"

class User : public Model {
  public:
//    User();
	void setID(int id);
	void setName(string first, string last);
	int getID();
	string getFirstName();
    string getLastName();
    void addHistory(History* history);
    virtual string key();
    Histories& getHistories();
  protected:
	int ID;
	string firstName;
	string lastName;
    Histories histories;
};

#endif
