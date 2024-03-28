# Roadmap

- Implement a DenseBoard, consisting of a contiguous array of token
- Redesign ConnectX::Vector to utilise expression templates and separate it from std library
  - Still useful to provide it iterators, so will base it on std::vector, just not via inheritance
- Implement the default rules of connect4 into a ruleset
- Create a sparse board (empty cells not stored, maybe some run length encoding) for storing *really* large boards
- ???
