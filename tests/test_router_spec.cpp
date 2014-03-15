#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>

#include "../Model/Book/Periodical.h"
#include "../Model/Book/Fiction.h"
#include "../Model/Book/Youth.h"
#include "../Model/History.h"
#include "../Model/User.h"
#include "../Collection/BooksYouth.h"
#include "../Collection/BooksPeriodical.h"
#include "../Collection/BooksFiction.h"
#include "../Collection/Histories.h"
#include "../Collection/Users.h"
#include "../View/TextView.h"
#include "../View/ListView.h"
#include "../Controller/ReturnController.h"
#include "../lib/Request/CommandRequest.h"
#include "../lib/Config.h"
#include "../lib/Router.h"

using namespace std;

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

string arg1;
string arg2;

int main( int argc, char* const argv[] ) {
    arg1 = argv[1];
    arg2 = argv[2];
    return Catch::Session().run( );
}

TEST_CASE("0-1 Router", "[controller]") {
    BooksYouth& books = BooksYouth::getInstance();
    Youth* youth = static_cast<Youth*> (books.find("Williams JayDanny Dunn & the Homework Machine"));

    REQUIRE(youth);

    youth->rentOut();

    int available = youth->getAvailableCount();

    CommandRequest request;
    request.set("bookText", arg1);
    request.set("patronText", arg2);

    Router router(&request);

    request.clear();
    request.parse("R 1111 Y H Danny Dunn & the Homework Machine, Williams Jay,");
    router.go(&request);

    REQUIRE(youth->getAvailableCount() == available + 1);
}
