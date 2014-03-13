#ifndef __Book_H
#define __Book_H

#include "./Model.h"

class Book : public Model {
 public:
    Book();
    ~Book() {}
    bool isBookAvailable();
    bool checkout();
    string getTitle();
    int getYear();
    void setTitle(string str);
    void setYear(int y);
 protected:
    string title;
    int year;
};

#endif
