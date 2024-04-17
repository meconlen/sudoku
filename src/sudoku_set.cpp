#include "sudoku_set.hpp"

const std::array<bool, 10> sudoku_set::empty_set {false, false, false, false, false, false, false, false, false, false};
const std::array<uint_fast8_t, 10> sudoku_set::iterator::values {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
const std::array<uint_fast8_t, 10> sudoku_set::const_iterator::values {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

