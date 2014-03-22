/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * # SHHH LIBRARY SYSTEM DOCUMENTATION
 * By Sota Ogo, Derek Willms
 * 
 * ## Software architecture
 * We used MVC + Router as our software architecture. We utilize singleton 
 * to keep the data consitancy (Singleton shouldn't be use in a real project 
 * for data storing; however, our assumption is that this library system won't
 * be operated by multiple people at the same time.).
 * 
 * # Folder structure
 * ```
 * .
 * ├
 * ├── Collections // Collections
 * ├── Controller  // Controllers
 * ├── lib         // Utilities, Router, Request
 * │   └── Request // Request
 * ├── Model       // Models
 * │   └── Book    // Books
 * ├── tests       // Test specs for Unit test
 * └── View        // Views
 * ```
 * 
 * ## Explanation
 * 
 * ### Compile && execution
 * ```
 * make clean
 * make
 * ./shhh data4books.txt data4patrons.txt < data4commands.txt
 * ```
 * ### Class diagram
 * Please refer classdiagram.pdf to see our class design.
 * 
 * ### Data structure
 * We use Binary tree for book sorting, and Hash Table for searching. 
 * For history, we use linked list to keep track of user history.
 * 
 * ### Basic flow
 * 1. Everything starts from Router. View or main.cpp uses Router, 
 * in order to call controller.
 * 2. Controller updates the state of the software (Views and Models).
 * 
 * ### Router
 * Router manages which controller to be called from user command.
 * 
 * ### Controller
 * In controller, we implemented actions such as checkout, return, and display.
 * 
 * ### Model
 * Models represents all kinds of data (User, Book, History)
 * 
 * ### Collection
 * Collection represents a set of models. There are "Indexed" and "UnIndexed" 
 * for collections. They have different data structures.
 * 
 * ### View
 * View represents the system states. Any kinds of output except errors are 
 * generated in View.
 * 
 * ### Request
 * Request is a data parser utility class. It allows classes (Controller, View, 
 * Model) to have the same language (input structure).
 * 
 * ### Catch
 * Catch is a testing framework for c++. We used it for our unit testing.
 * To enable the debug mode, please uncomment a line in lib/Config.h
 * 
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

#include "./lib/Config.h"
#include "./lib/Router.h"
#include "./lib/Request/ArgumentRequest.h"

// Remove unit tests if it's not in DEBUG mode
#ifdef DEBUG
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#endif

int main( int argc, char *argv[] ) {
#ifdef DEBUG
    Catch::Session().run( );
#endif
    ArgumentRequest request;
    request.parse(argc, argv);
    Router& router = Router::getInstance();
    router.start(&request);
}
