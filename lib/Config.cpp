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
 * Config is a namespace used for global constants such as the maximum amount
 * of books that can be checked out for a given book.  It is accessed by other
 * classes to reduce redundancy and hard coding of numbers.  
 */

#include <string>

using namespace std;

namespace Config {
    int MAX_DIGIT_USERID        = 4; // Length of user IDs
    int HARDCOPY_PERIODICAL     = 1; // Hardcopes of periodicals
    int HARDCOPY_NONPERIODICAL  = 5; // Standard copies of periodicals
    
    // Output dimensions
    int OUTPUT_WIDTH_AVAIL      = 5; 
    int OUTPUT_WIDTH_MONTH      = 2;
    int OUTPUT_WIDTH_YEAR       = 4;
    int OUTPUT_WIDTH_AUTHOR     = 30;
    int OUTPUT_WIDTH_TITLE      = 30;
    // char CAT_FICTION_CMD        = 'F';
    // char CAT_PERIODICAL_CMD     = 'P';
    // char CAT_YOUTH_CMD          = 'Y';
    
    // Book codes for different categories
    string TYPE_HARDCOPY        = "H";
    string CAT_FICTION          = "F";
    string CAT_PERIODICAL       = "P";
    string CAT_YOUTH            = "Y";
    
    // User commands
    string USER_KEY             = "user";
    string CMD_CHECKOUT         = "C";
    string CMD_RETURN           = "R";
    string CMD_HISTORY          = "H";
    string CMD_DISPLAY          = "D";
    string CMD_COMMENT          = "#";
}
