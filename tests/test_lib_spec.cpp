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
#include "../Collection/Books.h"
#include "../Collection/Histories.h"
#include "../Collection/Users.h"
#include "../View/ListView.h"
#include "../Controller/ReturnController.h"
#include "../lib/Request/CommandRequest.h"
#include "../lib/Config.h"

using namespace std;

TEST_CASE("0-1 Request", "[lib]") {
    CommandRequest request;
    request.parse("H 5000");
    REQUIRE(request.get("command") == "H");
    REQUIRE(request.get("user_id") == "5000");
    REQUIRE(request.size() == 2);

    request.clear();

    request.parse("C 8000 F H Kerouac Jack, On the Road,");
    REQUIRE(request.get("command") == "C");
    REQUIRE(request.get("user_id") == "8000");
    REQUIRE(request.get("category") == "F");
    REQUIRE(request.get("type") == "H");
    REQUIRE(request.get("author") == "Kerouac Jack");
    REQUIRE(request.get("title") == "On the Road");
    REQUIRE(request.size() == 6);

    request.clear();

    request.parse("C 1111 P H 2010 2 Communications of the ACM,");
    REQUIRE(request.get("command") == "C");
    REQUIRE(request.get("user_id") == "1111");
    REQUIRE(request.get("category") == "P");
    REQUIRE(request.get("type") == "H");
    REQUIRE(request.get("year") == "2010");
    REQUIRE(request.get("title") == "Communications of the ACM");
    REQUIRE(request.size() == 7);
}
#endif
