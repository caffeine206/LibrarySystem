#define CATCH_CONFIG_MAIN

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "catch.hpp"

#include "../Model/Book/Periodical.h"
#include "../Collection/Books.h"

using namespace std;

TEST_CASE("0-1", "[model]") {
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
    int month = 2;
    int year = 2014;

    Periodical* periodical = new Periodical();

    periodical->setMonth(month);
    periodical->setYear(year);
    periodical->setTitle("TestPeriodical");

    Books books;
    books.append(periodical);
    // REQUIRE(books.size() == 1);
}
