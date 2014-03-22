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
 * Util is a namespace composition of global functions necessary for the
 * library system, such as changing text to all lowercase.  
 */

#ifndef UTIL_H
#define UTIL_H

#include <string>

using namespace std;

namespace Util {
    // Returns a lowercase version of a string
    string toLowerCase(const string s); 
    bool isDigits(const string &str);
}

#endif
