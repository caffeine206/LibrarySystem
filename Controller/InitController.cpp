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

#include "./InitController.h"

InitController::InitController() {}

void InitController::exec(Request* request) {
    // string line;
    
    // ifstream myfile (request->get("bookText"));
    // if (myfile.is_open()) {
    //     while (getline (myfile,line)) {
    //         cout << line << '\n';
    //     }
    //     myfile.close();
    // } else {
    //     // TODO(SOTA): ADD Error handling
    //     cout << "Unable to open file";
    // }
    // cout << request->get("bookText") << endl;
    // cout << request->get("patronText") << endl;

    InitialView view;
    view.setOstream(&cout);
    view.render(NULL);
}
