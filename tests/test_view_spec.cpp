
#include "../Model/Book/Periodical.h"
#include "../Model/Book/Fiction.h"
#include "../Model/Book/Youth.h"
#include "../Model/History.h"
#include "../Model/User.h"
#include "../Collection/Books.h"
#include "../Collection/Histories.h"
#include "../Collection/Users.h"
#include "../View/TextView.h"


#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include "catch.hpp"

using namespace std;

TEST_CASE("0-1 ListView", "[view]") {
    Fiction* fiction = new Fiction();
    fiction->setYear(2014);
    fiction->setAuthor("Sota Ogo");
    fiction->setTitle("A Japanese Guy");

    Fiction* fiction2 = new Fiction();
    fiction2->setYear(2013);
    fiction2->setAuthor("Long Author Name Yayyyy abcdefghijklmnopqrstuvwxyz");
    fiction2->setTitle("Long Title Yayyyyabcdefghijklmnopqrstuvwxyz");

    Books books;
    books.append(fiction);
    books.append(fiction2);

    fiction->rentOut();

    TextView textView(&cout);
    textView.headerFiction();

    for (set<Model*>::iterator it = books.begin();
        it != books.end(); ++it) {
        textView.draw(static_cast<Fiction *>(*it));
    }
}
