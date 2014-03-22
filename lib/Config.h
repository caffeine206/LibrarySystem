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

#ifndef CONFIG_H
#define CONFIG_H

#include <string>

// Unomment to enable the Debug mode
#define DEBUG

using namespace std;

namespace Config {
    // Length of user IDs
    extern int MAX_DIGIT_USERID; 
    // Number of hardcopies for periodicals
    extern int HARDCOPY_PERIODICAL; 
    // Number of standard copies for periodicals
    extern int HARDCOPY_NONPERIODICAL;

    // Output dimensions
    extern int OUTPUT_WIDTH_AVAIL;
    extern int OUTPUT_WIDTH_MONTH;
    extern int OUTPUT_WIDTH_YEAR;
    extern int OUTPUT_WIDTH_AUTHOR;
    extern int OUTPUT_WIDTH_TITLE;

    // Book codes for different categories
    extern string CAT_FICTION;
    extern string CAT_PERIODICAL;
    extern string CAT_YOUTH;
    extern string TYPE_HARDCOPY;
    
    // User commands
    extern string USER_KEY;
    extern string CMD_CHECKOUT;
    extern string CMD_RETURN;
    extern string CMD_HISTORY;
    extern string CMD_DISPLAY;
    extern string CMD_COMMENT;
}

#endif
