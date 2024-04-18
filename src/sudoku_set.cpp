#include <array>
#include <iostream>
#include <ostream>
#include <string>

#include "sudoku_set.hpp"

std::ostream& operator<<(std::ostream& os, const sudoku_set& set)
{
   os << set.to_string(); 
   return os;
}
