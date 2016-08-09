#include "Galois.hpp"

int Field::isSuitable(int c) {
  int i;
  int power = 1;
  for (i = 2; i * i <= c; i++) {
    if (!(c % i)) {
#ifdef POLYNOMIAL_H
      while (c != 1) {
        if (c % i) {
          return 0;
        }
        c /= i;
        power++;
      }
      return power;
#else
      return 0;
#endif
    }
  }

  return power;
}

Field::Field(int c) {
#ifdef POLYNOMIAL_H
  if (!(q = isSuitable(c))) throw InvalidFieldOrder();
#else
  if (!(isSuitable(c))) throw InvalidFieldOrder();
#endif
  cha = c;
  val = 0;
}

int Field::getCha() {
  return cha;
}

Field::operator int() const {
  return val;
}

Field Field::operator=(int v) {
  val = v % cha;
  if (val < 0) val += cha;
  return *this;
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

Field Field::operator+=(int v) {
  val += v;
  val %= cha;
  return *this;
}

Field Field::operator+=(Field v) {
  if (v.getCha() != cha) throw IncompatibleField();
  val += v;
  val %= cha;
  return *this;
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

Field Field::operator-=(int v) {
  val -= v;
  val %= cha;
  if (val < 0) val += cha;
  return *this;
}

Field Field::operator-=(Field v) {
  if (v.getCha() != cha) throw IncompatibleField();
  val -= v;
  val %= cha;
  if (val < 0) val += cha;
  return *this;
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



Field Field::operator*(int v) {
  Field product(cha);
  product = val * v;
  return product;
}

Field Field::operator*(Field v) {
  if (v.getCha() != cha) throw IncompatibleField();
  Field product(cha);
  product = val * v;
  return product;
}

Field Field::operator*=(int v) {
  val *= v;
  val %= cha;
  if (val < 0) val += cha;
  return *this;
}

Field Field::operator*=(Field v) {
  if (v.getCha() != cha) throw IncompatibleField();
  val *= v;
  val %= cha;
  if (val < 0) val += cha;
  return *this;
}

Field Field::operator/(Field v) {
  if (v.getCha() != cha) throw IncompatibleField();
  Field quotient(cha);
  int inverseV = 0;
  while (inverseV++ != cha) {
    if ((inverseV * v) % cha == 1) break;
  }
  quotient = inverseV * val;
  return quotient;
}

Field Field::operator/=(Field v) {
  if (v.getCha() != cha) throw IncompatibleField();
  int inverseV = 0;
  while (inverseV++ != cha) {
    if ((inverseV * v) % cha == 1) break;
  }
  val *= inverseV;
  return *this;
}

Field Field::inv() {
  Field quotient(cha);
  int inverseV = 0;
  while (inverseV++ != cha) {
    if ((inverseV * val) % cha == 1) break;
  }
  quotient = inverseV;
  return quotient;
}
