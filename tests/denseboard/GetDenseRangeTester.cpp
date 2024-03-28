#include "ConnectX/DenseBoard.hpp"

ConnectX::Vector IndexToPosition_DenseRange(std::size_t const index) {
  return { (static_cast<ConnectX::VectorComponent>(index)/3) - 1,
    (static_cast<ConnectX::VectorComponent>(index)%3) - 1
  };
}

int GetDenseRangeTester(int argc, char** const argv) {
  using ConnectX::Equal;
  ConnectX::Vector const start = {-1,-1};
  ConnectX::Vector const end = {1,1};
  ConnectX::DenseBoard board(start, end);

  for (std::size_t i = 0; i < 9; ++i) {
    board.SetAt(IndexToPosition_DenseRange(i), static_cast<ConnectX::Token>(i));
  }

  ConnectX::Vector queryStart = {0,0};
  ConnectX::Vector queryEnd = {1,1};
  auto range = board.GetRange(queryStart, queryEnd);

  bool correct = Equal(range, {4,5,7,8});

  return correct ? 0 : -1;
}