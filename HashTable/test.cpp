
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "assoc.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

TEST_CASE( "0-1", "[assoc]" ) {
  REQUIRE(1!=1);
}
