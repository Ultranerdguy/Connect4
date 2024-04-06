#include "ConnectX/Vector/Vector.hpp"

int VecExInequalTester(int argc, char** const argv) {
  using vector = ConnectX::VectorExpression::Vector<int>;

  vector greatest = {9,9,9};
  vector least = {-9,-9,-9};
  vector a = {1,2,3};
  vector large = {9,0,0};
  vector small = {-9,0,0};

  return (a > least) && (a < greatest) && (greatest >= large) && (least <= small) ? 0 : -1;
}