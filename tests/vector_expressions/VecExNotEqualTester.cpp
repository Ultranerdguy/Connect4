#include "ConnectX/Vector/Vector.hpp"

int VecExNotEqualTester(int argc, char** const argv) {
  using vector = ConnectX::VectorExpression::Vector<int>;

  vector a = {1,2,3};
  vector b = {4,5,6};

  return (a != b) ? 0 : -1;
}