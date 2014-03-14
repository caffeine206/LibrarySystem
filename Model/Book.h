#ifndef __Book_H
#define __Book_H

#include "./Model.h"

class Book : public Model {
 public:
    Book();
    ~Book() {}
    bool isBookAvailable();
    bool checkout();
    int getAvailableCount();
    int getHardCopyCount();
    string getTitle();
    int getYear();
    void setTitle(string str);
    void setYear(int y);
    bool rentOut();
    bool returnBook();
 protected:
    string title;
    int year;
    int availableCount;
    int hardCopyCount;
};

#endif
