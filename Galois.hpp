#ifndef GALOIS_H

#define GALOIS_H

#include <exception>

class Field {
private:
  int val;
  int cha;
public:
  Field(int);
  int getCha();
  operator int() const;
  void operator=(int);
  Field operator+(int);
  Field operator+(Field);
  Field operator++();
  Field operator++(int);
  Field operator-();
  Field operator-(int);
  Field operator-(Field);
  Field operator--();
  Field operator--(int);
};

class IncompatibleField: public std::exception {
  virtual const char* what() const throw() {
    return "Fields must be of the same order.";
  }
};

#endif
