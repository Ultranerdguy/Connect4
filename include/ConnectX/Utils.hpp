#ifndef _CONNECT_X_UTILS_HPP_
#define _CONNECT_X_UTILS_HPP_

#include "Types.hpp"

namespace ConnectX {
  Vector GetSizes(Vector const& start, Vector const& end);
  std::size_t FullSize(Vector const& start, Vector const& end);
  Vector GetOffsets(Vector const& sizes);
  
  std::size_t GetIndex(Vector const& position, Vector const& start, Vector const& end);
  std::size_t GetIndex(Vector const& relativePosition, Vector const& offsets);
}

#endif // #ifndef _CONNECT_X_UTILS_HPP_