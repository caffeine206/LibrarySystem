#ifndef __Book_H
#define __Book_H

#include <iostream>
#include <iomanip>  // setw, setFill,
#include "./Model.h"

class Book : public Model {
 public:
    Book();
    Book(int available, int hardCopy);
    ~Book() {}
    bool isBookAvailable() const;
    int getAvailableCount() const;
    int getHardCopyCount() const;
    string getTitle() const;
    int getYear() const;
    void setTitle(string str);
    void setYear(int y);
    bool checkout();
    bool returnBook();
    friend ostream& operator<< (std::ostream &out,
                               const Book &book);
 protected:
    string title;
    int year;
    int availableCount;
    int hardCopyCount;
};

#endif
