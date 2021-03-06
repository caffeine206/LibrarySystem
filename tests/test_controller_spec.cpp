#include "../lib/Config.h"
#ifdef DEBUG

#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include "catch.hpp"

#include "../lib/Config.h"
#include "../Model/Book/Periodical.h"
#include "../Model/Book/Fiction.h"
#include "../Model/Book/Youth.h"
#include "../Model/History.h"
#include "../Model/User.h"
#include "../Collection/Books.h"
#include "../Collection/Histories.h"
#include "../Collection/Users.h"
#include "../View/ListView.h"
#include "../View/HistoryView.h"
#include "../Controller/ReturnController.h"
#include "../Controller/CheckoutController.h"
#include "../Controller/HistoryController.h"
#include "../lib/Request/CommandRequest.h"
#include "../lib/Config.h"

using namespace std;

TEST_CASE("0-1 HistoryController", "[controller]") {
    User* user = new User();
    user->setID(99992);
    user->setName("TestHistoryFirstName", "TestHistoryLastName");

    // Creat dummy books
    Fiction* fiction = new Fiction();
    fiction->setYear(1);
    fiction->setAuthor("HistoryViewTest Name FictionBookTestDerekSota");
    fiction->setTitle("HistoryViewTest Title FictionBookTestDerekSota");

    Youth* youth = new Youth();
    youth->setYear(5);
    youth->setAuthor("HistoryViewTest Name");
    youth->setTitle("HistoryViewTest Title");

    Periodical* periodical = new Periodical();
    periodical->setYear(114);
    periodical->setMonth(7);
    periodical->setTitle("Communications of the ACM");

    // Create dummy collections
    BooksFiction& fictionBooks = BooksFiction::getInstance();
    fictionBooks.append(fiction);

    BooksYouth& youthBooks = BooksYouth::getInstance();
    youthBooks.append(youth);

    BooksPeriodical& periodicalBooks = BooksPeriodical::getInstance();
    periodicalBooks.append(periodical);

    Users& users = Users::getInstance();
    users.append(user);

    // Checkout
    CommandRequest request;
    request.parse("C 99992 F H HistoryViewTest Name FictionBookTestDerekSota, HistoryViewTest Title FictionBookTestDerekSota,");
    CheckoutController checkoutCtr;
    checkoutCtr.exec(&request);

    request.clear();
    request.parse("C 99992 P H 114 7 Communications of the ACM,");
    checkoutCtr.exec(&request);

    request.clear();
    request.parse("C 99992 Y H HistoryViewTest Title, HistoryViewTest Name,");
    checkoutCtr.exec(&request);

    // Return
    request.clear();
    request.parse("R 99992 F H HistoryViewTest Name FictionBookTestDerekSota, HistoryViewTest Title FictionBookTestDerekSota,");
    ReturnController ReturnCtr;
    ReturnCtr.exec(&request);

    // Check History size
    Histories& histories = user->getHistories();
    REQUIRE(histories.size() == 4);

    // Render a divider
    cout << endl << "********HistoryController******" << endl;

    HistoryController historyCtr;

    // Create Request
    request.clear();
    request.parse("H 9999");

    historyCtr.exec(&request);
}


TEST_CASE("0-1 CheckoutController", "[controller]") {
    // Create dummy Users
    User* user = new User();
    user->setID(10000);
    user->setName("TestFirstName", "TestLastName");

    User* user2 = new User();
    user2->setID(11110);
    user2->setName("TestFirstName2", "TestLastName2");

    User* user3 = new User();
    user3->setID(12000);
    user3->setName("TestFirstName3", "TestLastName3");

    // Creat dummy books
    Fiction* fiction = new Fiction();
    fiction->setYear(246);
    fiction->setAuthor("ListViewTest Name");
    fiction->setTitle("ListViewTest Title");
    fiction->checkout();
    fiction->checkout();
    fiction->checkout();

    Fiction* fiction2 = new Fiction();
    fiction2->setYear(357);
    fiction2->setAuthor("ListViewTest Author Name abcdefghijklmnopqrstuvwxyz");
    fiction2->setTitle("ListViewTest Title abcdefghijklmnopqrstuvwxyz");

    Youth* youth = new Youth();
    youth->setYear(753);
    youth->setAuthor("Williams Jay");
    youth->setTitle("123Danny Dunn & the Homework Machine");

    Periodical* periodical = new Periodical();
    periodical->setMonth(2);
    periodical->setYear(4262);
    periodical->setTitle("Comic bon bon");

    // Create dummy collections
    Users& users = Users::getInstance();
    users.append(user);
    users.append(user2);
    users.append(user3);

    BooksFiction& fictionBooks = BooksFiction::getInstance();
    fictionBooks.append(fiction);
    fictionBooks.append(fiction2);

    BooksYouth& youthBooks = BooksYouth::getInstance();
    youthBooks.append(youth);

    BooksPeriodical& periodicalBooks = BooksPeriodical::getInstance();
    periodicalBooks.append(periodical);

    // Create CheckoutController
    CheckoutController checkoutCtr;

    REQUIRE(youth->getAvailableCount() == 5);

    // Create Request
    CommandRequest request;
    request.parse("C 11110 Y H 123Danny Dunn & the Homework Machine, Williams Jay,");

    checkoutCtr.exec(&request);
    REQUIRE(youth->getAvailableCount() == 4);
}

TEST_CASE("0-1 ReturnController", "[controller]") {
    // Create dummy Users
    User* user = new User();
    user->setID(10001);
    user->setName("TestFirstName", "TestLastName");

    User* user2 = new User();
    user2->setID(11112);
    user2->setName("TestFirstName2", "TestLastName2");

    User* user3 = new User();
    user3->setID(120033);
    user3->setName("TestFirstName3", "TestLastName3");

    Youth* youth = new Youth();
    youth->setYear(2011);
    youth->setAuthor("Williams Jay");
    youth->setTitle("Danny Dunn & the Homework Machine");

    Periodical* periodical = new Periodical();
    periodical->setMonth(2);
    periodical->setYear(2543);
    periodical->setTitle("Comic bon bon");

    // Create dummy collections
    Users& users = Users::getInstance();
    users.append(user);
    users.append(user2);
    users.append(user3);

    BooksFiction& fictionBooks = BooksFiction::getInstance();

    BooksYouth& youthBooks = BooksYouth::getInstance();
    youthBooks.append(youth);

    BooksPeriodical& periodicalBooks = BooksPeriodical::getInstance();
    periodicalBooks.append(periodical);

    // Create list view
    ReturnController returnCtr;

    REQUIRE(youth->getAvailableCount() == 5);

    // Create Request
    CommandRequest request;
    request.parse("R 11112 Y H Danny Dunn & the Homework Machine, Williams Jay,");

    returnCtr.exec(&request);
    REQUIRE(youth->getAvailableCount() == 5);

    request.parse("C 11112 Y H Danny Dunn & the Homework Machine, Williams Jay,");
    CheckoutController ctr;
    ctr.exec(&request);

    REQUIRE(youth->getAvailableCount() == 4);

    request.parse("R 11112 Y H Danny Dunn & the Homework Machine, Williams Jay,");

    returnCtr.exec(&request);
    REQUIRE(youth->getAvailableCount() == 5);
}
#endif
