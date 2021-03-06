#include "../lib/Config.h"
#ifdef DEBUG
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
#include "../Collection/BooksYouth.h"
#include "../Collection/BooksFiction.h"
#include "../Collection/BooksPeriodical.h"
#include "../Collection/Histories.h"
#include "../Collection/Users.h"


using namespace std;

TEST_CASE("0-1 Users", "[collection]") {
    User* user = new User();
    user->setID(1000);
    user->setName("TestFirstName", "TestLastName");

    User* user2 = new User();
    user2->setID(1100);
    user2->setName("TestFirstName2", "TestLastName2");

    User* user3 = new User();
    user3->setID(1200);
    user3->setName("TestFirstName3", "TestLastName3");

    Youth* youth = new Youth();
    youth->setYear(201);
    youth->setAuthor("TestAuthor");
    youth->setTitle("TestYouth");

    BooksYouth& booksYouth = BooksYouth::getInstance();
    booksYouth.append(youth);

    user->addHistory("R", youth);
    user->getHistories();

    REQUIRE(user->hasBook(youth) == false);

    user->addBook(youth);
    REQUIRE(user->hasBook(youth) == true);

    // Create Users
    Users* users = new Users();
    users->append(user);
    users->append(user2);
    users->append(user3);

    Model* models[] = {
        user,
        user2,
        user3
    };

    int i = 0;
    for (set<Model*>::iterator it = users->begin();
        it != users->end(); ++it) {
        REQUIRE((*it)->key() == models[i]->key());
        i++;
    }
    delete users;
}

TEST_CASE("0-1 User", "[model]") {
    User* user = new User();
    user->setID(10000);
    user->setName("TestFirstName", "TestLastName");

    Youth* youth = new Youth();
    youth->setYear(201);
    youth->setAuthor("TestAuthor234");
    youth->setTitle("TestYouth");

    BooksYouth& booksYouth = BooksYouth::getInstance();
    booksYouth.append(youth);

    user->addHistory("R", youth);

    REQUIRE(user->getID() == 10000);
    REQUIRE(user->key() == "10000");
    REQUIRE(user->getFirstName() != "Test");
    REQUIRE(user->getLastName() != "Test");
    REQUIRE(user->getFirstName() == "TestFirstName");
    REQUIRE(user->getLastName() == "TestLastName");
    delete user;
}

TEST_CASE("0-1 histories", "[collection]") {
    Youth* youth = new Youth();
    youth->setYear(2014);
    youth->setAuthor("TestAuthor123");
    youth->setTitle("TestYouth123");

    BooksYouth& booksYouth = BooksYouth::getInstance();
    booksYouth.append(youth);

    History* history = new History();
    history->setCommand("R");
    history->setBook(youth);

    History* history2 = new History();
    history2->setCommand("C");
    history2->setBook(youth);

    History* history3 = new History();
    history3->setCommand("D");
    history3->setBook(youth);
    Histories histories;

    // Add one book
    histories.append(history);
    histories.append(history2);
    histories.append(history3);
    REQUIRE(histories.size() == 3);

    Model* models[] = {
        history,
        history2,
        history3
    };

    int i = 0;
    for (list<Model*>::iterator it = histories.begin();
        it != histories.end(); ++it) {
        REQUIRE(*it == models[i]);
        i++;
    }
}

TEST_CASE("0-1 history", "[model]") {
    Youth* youth = new Youth();
    youth->setYear(1112);
    youth->setAuthor("TestAuthor");
    youth->setTitle("TestYouth");

    History* history = new History();
    history->setCommand("R");
    history->setBook(youth);

    REQUIRE(history->getCommand() == "R");
    REQUIRE(&(history->getBook()) == youth);

    delete youth;
    delete history;
}

