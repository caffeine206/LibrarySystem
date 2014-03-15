
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
#include "../Collection/BooksFiction.h"
#include "../Collection/BooksPeriodical.h"
#include "../Collection/BooksYouth.h"
#include "../Collection/Histories.h"
#include "../Collection/Users.h"
#include "../View/TextView.h"
#include "../View/ListView.h"
#include "../View/HistoryView.h"
#include "../Controller/ReturnController.h"
#include "../Controller/CheckoutController.h"
#include "../lib/Request/CommandRequest.h"

using namespace std;


TEST_CASE("0-1 HistoryView", "[view]") {
    User* user = new User();
    user->setID(9999);
    user->setName("TestHistoryFirstName", "TestHistoryLastName");

    // Creat dummy books
    Fiction* fiction = new Fiction();
    fiction->setYear(2014);
    fiction->setAuthor("HistoryViewTest Name");
    fiction->setTitle("HistoryViewTest Title");

    // Create dummy collections
    BooksFiction& fictionBooks = BooksFiction::getInstance();
    fictionBooks.append(fiction);

    Users& users = Users::getInstance();
    users.append(user);

    // Checkout
    CommandRequest request;
    request.parse("C 9999 F H HistoryViewTest Title, HistoryViewTest Name,");
    CheckoutController checkoutCtr;
    checkoutCtr.exec(&request);

    // Return
    request.clear();
    request.parse("R 9999 F H HistoryViewTest Title, HistoryViewTest Name,");
    ReturnController ReturnCtr;
    ReturnCtr.exec(&request);

    // Render a divider
    cout << endl << "********HistoryViewTest******" << endl;

    // Create list view
    HistoryView historyView;
    historyView.setOstream(&cout);
    historyView.render(&request);
}


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
    BooksFiction& fictionBooks = BooksFiction::getInstance();
    fictionBooks.append(fiction);
    fictionBooks.append(fiction2);

    BooksYouth& youthBooks = BooksYouth::getInstance();
    youthBooks.append(youth);

    BooksPeriodical& periodicalBooks = BooksPeriodical::getInstance();
    periodicalBooks.append(periodical);

    // Render a divider
    cout << endl << "********ListViewTest******" << endl;

    // Create list view
    ListView listView;
    listView.setOstream(&cout);
    listView.render(NULL);
}

TEST_CASE("0-1 TextView Fiction", "[view]") {
    // Fiction* fiction = new Fiction();
    // fiction->setYear(2014);
    // fiction->setAuthor("Sota Ogo");
    // fiction->setTitle("A Japanese Guy");

    // Fiction* fiction2 = new Fiction();
    // fiction2->setYear(2013);
    // fiction2->setAuthor("Long Author Name Yayyyy abcdefghijklmnopqrstuvwxyz");
    // fiction2->setTitle("Long Title Yayyyyabcdefghijklmnopqrstuvwxyz");

    // BooksFiction& books = BooksFiction::getInstance();
    // books.append(fiction);
    // books.append(fiction2);

    // fiction->checkout();

    // // cout << endl << "********TextViewTest******" << endl;
    // TextView textView;
    // textView.setOstream(&cout);
    // textView.headerFiction();

    // for (set<Model*>::iterator it = books.begin();
    //     it != books.end(); ++it) {
    //     textView.draw(static_cast<Fiction *>(*it));
    // }
}
