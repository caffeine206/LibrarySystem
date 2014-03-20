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
 * History is an object that saves information about books that
 * a user has checked out or returned so it can be viewed or printed
 */

#ifndef __History_H
#define __History_H

#include "./Model.h"
#include "./Book.h"

class History : public Model {
  public:
    // History();
    
    // Setter functions
    void setCommand(const string commandType);
    void setBook(Book* book);
    
    // Getter functions
    string getCommand() const;
    Book& getBook() const;
    
    // Output and storage key
    virtual string key() const {return NULL;}
    void print(ostream& out) const;
  protected:
    string command; // Defines whether it is checkout or return entry
    Book* book; // The book linked to this history entrry
};

#endif
