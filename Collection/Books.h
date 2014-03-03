#ifndef __Books_H
#define __Books_H

class Books : public Collection{
  public:
  Books();
  Model[] getBooksByCatId(int category_id);
  protected:
};

#endif
