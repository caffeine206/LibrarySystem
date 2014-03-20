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
 * Book extends the functionality of a model by including all the information
 * needed to checkout, return, sort, and access information about a book and
 * its status in the SHHH library system.
 */

#ifndef __Book_H
#define __Book_H

#include <iostream>
#include <iomanip>  // setw, setFill,
#include <algorithm>
#include "../lib/Util.h"
#include "./Model.h"

class Book : public Model {
 public:
    // Constructors
    Book(); 
    Book(int available, int hardCopy);
    
    // Destructor
    ~Book() {}
    
    // Getter functions
    bool isBookAvailable() const;
    int getAvailableCount() const;
    int getHardCopyCount() const;
    string getTitle() const;
    int getYear() const;
    
    // Setter functions
    void setTitle(string str);
    void setYear(int y);
    bool checkout();
    bool returnBook();
 protected:
    string title; // Book's title
    int year; // Year of publication
    int availableCount; // Number available in library
    int hardCopyCount; // Number of hardcopies available
};

#endif
