#include <iostream>
#include "Galois.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
  Field test1(7), test2(7);
  test1 = 5;
  test2 = 2;

  int sum = test1 + test2;
  cout << "5 + 2 = " << sum << endl;

  return 0;
}
