#include "ConnectX/Utils.hpp"

ConnectX::Vector ConnectX::GetSizes(ConnectX::Vector const& start, ConnectX::Vector const& end) {
  return end-start+1;
}

std::size_t ConnectX::FullSize(ConnectX::Vector const& start, ConnectX::Vector const& end) {
  auto const sizes = GetSizes(start, end);
  std::size_t output = 1;
  for (auto& s : sizes) {
    output *= s;
  }
  return output;
}

ConnectX::Vector ConnectX::GetOffsets(ConnectX::Vector const& sizes) {
  std::size_t const size = sizes.Size();
  ConnectX::Vector offsets(size, 1);
  for (std::size_t i = 1; i < size; ++i) {
    offsets[size-i-1] = offsets[size-i] * sizes[size-i];
  }
  return offsets;
}

std::size_t ConnectX::GetIndex(ConnectX::Vector const& position, ConnectX::Vector const& start, ConnectX::Vector const& end) {
  ConnectX::Vector const sizes = GetSizes(start, end);
  ConnectX::Vector const offsets = GetOffsets(sizes);
  return GetIndex(position-start, offsets);
}

std::size_t ConnectX::GetIndex(ConnectX::Vector const& relativePosition, ConnectX::Vector const& offsets) {
  std::size_t output = 0;
  std::size_t const size = offsets.Size();
  for (std::size_t i = 0; i < size; ++i) {
    output += offsets[i] * relativePosition[i];
  }
  return output;
}