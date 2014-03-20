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
 *
 * ArgumentRequest is a parser for argument requests that absorbs text
 * and passes the information onto the router.  It takes in a standardized form
 * of text.  
 */

#include "./ArgumentRequest.h"

ArgumentRequest::ArgumentRequest() {}
ArgumentRequest::~ArgumentRequest() {}

void ArgumentRequest::parse(int argc, char** argv) 
// Parse argument request
{
    // Loop over arguments and parse the string
    for (int i = 0; i < argc; i++) {
        stringstream ss;
        ss << i;
        this->set(ss.str(), argv[i]);
    }
}
