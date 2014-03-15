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
#include "../lib/Router.h"

using namespace std;

TEST_CASE("0-1 Router", "[controller]") {
    Router router;
    router.init();

    CommandRequest request;
    request.parse("R 1111 Y H Danny Dunn & the Homework Machine, Williams Jay,");

    router.go(&request);
}
