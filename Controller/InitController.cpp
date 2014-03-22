/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * The InitController class is intended to initialize the library system from
 * external input. It extends the Controller class with the functionality of 
 * parsing data from a standardized input text file, and then intializing
 * the library system.  
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

#include <sys/time.h> // gettimeofday
#include <iostream> //
#include <fstream> // ifstream
#include <string>
#include "./InitController.h"
#include "../View/InitialView.h"

// Constructor
InitController::InitController() {}

void InitController::exec(Request* request)
// Execute an initialization request
// Pre: Book file must be valid and of expected style, else returns an error
// Post: Adds a list of books to the library system
{
    #ifdef DEBUG
    // Time measuring
    cout << "Intializing the database..." << endl;
    struct timeval tim;
    gettimeofday(&tim, NULL); // Start timing
    double t1 = tim.tv_sec+(tim.tv_usec/1000000.0);
    #endif

    // Get argv[1]
    string bookFilePath = request->get("1");

    // Get argv[2]
    string patronFilePath = request->get("2");

    if (bookFilePath.empty() || patronFilePath.empty()) {
        cout << "ERROR: Initialization: Not enough arguments." << endl
             << "Arguments must contain paths to book and patron lists."
             << endl
             << "Usage:"
             << "  shhh /path/to/bookFile /path/to/patronFile" << endl
             << "(commands are read from the standard input)" << endl;
        exit(1); // (exit abnormally)
    }

    // Parsing the book file
    if (!parseBookdata(bookFilePath)) { // Parsing failed
        cout << "ERROR: Initialization: Unable to open a book file" << endl;
    }

    // User initilization
    if (!parseUserdata(patronFilePath)) { // Parsing failed
        cout << "ERROR: Initialization: Unable to open book file" << endl;
    }

    #ifdef DEBUG
    gettimeofday(&tim, NULL);
    double t2 = tim.tv_sec+(tim.tv_usec/1000000.0);
    printf("--Data loaded. Execution time: %.6lf seconds elapsed\n", t2-t1);
    #endif

    // Show view
    InitialView view(&cout);
    view.render(request);
}

bool InitController::parseBookdata(const string& filePath)
// Parse Book data
// Pre: filePath must be valid
// Post: Adds a list of books to the library system
{
    // Book initilization
    ifstream bookfile (filePath.c_str());
    if (!bookfile.is_open()) { // File open failed
        return false;
    } else { // Parse the book file
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

        // Iterate over every line of the book file
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

                if (BooksFiction::fetchBook(Config::CAT_FICTION, 
                                            fiction->key())) {
                    cerr << "ERROR: Initialize:"
                         << "Skipped duplicated book" <<endl;
                    delete fiction;
                    continue;
                }

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

                if (BooksPeriodical::fetchBook(Config::CAT_PERIODICAL,
                                               periodical->key())) {
                    cerr << "ERROR: Initialize:"
                         << "Skipped duplicated book" <<endl;
                    delete periodical;
                    continue;
                }

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

                if (BooksYouth::fetchBook(Config::CAT_YOUTH, youth->key())) {
                    cerr << "ERROR: Initialize:"
                         << "Skipped duplicated book" <<endl;
                    delete youth;
                    continue;
                }

                // Store in a collection
                booksYouth.append(youth);
            } else {
                // TODO(SOTA): ADD Error handling
                cerr << "ERROR: Initialize: Unrecognized Category ["
                << category << "]" <<endl;
            }
        }
        bookfile.close();
    }
    return true;
}

bool InitController::parseUserdata(const string& filePath)
// Parse User data
// Pre: filePath must be valid
// Post: Adds a list of users to the library system
{
    // get the file stream
    ifstream patronfile(filePath.c_str());
    if (!patronfile.is_open()) { // Faild to open the file
        return false;
    } else { // Opend the file
        int userID;
        string firstName;
        string lastName;
        string line;

        // Get instances of user collection
        Users& users = Users::getInstance();
        while (getline (patronfile, line)) {
            stringstream ss(line);
            ss >> userID;

            if (Users::fetchUser(userID)) {
                cerr << "ERROR: Initialize: UserID ["
                << userID << "] already exists." <<endl;
                continue;
            }

            ss >> lastName
               >> firstName;
           User* user = new User();
           user->setID(userID);
           user->setName(firstName, lastName);
           users.append(user);
        }
    }
    return true;
}

