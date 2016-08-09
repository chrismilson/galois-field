#include <iostream>
#include "Galois.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
  Field test1(7);
  test1 = 3;

  cout << "This is an example of a finite field of order 7." << endl;
  cout << "In GF(7), 3 + 3 = " << test1 + test1 << ", ";
  cout << "-3 = " << -test1 << ", ";
  cout << "and (the multiplicative inverse of 3) 1 / 3 = " << test1.inv() << endl;

  cout << endl;

  cout << "Be careful when trying to work with Fields of different order!" << endl;
  try {
    Field test2(5), test3(11);
    Field test4 = test2 + test3;
  } catch (IncompatibleField e) {
    cout << "Fields must be of the same order to operate on the elements in them." << endl;
  }

  cout << endl;

  cout << "Also, be careful when constructing Fields of non-prime order." << endl;
  cout << "There are only finite fields of order p^q where p is prime and q is a natural number." << endl;
  try {
    Field nonPrime(9);
  } catch (InvalidFieldOrder e) {
    cout << "In this implementation however, we can only deal with fields of PRIME order." << endl;
  }

  return 0;
}
