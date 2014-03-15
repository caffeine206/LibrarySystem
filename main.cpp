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

#include "./lib/Router.h"
#include "./lib/Request/ArgumentRequest.h"

int main( int argc, char *argv[] ) {
    ArgumentRequest request;
    request.parse(argc, argv);
    Router& router = Router::getInstance();
    router.start(&request);
}
