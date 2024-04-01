#include "ConnectX/Vector/Vector.hpp"

int VecExDivTester(int argc, char** const argv) {
  using vector = ConnectX::VectorExpression::Vector<int>;

  vector a = {3,15,20};
  vector b = {1,3,-10};
  vector expected = {3,5,-2};

  return ((a/b) == expected) ? 0 : -1;
}