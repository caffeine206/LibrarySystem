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

#include "./ShhhController.h"

User* ShhhController::fetchUser(string user_id) {
    Users* users = static_cast<Users *>(clMap[Config::USER_KEY]);

    if (user_id.size() == 0) {
        // Todo: Error handling for userKey
        cerr << "ERROR: ReturnController::exec() EMPTY USER ID" << endl;
        return NULL;
    }

    User* user = static_cast<User *>(users->find(user_id));

    if (!user) {
        // Todo: Error handling for user
        cerr << "ERROR: ReturnController::exec() INVALID USER ID" << endl;
        return NULL;
    }
    return user;
}
