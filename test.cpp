#include <iostream>
#include "Galois.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
  Field test1(7), test2(7);
  test1 = 7;
  test2 = 5;


  cout << "test1 = " << test1-- << endl;

  return 0;
}
