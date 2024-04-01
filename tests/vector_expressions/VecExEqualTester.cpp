#include "ConnectX/Vector/Vector.hpp"

int VecExEqualTester(int argc, char** const argv) {
  using vector = ConnectX::VectorExpression::Vector<int>;

  vector a = {1,2,3};
  vector expected = {1,2,3};

  return (a == expected) ? 0 : -1;
}