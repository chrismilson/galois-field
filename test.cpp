#include <iostream>
#include "Galois.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
  Field test1(53);
  test1 = 7;

  cout << "test1 = " << test1 * test1 << endl;

  return 0;
}
