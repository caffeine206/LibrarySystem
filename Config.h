#ifndef __Config_H
#define __Config_H

class Config {
public:
  static bool debug = true;
  static string inputFile = 'data/input.txt';
  static string userData = 'data/user.txt';
  static string BookData = 'data/book.txt';
  static string [] CATGORIES = [
                                'Children\'s book',
                                'Fiction',
                                'Periodicals',
                                ];
  static string [] CATGORIES_HARDCOPY = [5, 5, 1];
protected:
};

#endif
