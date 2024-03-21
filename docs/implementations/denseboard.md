# DenseBoard

A simple board implementation that stores the entire board as a single array. DenseBoard is not suited to large games or very high number of dimensions due to increasing memory cost.

## Constructor
- Takes an array (`ConnectX::Vector`) of sizes to construct the board with. Each element corresponds to the size of the board at that dimensional index (i.e. `sizes[0]` is the size of the `0`th dimension, usually `X`, `sizes[1]` for the `1`st dimension, usually `Y`, etc). The total number of spaces in the board is the product of all elements in the size vector, and the offsets can be calculated from the sizes from back to front.