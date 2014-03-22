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

#ifndef __InitialView_H
#define __InitialView_H

#include "./View.h"

class InitialView : public View {
  public:
    // Constructor
    InitialView(ostream* o = NULL);
    // Destructor
    ~InitialView() {}
    // Render an initial welcome page.
    void render(Request* request = NULL);
  protected:
    // Drawing Helper
    void welcome();
};

#endif
