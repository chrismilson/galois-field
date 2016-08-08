#ifndef GALOIS_H

#define GALOIS_H

#include <exception>

class Field {
private:
  int cha;
#ifdef POLYNOMIAL_H
  int q;
  Polynomial val;
#else
  int val;
#endif
  int isSuitable(int);
public:
  Field(int);
  int getCha();
  operator int() const;
  Field operator=(int);

  Field operator+(int);
  Field operator+(Field);
  Field operator+=(int);
  Field operator+=(Field);
  Field operator++();
  Field operator++(int);

  Field operator-();
  Field operator-(int);
  Field operator-(Field);
  Field operator-=(int);
  Field operator-=(Field);
  Field operator--();
  Field operator--(int);

  Field operator*(int);
  Field operator*(Field);
  Field operator*=(int);
  Field operator*=(Field);
};

class IncompatibleField: public std::exception {
  virtual const char* what() const throw() {
    return "Fields must be of the same order to operate on them";
  }
};

class InvalidFieldOrder: public std::exception {
  virtual const char* what() const throw() {
    return "Fields ";
  }
};

#endif
