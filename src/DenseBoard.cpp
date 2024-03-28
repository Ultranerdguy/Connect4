#include "ConnectX/DenseBoard.hpp"

namespace {
  ConnectX::Vector GetSizes(ConnectX::Vector const& start, ConnectX::Vector const& end) {
    std::size_t const size = start.size();
    ConnectX::Vector sizes(size, 0);
    for (std::size_t i = 0; i < size; ++i) {
      sizes[i] = end[i] - start[i] + 1;
    }
    return sizes;
  }
  
  std::size_t FullSize(ConnectX::Vector const& start, ConnectX::Vector const& end) {
    auto const sizes = GetSizes(start, end);
    std::size_t output = 1;
    for (auto& s : sizes) {
      output *= s;
    }
    return output;
  }

  ConnectX::Vector GetOffsets(ConnectX::Vector const& sizes) {
    std::size_t const size = sizes.size();
    ConnectX::Vector offsets(size, 1);
    for (std::size_t i = 1; i < size; ++i) {
      offsets[size-i-1] = offsets[size-i] * sizes[size-i];
    }
    return offsets;
  }

  std::size_t GetIndex(ConnectX::Vector const& position, ConnectX::Vector const& start, ConnectX::Vector const& end) {
    ConnectX::Vector const sizes = GetSizes(start, end);
    ConnectX::Vector const offsets = GetOffsets(sizes);

    std::size_t output = 0;
    std::size_t const size = sizes.size();
    for (std::size_t i = 0; i < size; ++i) {
      output += offsets[i] * (position[i] - start[i]);
    }

    return output;
  }
}

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
  std::size_t const size = position.size();
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
