/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * show a list of histories.
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

#ifndef __HistoryView_H
#define __HistoryView_H

#include "./View.h"
#include "../Collection/Users.h"

class HistoryView : public View {
  public:
    // Constructor
    HistoryView(ostream* o = NULL);
    // Destructor
    ~HistoryView() {}
    // Render a list of histories
    void render(Request* request = NULL);
  protected:
};

#endif
