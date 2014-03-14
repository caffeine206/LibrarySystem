
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include "catch.hpp"

#include "../Model/Book/Periodical.h"
#include "../Model/Book/Fiction.h"
#include "../Model/Book/Youth.h"
#include "../Model/History.h"
#include "../Model/User.h"
#include "../Collection/Books.h"
#include "../Collection/Histories.h"
#include "../Collection/Users.h"
#include "../View/TextView.h"
#include "../View/ListView.h"

using namespace std;

TEST_CASE("0-1 ListView", "[view]") {
    // Creat dummy books
    Fiction* fiction = new Fiction();
    fiction->setYear(2014);
    fiction->setAuthor("ListViewTest Name");
    fiction->setTitle("ListViewTest Title");

    Fiction* fiction2 = new Fiction();
    fiction2->setYear(2013);
    fiction2->setAuthor("ListViewTest Author Name abcdefghijklmnopqrstuvwxyz");
    fiction2->setTitle("ListViewTest Title abcdefghijklmnopqrstuvwxyz");

    Youth* youth = new Youth();
    youth->setYear(2011);
    youth->setAuthor("TestAuthor");
    youth->setTitle("TestYouth");

    Periodical* periodical = new Periodical();
    periodical->setMonth(2);
    periodical->setYear(2000);
    periodical->setTitle("Comic bon bon");

    // Create dummy collections
    Books* fictionBooks = new Books();
    fictionBooks->append(fiction);
    fictionBooks->append(fiction2);

    Books* youthBooks = new Books();
    youthBooks->append(youth);

    Books* periodicalBooks = new Books();
    periodicalBooks->append(periodical);

    // Render a divider
    cout << endl << "********ListViewTest******" << endl;

    // Create list view
    ListView listView;
    listView.setOstream(&cout);
    listView.setCollection(Config::CAT_FICTION_NAME, fictionBooks);
    listView.setCollection(Config::CAT_YOUTH_NAME, youthBooks);
    listView.setCollection(Config::CAT_PERIODICAL_NAME, periodicalBooks);
    listView.render();

    // Delete Collections
    delete fictionBooks;
    delete youthBooks;
    delete periodicalBooks;
}

TEST_CASE("0-1 TextView Fiction", "[view]") {
    Fiction* fiction = new Fiction();
    fiction->setYear(2014);
    fiction->setAuthor("Sota Ogo");
    fiction->setTitle("A Japanese Guy");

    Fiction* fiction2 = new Fiction();
    fiction2->setYear(2013);
    fiction2->setAuthor("Long Author Name Yayyyy abcdefghijklmnopqrstuvwxyz");
    fiction2->setTitle("Long Title Yayyyyabcdefghijklmnopqrstuvwxyz");

    Books books;
    books.append(fiction);
    books.append(fiction2);

    fiction->rentOut();

    cout << endl << "********TextViewTest******" << endl;
    TextView textView;
    textView.setOstream(&cout);
    textView.headerFiction();

    for (set<Model*>::iterator it = books.begin();
        it != books.end(); ++it) {
        textView.draw(static_cast<Fiction *>(*it));
    }
}
