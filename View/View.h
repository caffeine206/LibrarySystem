/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * View class is an output repeentaion of information.
 * This is an abstract class.
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

#ifndef __View_H
#define __View_H

#include <iomanip>  // setw, setFill,
#include "../lib/Config.h"
#include "../Collection/Collection.h"
#include "../lib/Request/CommandRequest.h"

using namespace std;

class View {
  public:
    // Counstructor
    View(ostream* o = NULL);
    // Virtual Destructor
    virtual ~View() {}
    // Render information
    virtual void render(Request* request = NULL) = 0;
    // Set ostream
    void setOstream(ostream* o);
  protected:
    // ostream
    ostream* out;
};

#endif
