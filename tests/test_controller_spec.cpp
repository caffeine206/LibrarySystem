
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
#include "../lib/Request/CommandRequest.h"
#include "../lib/Config.h"

using namespace std;

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
    fiction->rentOut();
    fiction->rentOut();
    fiction->rentOut();

    Fiction* fiction2 = new Fiction();
    fiction2->setYear(2013);
    fiction2->setAuthor("ListViewTest Author Name abcdefghijklmnopqrstuvwxyz");
    fiction2->setTitle("ListViewTest Title abcdefghijklmnopqrstuvwxyz");

    Youth* youth = new Youth();
    youth->setYear(2011);
    youth->setAuthor("Williams Jay");
    youth->setTitle("Danny Dunn & the Homework Machine");
    youth->rentOut();

    Periodical* periodical = new Periodical();
    periodical->setMonth(2);
    periodical->setYear(2000);
    periodical->setTitle("Comic bon bon");

    // Create dummy collections
    Users* users = new Users();
    users->append(user);
    users->append(user2);
    users->append(user3);

    Books* fictionBooks = new Books();
    fictionBooks->append(fiction);
    fictionBooks->append(fiction2);

    Books* youthBooks = new Books();
    youthBooks->append(youth);

    Books* periodicalBooks = new Books();
    periodicalBooks->append(periodical);

    // Create list view
    ReturnController returnCtr;
    returnCtr.setCollection(Config::USER_KEY, users);
    returnCtr.setCollection(Config::CAT_FICTION, fictionBooks);
    returnCtr.setCollection(Config::CAT_YOUTH, youthBooks);
    returnCtr.setCollection(Config::CAT_PERIODICAL, periodicalBooks);

    REQUIRE(youth->getAvailableCount() == 4);

    // Create Request
    CommandRequest request;
    request.parse("R 1111 Y H Danny Dunn & the Homework Machine, Williams Jay,");

    returnCtr.exec(&request);
    REQUIRE(youth->getAvailableCount() == 5);

    // Delete Collections
    delete fictionBooks;
    delete youthBooks;
    delete periodicalBooks;
    delete users;
}
