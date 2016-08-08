#include "Galois.hpp"

Field::Field(int c) {
  val = 0;
  if (c < 0) c *= -1;
  cha = c;
}

int Field::getCha() {
  return cha;
}

Field::operator int() const {
  return val;
}

void Field::operator=(int v) {
  while (v < 0) {
    v += cha;
  }
  val = v % cha;
}

Field Field::operator+(int rhs) {
  Field sum(cha);
  sum = val + rhs;
  return sum;
}

Field Field::operator+(Field rhs) {
  if (rhs.getCha() != cha) throw IncompatibleField();
  Field sum(cha);
  sum = val + rhs;
  return sum;
}

Field Field::operator++() {
  val++;
  val %= cha;
  return *this;
}

Field Field::operator++(int) {
  Field tmp(*this);
  operator++();
  return tmp;
}

Field Field::operator-(int rhs) {
  Field sum(cha);
  sum = val - rhs;
  return sum;
}

Field Field::operator-() {
  Field sum(cha);
  sum = cha - val;
  return sum;
}

Field Field::operator-(Field rhs) {
  if (rhs.getCha() != cha) throw IncompatibleField();
  Field sum(cha);
  sum = val + (cha - rhs);
  return sum;
}

Field Field::operator--() {
  val += (cha - 1);
  val %= cha;
  return *this;
}

Field Field::operator--(int) {
  Field tmp(*this);
  operator--();
  return tmp;
}
