/*
Ensure that there is no overlap in any higher dimensional indexing methods
E.g. if SetAt({1,1,1}, 26) incorrectly overwrote SetAt({-1,-1,-1},0), that's a problem
*/

#include "ConnectX/DenseBoard.hpp"

ConnectX::Vector IndexToPositionAll(std::size_t const index) {
  return { (static_cast<ConnectX::VectorComponent>(index)/9) - 1,
    (static_cast<ConnectX::VectorComponent>(index)%9)/3 - 1,
    (static_cast<ConnectX::VectorComponent>(index)%3) - 1,
  };
}

int SetAllTester(int argc, char** const argv) {
  using ConnectX::Equal;
  ConnectX::Vector const start = {-1,-1,-1};
  ConnectX::Vector const end = {1,1,1};
  ConnectX::DenseBoard board(start, end);

  for (std::size_t i = 0; i < 27; ++i) {
    board.SetAt(IndexToPositionAll(i), static_cast<ConnectX::Token>(i));
  }
  
  // Reread to verify the integrity of the setter/getter methods
  bool correct = true;
  for (std::size_t i = 0; i < 27; ++i) {
    correct = Equal(board.GetAt(IndexToPositionAll(i)), static_cast<ConnectX::Token>(i));
    if (!correct) break;
  }

  return correct ? 0 : -1;
}