#include "ConnectX/DenseBoard.hpp"

int StartEndTester(int argc, char** const argv) {
  using ConnectX::Equal;
  ConnectX::Vector start = {-5,-5,-5};
  ConnectX::Vector end = {5,5,5};
  ConnectX::DenseBoard board(start, end);

  return Equal(board.GetStart(), start)
    && Equal(board.GetEnd(), end) ? 0 : -1;
}