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

#include "./CommandRequest.h"

CommandRequest::CommandRequest() {}
CommandRequest::~CommandRequest() {}

void CommandRequest::parse(string cmd) {
    // Create string stream
    stringstream ss(cmd);
    // tmp string
    string tmp;

    // First one is the main Command
    if (ss >> tmp) {
        this->set("cmd", tmp);
    } else {
        cerr << "ERROR: Empty command" << endl; // TODO(Sota): Error handling
        return;
    }

    // Second one is the USER ID
    if (ss >> tmp) {
        this->set("user_id", tmp);
    } else {
        return;
    }

    // Thrid one is the book category
    string cat;
    if (ss >> cat) {
        this->set("cat", cat);
    } else {
        return;
    }

    // Forth one is the book type
    if (ss >> tmp) {
        this->set("type", tmp);
    } else {
        return;
    }

    // Parse the rest of book Info
    if (cat == "P") { // Periodical
        ss >> tmp;
        this->set("year", tmp);
        ss >> tmp;
        this->set("month", tmp);
        getline(ss, tmp, ',');
        this->set("title", tmp.substr(1, tmp.size()-1));
    } else { // NonPeriodical
        getline(ss, tmp, ',');
        this->set("author", tmp.substr(1, tmp.size()-1));
        getline(ss, tmp, ',');
        this->set("title", tmp.substr(1, tmp.size()-1));
    }
}
