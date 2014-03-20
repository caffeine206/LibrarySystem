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

#include <sys/time.h> 

#include "./InitialView.h"
#include "../lib/Router.h"

InitialView::InitialView(ostream* o) : View::View(o) {}

void InitialView::render(Request* request) {
    this->welcome();
    Router& router = Router::getInstance();
    CommandRequest commandRequest;
    string line;
    string message = "Type your command (i.e. 'D' 'H 1xxx' ) here:";
    cout << endl << message << endl;

  // hash1("100000000000");

    while (getline(cin, line)) {
      commandRequest.parse(line);
      // Time mesuring
      struct timeval tim;  
      gettimeofday(&tim, NULL);  
      double t1=tim.tv_sec+(tim.tv_usec/1000000.0);  

      // Execution
      router.go(&commandRequest);

      gettimeofday(&tim, NULL);  
      double t2=tim.tv_sec+(tim.tv_usec/1000000.0);  
      printf("-- Execution time: %.6lf seconds elapsed\n", t2-t1);  
    }
}

void InitialView::welcome() {
    *(this->out)  << endl
                  << right
                  << setfill('*') << setw(80) 
                  << "*"
                  << endl
                  << left
                  << setfill('*') << setw(20)
                  << "*"
                  << left
                  << setfill('*') << setw(60)
                  << "   WELCOME TO SHHH LIBRARY SYSTEM!!   "
                  << endl
                  << left
                  << setfill('*') << setw(80)
                  << "*"
                  << endl;
}
