#include "ConnectX/Vector/Vector.hpp"

int VecExNotTester(int argc, char** const argv) {
  using vector = ConnectX::VectorExpression::Vector<bool>;

  vector a = {true, true, false};
  vector expected = {false, false, true};

  return ((!a) == expected) ? 0 : -1;
}