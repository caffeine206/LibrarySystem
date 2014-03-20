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
 * User extends model by adding unique functionality for keeping track
 * of a user of the system.  The user object can be assigned an ID, 
 * a first and last name, and a history of their actions in the library
 * system.  There is also an overloaded print behavior and storage key,
 * for printing and storing users in their own unique way. 
 */

#ifndef __User_H
#define __User_H

#include "./Model.h"
#include "../Collection/Histories.h"
#include "../Collection/UserBooks.h"
#include "./Book.h"

class User : public Model {
  public:
//    User();
    // Setter functions
    void setID(int id);
    void setName(string first, string last);
    
    // Getter functions
    int getID() const;
    string getFirstName() const;
    string getLastName() const;
    
    // History functions
    void addHistory(string command, Book* book);
    void addBook(Book* book);
    Histories& getHistories();
    Books& getBooks();
    bool returnBook(const Book* book);
    bool hasBook(const Book* book) const;
    
    // Output and storage key
    virtual string key() const;
    void print(ostream& out) const;
  protected:
    int ID; // Unique ID for the user
    string firstName; // User first name
    string lastName; // User last name
    Histories histories; // Collection of history entries
    UserBooks books; // Books currently associated with the user
};

#endif
