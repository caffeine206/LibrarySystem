#ifndef __View_H
#define __View_H

#include <iomanip>  // setw, setFill,
#include "../lib/Config.h"
#include "../Collection/Collection.h"
#include "../lib/Request/CommandRequest.h"

using namespace std;

class View {
  public:
    View();
    View(ostream* o = NULL);
    virtual ~View();
    virtual void render(Request* request = NULL) = 0;
    void setOstream(ostream* o);
  protected:
    ostream* out;
};

#endif
