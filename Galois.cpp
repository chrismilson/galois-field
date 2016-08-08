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

Field Field::operator+(Field rhs) {
  if (rhs.getCha() != cha) throw IncompatibleField();
  Field sum(cha);
  sum = val + rhs;
  return sum;
}
