#ifndef __Book_H
#define __Book_H

class Book : public Model {
  public:
    getAuthor();
    getTitle();
    getCategoryID();
    getDay();
    getMonth();
    getYear();
  
  protected:
    string author;
    string title;
    int categoryID;
    int day;
    int month;
    int year;
};

#endif