TEST_CASE("0-1 Youth", "[model]") {
    string title = "TestYouth";
    string author = "TestAuthor";
    int year = 123;

    Youth* youth = new Youth();
    youth->setYear(year);
    youth->setAuthor(author);
    youth->setTitle(title);

    REQUIRE(title == youth->getTitle());
    REQUIRE(author == youth->getAuthor());
    REQUIRE(year == youth->getYear());
    REQUIRE("YTestAuthorTestYouth" == youth->key());

    delete youth;
}

TEST_CASE("0-1 Fiction", "[model]") {
    string title = "TestFiction";
    string author = "TestAuthor";
    int year = 432;

    Fiction* fiction = new Fiction();
    fiction->setYear(year);
    fiction->setAuthor(author);
    fiction->setTitle(title);

    // Renting test
    bool r;
    r = fiction->checkout();
    REQUIRE(r == true);
    REQUIRE(4 == fiction->getAvailableCount());
    r = fiction->checkout();
    REQUIRE(3 == fiction->getAvailableCount());
    r = fiction->checkout();
    r = fiction->checkout();
    r = fiction->checkout();
    REQUIRE(0 == fiction->getAvailableCount());

    // Try to checkout of book that isn't Available
    r = fiction->checkout();
    REQUIRE(0 == fiction->getAvailableCount());
    REQUIRE(r == false);

    // Renting test
    r = fiction->returnBook();
    REQUIRE(1 == fiction->getAvailableCount());
    REQUIRE(r == true);
    r = fiction->returnBook();
    r = fiction->returnBook();
    r = fiction->returnBook();
    r = fiction->returnBook();
    REQUIRE(5 == fiction->getAvailableCount());

    // Returning more than it's hard copy
    r = fiction->returnBook();
    REQUIRE(5 == fiction->getAvailableCount());
    REQUIRE(r == false);

    REQUIRE(title == fiction->getTitle());
    REQUIRE(author == fiction->getAuthor());
    REQUIRE(year == fiction->getYear());
    REQUIRE("FTestAuthorTestFiction" == fiction->key());

    delete fiction;
}

TEST_CASE("0-1 Periodical", "[model]") {
    string title = "TestPeriodical";
    int month = 2;
    int year = 2014;

    Periodical* periodical = new Periodical();

    periodical->setMonth(month);
    periodical->setYear(year);
    periodical->setTitle(title);

    REQUIRE(title == periodical->getTitle());
    REQUIRE(month == periodical->getMonth());
    REQUIRE(year == periodical->getYear());
    REQUIRE("P20142TestPeriodical" == periodical->key());

    delete periodical;
}


TEST_CASE("0-1 Collection", "[collection]") {
    Periodical* periodical = new Periodical();

    // Test book 1
    periodical->setMonth(2);
    periodical->setYear(543);
    periodical->setTitle("TestPeriodical1");

    // Test book 2
    Periodical* periodical2 = new Periodical();
    periodical2->setMonth(4);
    periodical2->setYear(654);
    periodical2->setTitle("TestPeriodical2");

    // Test book 3
    Periodical* periodical3 = new Periodical();
    periodical3->setMonth(4);
    periodical3->setYear(7657);
    periodical3->setTitle("TestPeriodical3");

    // Add one book

    BooksPeriodical* books = new BooksPeriodical();
    books->append(periodical);
    REQUIRE(books->size() == 1);


    // Add one more book
    books->append(periodical2);
    REQUIRE(books->size() == 2);

    // Add one more book
    books->append(periodical3);
    REQUIRE(books->size() == 3);

    // Find a periodical that doesn't exist
    Periodical* result = static_cast<Periodical *>(books->find("test"));
    REQUIRE(!result); // Shouldn't be there

    // Find a periodical that exist
    result = static_cast<Periodical *>(books->find("P5432TestPeriodical1"));
    REQUIRE(result == periodical); // Should be there

    delete books;

    // Model* models[] = {
    //     periodical2,
    //     periodical3,
    //     periodical
    // };

    // int i = 0;
    // for (set<Model*>::iterator it = books.begin(); it != books.end(); ++it) {
    //     REQUIRE((*it)->key() == models[i]->key());
    //     i++;
    // }
}
#endif
