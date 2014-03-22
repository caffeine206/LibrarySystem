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

#include <string>
#include <algorithm> // transform

using namespace std;

namespace Util {
    string toLowerCase(const string s) 
    // Returns a new lowercase version of the string passed in
    {
        string result = s;
        // iterate over each character and make it lower case
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

    bool isDigits(const string &str)
    // Check if the string is digits
    {
        return str.find_first_not_of("0123456789") == string::npos;
    }
}
