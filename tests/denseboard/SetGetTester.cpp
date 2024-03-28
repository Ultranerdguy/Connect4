#include "ConnectX/DenseBoard.hpp"

int SetGetTester(int argc, char** const argv) {
  using ConnectX::Equal;
  ConnectX::Vector const start = {-5,-5,-5};
  ConnectX::Vector const end = {5,5,5};
  ConnectX::DenseBoard board(start, end);

  ConnectX::Vector const position = {1,2,3};
  ConnectX::Token const token = 7;
  board.SetAt(position, token);

  return Equal(board.GetAt(position), token) ? 0 : -1;
}