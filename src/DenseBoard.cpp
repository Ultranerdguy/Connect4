#include "ConnectX/DenseBoard.hpp"
#include "ConnectX/Utils.hpp"

ConnectX::DenseBoard::DenseBoard(ConnectX::Vector const& start, ConnectX::Vector const& end)
  : m_start{start}
  , m_end{end}
  , m_grid(FullSize(start, end), 0)
{
}

ConnectX::Vector ConnectX::DenseBoard::GetStart() const {
  return m_start;
}

ConnectX::Vector ConnectX::DenseBoard::GetEnd() const {
  return m_end;
}

ConnectX::Token ConnectX::DenseBoard::GetAt(Vector const& position) const {
  return m_grid[GetIndex(position, m_start, m_end)];
}

void ConnectX::DenseBoard::SetAt(Vector const& position, Token const token) {
  m_grid[GetIndex(position, m_start, m_end)] = token;
}

ConnectX::TokenBuffer ConnectX::DenseBoard::GetRange(Vector const& start, Vector const& end) const {
  ConnectX::Vector position = start;
  ConnectX::Vector rangeSize = GetSizes(start, end);
  std::size_t const size = position.Size();
  ConnectX::TokenBuffer output;
  if (size == 0) return output;

  bool running = true;
  while (running) {
    // Set to start of a contiguous space in memory
    position[size-1] = start[size-1];
    // Copy contiguous
    std::size_t const index = GetIndex(position, m_start, m_end);
    output.insert(output.end(), m_grid.begin() + index, m_grid.begin() + index + rangeSize[size-1]);

    // Escape if only need one write
    if (size < 2) break;
    // Iterate
    for (std::size_t i = 1; i < size; ++i) {
      std::size_t const p = size-i-1;
      if (start[p] == end[p]) continue;
      ++position[p];
      if (position[p] > end[p]) {
        position[p] = start[p];
        if (p == 0) {
          running = false;
        }
      }
      else {
        break;
      }
    }
  }

  return output;
}
