/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * Users is a collection used to store user models.  It includes the basic
 * functionality of creating a user collection, adding a user to the collection,
 * and finding a user in the collection.
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

#include "./Users.h"

Users& Users::getInstance() 
// Instantiates a static instance of a user collection
{
    // Auto destroyed Singleton
    static Users instance;
    return instance;
}

void Users::append(User* user) 
// Adds a user to the user collection
{
    // Call superclass function
    Indexed::append(user);
}

User* Users::fetchUser(int user_id) {
    ostringstream userKey;
    userKey << user_id;
    return Users::fetchUser(userKey.str());
}


User* Users::fetchUser(string user_id) 
// Pre: User ID must not be empty, else returns NULL
// Post: Returns a user from the user collection, or NULL if user
// cannot be found
{
    if (user_id.empty()) { // Empty ID
        return NULL;
    }
    
    // Create a unique key for the user
    ostringstream userKey;
    userKey << right << setfill('0') << setw(Config::MAX_DIGIT_USERID) << user_id;

    Users& users = Users::getInstance(); // Create a user collection

    User* user = static_cast<User *>(users.find(userKey.str()));

    if (!user) { // User not found
        return NULL;
    }
    return user;
}
