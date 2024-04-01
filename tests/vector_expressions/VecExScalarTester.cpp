#include "ConnectX/Vector/Vector.hpp"

int VecExScalarTester(int argc, char** const argv) {
  using vector = ConnectX::VectorExpression::Vector<int>;

  int a = 5;
  vector b = {2,5,8};

  vector lSumExpected = {7,10,13};
  vector rSumExpected = {7,10,13};
  vector lSubExpected = {3,0,-3};
  vector rSubExpected = {-3,0,3};
  vector lMulExpected = {10,25,40};
  vector rMulExpected = {10,25,40};
  vector lDivExpected = {2,1,0}; // integer division
  vector rDivExpected = {0,1,1}; // integer division

  bool allCorrect = (a+b) == lSumExpected
    && (b+a) == rSumExpected
    && (a-b) == lSubExpected
    && (b-a) == rSubExpected
    && (a*b) == lMulExpected
    && (b*a) == rMulExpected
    && (a/b) == lDivExpected
    && (b/a) == rDivExpected;

  return allCorrect ? 0 : -1;
}