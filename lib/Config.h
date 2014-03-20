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

#ifndef CONFIG_H
#define CONFIG_H

#include <string>

#define DEBUG

using namespace std;

namespace Config {
    extern int MAX_DIGIT_USERID;
    extern int HARDCOPY_PERIODICAL;
    extern int HARDCOPY_NONPERIODICAL;
    extern int OUTPUT_WIDTH_AVAIL;
    extern int OUTPUT_WIDTH_MONTH;
    extern int OUTPUT_WIDTH_YEAR;
    extern int OUTPUT_WIDTH_AUTHOR;
    extern int OUTPUT_WIDTH_TITLE;
    // extern char CAT_FICTION_CMD;
    // extern char CAT_PERIODICAL_CMD;
    // extern char CAT_YOUTH_CMD;
    extern string CAT_FICTION;
    extern string CAT_PERIODICAL;
    extern string CAT_YOUTH;
    extern string TYPE_HARDCOPY;
    extern string USER_KEY;
    extern string CMD_CHECKOUT;
    extern string CMD_RETURN;
    extern string CMD_HISOTRY;
    extern string CMD_DISPLAY;
    extern string CMD_COMMENT;
}

#endif
