#include "ConnectX/Types.hpp"

template <>
bool ConnectX::Equal<ConnectX::SingleMove>(ConnectX::SingleMove const& lhs, ConnectX::SingleMove const& rhs) {
  return Equal(lhs.token, rhs.token)
    && Equal(lhs.pController, rhs.pController)
    && Equal(lhs.position, rhs.position);
}

std::istream& operator>>(std::istream& input, ConnectX::Vector& vector) {
  if (!input) return input;
  while (true) {
    std::istream::pos_type start = input.tellg();
    ConnectX::VectorComponent value{};
    if (!(input >> value)) {
      // Only reset if the formatting was bad
      if (input.fail()) {
        input.seekg(start);
        input.clear();
      }
      break;
    }
    vector.Append(value);

    // Skip commas
    start = input.tellg();
    char c{};
    if (!(input >> c) || c != ',') {
      if (input.fail() || c != ',') {
        input.seekg(start);
        input.clear();
      }
      break;
    }
  }
  if (vector.IsEmpty()) {
    input.setstate(std::ios_base::failbit);
  }
  return input;
}

std::ostream& operator<<(std::ostream& output, ConnectX::Vector const& vector) {
  std::size_t const size = vector.Size();
  for (std::size_t i = 0; i < size; ++i) {
    output << vector[i];
    if ((i+1) != size) output << ", ";
  }
  return output;
}