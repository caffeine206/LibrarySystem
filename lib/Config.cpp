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

#include <string>

using namespace std;

namespace Config {
    string DATA4BOOKS           = "data/data4books.txt";
    string DATA4PATRONS         = "data/data4patrons.txt";
    string DATA4COMMANDS        = "data/data4commands.txt";
    int HARDCOPY_PERIODICAL     = 1;
    int HARDCOPY_NONPERIODICAL  = 5;
    int OUTPUT_WIDTH_AVAIL      = 5;
    int OUTPUT_WIDTH_MONTH      = 2;
    int OUTPUT_WIDTH_YEAR       = 4;
    int OUTPUT_WIDTH_AUTHOR     = 25;
    int OUTPUT_WIDTH_TITLE      = 40;
    char CAT_FICTION_CMD        = 'F';
    char CAT_PERIODICAL_CMD     = 'P';
    char CAT_YOUTH_CMD          = 'Y';
    char TYPE_HARDCOPY          = 'H';
    string CAT_FICTION_NAME       = "Fiction";
    string CAT_PERIODICAL_NAME    = "Periodical";
    string CAT_YOUTH_NAME         = "Youth";
    string USER_KEY               = "user";
}
