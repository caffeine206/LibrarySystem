/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * Render an initial welcome page.
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

#include <sys/time.h>
#include "./InitialView.h"
#include "../lib/Router.h"

InitialView::InitialView(ostream* o) : View::View(o) {}

void InitialView::render(Request* request)
// shows a welcome message and start capturing the user input.
// PRE: Book & User data must be loaded before this being called.
{
    // Show a welcome message
    this->welcome();
    // Get a router instance
    Router& router = Router::getInstance();
    // Initiate command request.
    CommandRequest commandRequest;
    // Show a helper text
    string message = "Type your command (i.e. 'D' 'H 1xxx' ) here:";
    *(this->out) << endl << message << endl;

    // Get a user input until they push ctr-D
    string line;
    while (getline(cin, line)) {
      // Parse the command
      commandRequest.parse(line);

      #ifdef DEBUG
      // Time mesuring
      struct timeval tim;
      gettimeofday(&tim, NULL);
      double t1 = tim.tv_sec+(tim.tv_usec/1000000.0);
      #endif

      // pass the command request to router
      router.go(&commandRequest);

      *(this->out) << endl;

      #ifdef DEBUG
      gettimeofday(&tim, NULL);
      double t2 = tim.tv_sec+(tim.tv_usec/1000000.0);
      printf("-- Execution time: %.6lf seconds elapsed\n", t2-t1);
      cout << endl;
      #endif
    }
}

void InitialView::welcome()
// Draw a welcome message
{
    *(this->out)  << endl
                  << right
                  << setfill('*') << setw(70)
                  << "*"
                  << endl
                  << left
                  << setfill('*') << setw(15)
                  << "*"
                  << left
                  << setfill('*') << setw(55)
                  << "   WELCOME TO SHHH LIBRARY SYSTEM!!   "
                  << endl
                  << left
                  << setfill('*') << setw(70)
                  << "*"
                  << endl;
}
