#include "ConnectX/Vector/Vector.hpp"

int VecExChainedOperationTester(int argc, char** const argv) {
  using vector = ConnectX::VectorExpression::Vector<int>;

  int i = 4;
  vector a = {1,1,1};
  vector b = {2,3,4};
  vector c = {4,3,2};
  vector d = {2,4,6};

  vector expected = {1, -1, -2};
  
  bool correct = (a + b * c / d - i) == expected;

  return correct ? 0 : -1;
}