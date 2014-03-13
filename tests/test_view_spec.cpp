
#include "../Model/Book/Periodical.h"
#include "../Model/Book/Fiction.h"
#include "../Model/Book/Youth.h"
#include "../Model/History.h"
#include "../Model/User.h"
#include "../Collection/Books.h"
#include "../Collection/Histories.h"
#include "../Collection/Users.h"


#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include "catch.hpp"

using namespace std;

TEST_CASE("0-1 ListView", "[view]") {
    REQUIRE(1 == 0);
}
