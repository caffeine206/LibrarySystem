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

#include "./TextView.h"

void toStringFiction(ostream& out, const Fiction* book) const {
    cout << left << setw(Config::OUTPUT_WIDTH_AVAIL) << " " << book->getAvailableCount()
         << left << string(book->getTitle()).substr(0, Config::OUTPUT_WIDTH_TITLE)
         << endl;
}

void toStringPeriodial(const Fiction* fiction) const {

}
