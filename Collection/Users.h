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
 * Users is a collection used to store user models.  It includes the basic
 * functionality of creating a user collection, adding a user to the collection,
 * and finding a user in the collection.
 */

#ifndef __Users_H
#define __Users_H

#include "./Indexed.h"
#include "../Model/User.h"

class Users : public Indexed {
 public:
    void append(User* model); // Add a user to user collection
    static Users& getInstance(); // Create a user collection
    static User* fetchUser(string user_id); // Find a user in current collection
 protected:
};

#endif
