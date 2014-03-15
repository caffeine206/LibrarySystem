#ifndef __Users_H
#define __Users_H

#include "./Indexed.h"
#include "../Model/User.h"

class Users : public Indexed {
 public:
    void append(User* model);
    static Users& getInstance();
    static User* fetchUser(string user_id);
 protected:
};

#endif
