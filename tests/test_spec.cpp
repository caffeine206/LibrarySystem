#define CATCH_CONFIG_MAIN

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
#include "../Collection/Books.h"
#include "../Collection/Histories.h"

using namespace std;

TEST_CASE("0-1 histories", "[model]") {
    Youth* youth = new Youth();
    youth->setYear(2014);
    youth->setAuthor("TestAuthor");
    youth->setTitle("TestYouth");

    Books books;
    books.append(youth);

    History* history = new History();
    history->setCommand('R');
    history->setBook(youth);

    History* history2 = new History();
    history2->setCommand('C');
    history2->setBook(youth);

    History* history3 = new History();
    history3->setCommand('D');
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
    youth->setYear(2014);
    youth->setAuthor("TestAuthor");
    youth->setTitle("TestYouth");

    char command = 'R';
    History* history = new History();
    history->setCommand(command);
    history->setBook(youth);

    REQUIRE(history->getCommand() == 'R');
    REQUIRE(history->getBook() == youth);

    delete youth;
    delete history;
}

TEST_CASE("0-1 Youth", "[model]") {
    string title = "TestYouth";
    string author = "TestAuthor";
    int year = 2014;

    Youth* youth = new Youth();
    youth->setYear(year);
    youth->setAuthor(author);
    youth->setTitle(title);

    REQUIRE(title == youth->getTitle());
    REQUIRE(author == youth->getAuthor());
    REQUIRE(year == youth->getYear());
    REQUIRE("TestAuthorTestYouth2014" == youth->key());

    delete youth;
}

TEST_CASE("0-1 Fiction", "[model]") {
    string title = "TestFiction";
    string author = "TestAuthor";
    int year = 2014;

    Fiction* fiction = new Fiction();
    fiction->setYear(year);
    fiction->setAuthor(author);
    fiction->setTitle(title);

    REQUIRE(title == fiction->getTitle());
    REQUIRE(author == fiction->getAuthor());
    REQUIRE(year == fiction->getYear());
    REQUIRE("TestAuthorTestFiction2014" == fiction->key());

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
    REQUIRE("TestPeriodical22014" == periodical->key());

    delete periodical;
}


TEST_CASE("0-1 Collection", "[model]") {
    Periodical* periodical = new Periodical();

    // Test book 1
    periodical->setMonth(2);
    periodical->setYear(2014);
    periodical->setTitle("TestPeriodical1");

    // Test book 2
    Periodical* periodical2 = new Periodical();
    periodical2->setMonth(4);
    periodical2->setYear(2015);
    periodical2->setTitle("TestPeriodical2");

    // Test book 3
    Periodical* periodical3 = new Periodical();
    periodical3->setMonth(4);
    periodical3->setYear(2015);
    periodical3->setTitle("TestPeriodical3");

    Books books;

    // Add one book
    books.append(periodical);
    REQUIRE(books.size() == 1);

    // Add one more book
    books.append(periodical2);
    REQUIRE(books.size() == 2);

    // Add one more book
    books.append(periodical3);
    REQUIRE(books.size() == 3);

    // Find a periodical that doesn't exist
    Periodical* result = static_cast<Periodical *>(books.find("test"));
    REQUIRE(!result); // Shouldn't be there

    // Find a periodical that exist
    result = static_cast<Periodical *>(books.find("TestPeriodical122014"));
    REQUIRE(result == periodical); // Should be there

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
