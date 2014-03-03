#ifndef __Books_H
#define __Books_H

class Books : public Collection{
  public:
  Books();
  list getBooksByCatId(int category_id);
  virtural void apend(Model&);
  protected:
};

#endif
