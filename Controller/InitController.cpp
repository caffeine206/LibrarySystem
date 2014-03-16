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

#include <iostream> //
#include <fstream> // ifstream
#include <string>
#include "./InitController.h"
#include "../View/InitialView.h"

InitController::InitController() {}

void InitController::exec(Request* request) {
    // Get argv[1]
    string bookFilePath = request->get("1");

    // Get argv[2]
    string patronFilePath = request->get("2");

    // TODO(SOTA): Bring this chunk of code somewhere
    // Book initilization

    ifstream bookfile (bookFilePath.c_str());
    if (bookfile.is_open()) {
        string line;
        string author;
        string title;
        string category;
        int year;
        int month;

        // Get instances of book collections
        BooksFiction& booksFiction = BooksFiction::getInstance();
        BooksPeriodical& booksPeriodical = BooksPeriodical::getInstance();
        BooksYouth& booksYouth = BooksYouth::getInstance();
        while (getline (bookfile, line)) {
            stringstream ss(line);
            ss >> category;
            if (category == Config::CAT_FICTION) {
                ss.get();
                getline(ss, author, ',');
                ss.get();
                getline(ss, title, ',');
                ss >> year;

                // Create a new book
                Fiction* fiction = new Fiction();
                fiction->setAuthor(author);
                fiction->setTitle(title);
                fiction->setYear(year);

                // Store in a collection
                booksFiction.append(fiction);
            } else if (category == Config::CAT_PERIODICAL) {
                ss.get();
                getline(ss, title, ',');
                ss >> month;
                ss >> year;

                // Create a new book
                Periodical* periodical = new Periodical();
                periodical->setTitle(title);
                periodical->setYear(year);
                periodical->setMonth(month);

                // Store in a collection
                booksPeriodical.append(periodical);
            } else if (category == Config::CAT_YOUTH) {
                ss.get();
                getline(ss, author, ',');
                ss.get();
                getline(ss, title, ',');
                ss >> year;

                // Create a new book
                Youth* youth = new Youth();
                youth->setAuthor(author);
                youth->setTitle(title);
                youth->setYear(year);

                // Store in a collection
                booksYouth.append(youth);
            } else {
                // TODO(SOTA): ADD Error handling
                cerr << "ERROR: InitController::exec() Wrong Letter" << endl;
            }
        }
        bookfile.close();
    } else {
        // TODO(SOTA): ADD Error handling
        cout << "ERROR: InitController::exec() Unable to open book file";
    }

    // TODO(SOTA): Bring this chunk of code somewhere
    // User initilization
    ifstream patronfile (patronFilePath.c_str());
    if (patronfile.is_open()) {
        int userID;
        string firstName;
        string lastName;
        string line;

        // Get instances of user collection
        Users& users = Users::getInstance();
        while (getline (patronfile, line)) {
            stringstream ss(line);
            ss >> userID
               >> firstName
               >> lastName;
           User* user = new User();
           user->setID(userID);
           user->setName(firstName, lastName);
           users.append(user);
        }
    } else {
        // TODO(SOTA): ADD Error handling
        cout << "ERROR: InitController::exec() Unable to open book file";
    }

    InitialView view;
    view.setOstream(&cout);
    view.render(request);
}
