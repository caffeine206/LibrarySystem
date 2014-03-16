/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * 
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

// #define DEBUG

#include "./lib/Config.h"
#include "./lib/Router.h"
#include "./lib/Request/ArgumentRequest.h"

// Remove unit tests if it's not in DEBUG mode
#ifdef DEBUG
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#endif

int main( int argc, char *argv[] ) {
#ifdef DEBUG
    Catch::Session().run( );
#endif
    ArgumentRequest request;
    request.parse(argc, argv);
    Router& router = Router::getInstance();
    router.start(&request);
}
