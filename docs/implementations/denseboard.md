# DenseBoard

A simple board implementation that stores the entire board as a single array. DenseBoard is not suited to large games or very high number of dimensions due to increasing memory cost.

## Constructor
- Takes two array (`ConnectX::Vector`) defining the start and end point of the board. The size of the board on each axis is equal to the end position minus the start position, plus 1 for inclusivity. The total number of spaces in the board is the product of all elements in the size vector, and the offsets can be calculated from the sizes from back to front.