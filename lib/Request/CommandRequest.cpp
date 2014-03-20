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
 * The CommandRequest class extends the request class with the basic
 * functionality of being able to parse commands, such as checkout or
 * return.  
 */

#include "./CommandRequest.h"

CommandRequest::CommandRequest() {}
CommandRequest::~CommandRequest() {}

void CommandRequest::parse(string cmd) 
// Pre: Command must be standarized input, else it will ignore
// Post: Parses a command line and sends the read request
{
    // Clear the data
    this->clear();
    // Create string stream
    stringstream ss(cmd);
    // tmp string
    string tmp;

    // First one is the main Command
    if (ss >> tmp) {
        if (tmp.substr(0, 1) == Config::CMD_COMMENT) { // Ignore comment line.
            return;
        }
        this->set("command", tmp);
    } else {
        return;
    }

    // Second one is the USER ID
    if (ss >> tmp) {
        this->set("user_id", tmp);
    } else {
        return;
    }

    // Third one is the book category
    string cat;
    if (ss >> cat) {
        this->set("category", cat);
    } else {
        return;
    }

    // Fourth one is the book type
    if (ss >> tmp) {
        this->set("type", tmp);
    } else {
        return;
    }

    // Parse the rest of book Info
    if (cat == Config::CAT_PERIODICAL) { // Periodical
        ss >> tmp;
        this->set("year", tmp);
        ss >> tmp;
        this->set("month", tmp);
        getline(ss, tmp, ',');
        this->set("title", tmp.substr(1, tmp.size()-1));
    } else if (cat == Config::CAT_FICTION) { // NonPeriodical
        getline(ss, tmp, ',');
        this->set("author", tmp.substr(1, tmp.size()-1));
        getline(ss, tmp, ',');
        this->set("title", tmp.substr(1, tmp.size()-1));
    } else if (cat == Config::CAT_YOUTH) { // NonPeriodical
        getline(ss, tmp, ',');
        this->set("title", tmp.substr(1, tmp.size()-1));
        getline(ss, tmp, ',');
        this->set("author", tmp.substr(1, tmp.size()-1));
    }
}
