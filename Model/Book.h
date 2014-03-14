#ifndef __Book_H
#define __Book_H

#include "./Model.h"

class Book : public Model {
 public:
    Book();
    Book(int available, int hardCopy);
    ~Book() {}
    bool isBookAvailable() const;
    bool checkout();
    int getAvailableCount() const;
    int getHardCopyCount() const;
    string getTitle() const;
    int getYear() const;
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
