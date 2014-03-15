
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
#include "../Controller/ReturnController.h"
#include "../Controller/CheckoutController.h"
#include "../lib/Request/CommandRequest.h"
#include "../lib/Config.h"

using namespace std;


TEST_CASE("0-1 CheckoutController", "[controller]") {
    // Create dummy Users
    User* user = new User();
    user->setID(1000);
    user->setName("TestFirstName", "TestLastName");

    User* user2 = new User();
    user2->setID(1111);
    user2->setName("TestFirstName2", "TestLastName2");

    User* user3 = new User();
    user3->setID(1200);
    user3->setName("TestFirstName3", "TestLastName3");

    // Creat dummy books
    Fiction* fiction = new Fiction();
    fiction->setYear(2014);
    fiction->setAuthor("ListViewTest Name");
    fiction->setTitle("ListViewTest Title");
    fiction->checkout();
    fiction->checkout();
    fiction->checkout();

    Fiction* fiction2 = new Fiction();
    fiction2->setYear(2013);
    fiction2->setAuthor("ListViewTest Author Name abcdefghijklmnopqrstuvwxyz");
    fiction2->setTitle("ListViewTest Title abcdefghijklmnopqrstuvwxyz");

    Youth* youth = new Youth();
    youth->setYear(2011);
    youth->setAuthor("Williams Jay");
    youth->setTitle("123Danny Dunn & the Homework Machine");

    Periodical* periodical = new Periodical();
    periodical->setMonth(2);
    periodical->setYear(2000);
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
    request.parse("C 1111 Y H 123Danny Dunn & the Homework Machine, Williams Jay,");

    checkoutCtr.exec(&request);
    REQUIRE(youth->getAvailableCount() == 4);
}

TEST_CASE("0-1 ReturnController", "[controller]") {
    // Create dummy Users
    User* user = new User();
    user->setID(1000);
    user->setName("TestFirstName", "TestLastName");

    User* user2 = new User();
    user2->setID(1111);
    user2->setName("TestFirstName2", "TestLastName2");

    User* user3 = new User();
    user3->setID(1200);
    user3->setName("TestFirstName3", "TestLastName3");

    // Creat dummy books
    Fiction* fiction = new Fiction();
    fiction->setYear(2014);
    fiction->setAuthor("ListViewTest Name");
    fiction->setTitle("ListViewTest Title");
    fiction->checkout();
    fiction->checkout();
    fiction->checkout();

    Fiction* fiction2 = new Fiction();
    fiction2->setYear(2013);
    fiction2->setAuthor("ListViewTest Author Name abcdefghijklmnopqrstuvwxyz");
    fiction2->setTitle("ListViewTest Title abcdefghijklmnopqrstuvwxyz");

    Youth* youth = new Youth();
    youth->setYear(2011);
    youth->setAuthor("Williams Jay");
    youth->setTitle("Danny Dunn & the Homework Machine");
    youth->checkout();

    Periodical* periodical = new Periodical();
    periodical->setMonth(2);
    periodical->setYear(2000);
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

    // Create list view
    ReturnController returnCtr;

    REQUIRE(youth->getAvailableCount() == 4);

    // Create Request
    CommandRequest request;
    request.parse("R 1111 Y H Danny Dunn & the Homework Machine, Williams Jay,");

    returnCtr.exec(&request);
    REQUIRE(youth->getAvailableCount() == 5);
}
