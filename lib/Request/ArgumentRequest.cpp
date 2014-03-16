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

#include "./ArgumentRequest.h"

ArgumentRequest::ArgumentRequest() {}
ArgumentRequest::~ArgumentRequest() {}

void ArgumentRequest::parse(int argc, char** argv) {
    for (int i = 0; i < argc; i++) {
        stringstream ss;
        ss << i;
        this->set(ss.str(), argv[i]);
    }
}
