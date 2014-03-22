/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * Display a list of books.
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

#ifndef __ListView_H
#define __ListView_H

#include "./View.h"
#include "../Collection/BooksFiction.h"
#include "../Collection/BooksPeriodical.h"
#include "../Collection/BooksYouth.h"

class ListView : public View {
  public:
    // Constructor
    ListView(ostream* o = NULL);
    // Destructor
    ~ListView() {}
    // Show a list if books
    void render(Request* request = NULL);
  protected:
    // Render helpers
    void headerFiction() const;
    void headerYouth() const;
    void headerPeriodical() const;
    void draw(const Books& books) const;
};

#endif
