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
 * UserBooks is an indexed collection of book models.  It includes the
 * functionality of constructing a collection of a user's books. 
 */

#include "./UserBooks.h"

UserBooks::UserBooks() {
    // This collection is sub collection and we don't need to destruct
    this->need2Destruct = false;
}
