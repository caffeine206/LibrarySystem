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

#include "./Users.h"

Users& Users::getInstance() {
    // Auto destroyed Singleton
    static Users instance;
    return instance;
}

void Users::append(User* user) {
    // Call superclass function
    Indexed::append(user);
}

User* Users::fetchUser(string user_id) {
    if (user_id.size() == 0) {
        // Todo: Error handling for userKey
        cerr << "ERROR: Users::fetchUser() EMPTY USER ID" << endl;
        return NULL;
    }

    Users& users = Users::getInstance();

    User* user = static_cast<User *>(users.find(user_id));

    if (!user) {
        // Todo: Error handling for user
        cerr << "ERROR: Users::fetchUser() INVALID USER ID" << endl;
        return NULL;
    }
    return user;
}
