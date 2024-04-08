#include "ConnectX/Vector/Vector.hpp"

int VecExMinMaxTester(int argc, char** const argv) {
  using vector = ConnectX::VectorExpression::Vector<int>;

  vector a = {1,5,9};
  vector b = {2,7,3};

  vector minVec = ConnectX::Min(a,b);
  vector maxVec = ConnectX::Max(a,b);

  vector minExpected = {1,5,3};
  vector maxExpected = {2,7,9};

  return (minVec == minExpected)
    && (maxVec == maxExpected) ? 0 : -1;
}