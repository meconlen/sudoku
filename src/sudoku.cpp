#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <utility>

#include "sudoku.hpp"

const sudoku::puzzle_candidate_t sudoku::default_candidates {};
const sudoku::puzzle_candidate_t sudoku::all_candidates {1, 2, 3, 4, 5, 6, 7, 8, 9};
const sudoku::puzzle_entry_t sudoku::empty_entry {0, default_candidates};
const sudoku::puzzle_row_t sudoku::empty_row {empty_entry, empty_entry, empty_entry, empty_entry, empty_entry, empty_entry, empty_entry, empty_entry, empty_entry};
const sudoku::puzzle_data_t sudoku::empty_puzzle {empty_row, empty_row, empty_row, empty_row, empty_row, empty_row, empty_row, empty_row, empty_row};


sudoku::sudoku(const puzzle_input_data_t& p)
{
   for(auto i = 0; i < 9; i++) {
      for(auto j = 0; j < 9; j++) {
         *puzzle[i][j] = puzzle_entry_t(p[i][j], default_candidates);
      }
   }
}

bool sudoku::is_equal(const sudoku& other) const
{

   return puzzle_data == other.puzzle_data;
}

std::string sudoku::to_string() const
{
   std::ostringstream os;
   for(auto i = 0; i < 9; i++) {
      os << static_cast<unsigned>(puzzle[i][0]->first) << " " << static_cast<unsigned>(puzzle[i][1]->first) << " " << static_cast<unsigned>(puzzle[i][2]->first) << " | " << static_cast<unsigned>(puzzle[i][3]->first) << " " << static_cast<unsigned>(puzzle[i][4]->first) << " " << static_cast<unsigned>(puzzle[i][5]->first) << " | " << static_cast<unsigned>(puzzle[i][6]->first) << " " << static_cast<unsigned>(puzzle[i][7]->first) << " " << static_cast<unsigned>(puzzle[i][8]->first)<< " " << std::endl;
      if(i % 3 == 2 && i != 8) {
         os << "------+-------+-------" << std::endl;
      }
   }
   return os.str();
}

std::string sudoku::to_string_transposed() const
{
   std::ostringstream os;
   for(auto i = 0; i < 9; i++) {
      os << static_cast<unsigned>(transposed_puzzle[i][0]->first) << " " << static_cast<unsigned>(transposed_puzzle[i][1]->first) << " " << static_cast<unsigned>(transposed_puzzle[i][2]->first) << " | " << static_cast<unsigned>(transposed_puzzle[i][3]->first) << " " << static_cast<unsigned>(transposed_puzzle[i][4]->first) << " " << static_cast<unsigned>(transposed_puzzle[i][5]->first) << " | " << static_cast<unsigned>(transposed_puzzle[i][6]->first) << " " << static_cast<unsigned>(transposed_puzzle[i][7]->first) << " " << static_cast<unsigned>(transposed_puzzle[i][8]->first)<< " " << std::endl;
      if(i % 3 == 2 && i != 8) {
         os << "------+-------+-------" << std::endl;
      }
   }
   return os.str();
}

void sudoku::set_candidates()
{
   for(auto i = 0; i < 9; i++) {
      for(auto j = 0; j < 9; j++) {
         if(puzzle[i][j]->first == 0) {
            std::set<value_t> row_set, column_set, block_set;
            row_set = get_row(i);
            column_set = get_column(j);
            value_t block_number = get_block_number(i, j);
            block_set = get_block(block_number);
            puzzle[i][j]->second = all_candidates;
            for(auto& x : row_set) {
               puzzle[i][j]->second.erase(x);
            }
            for(auto& x : column_set) {
               puzzle[i][j]->second.erase(x);
            }
            for(auto& x : block_set) {
               puzzle[i][j]->second.erase(x);
            }
         }
      }
   }
   return;
}

void sudoku::solve_cell(uint_fast8_t row, uint_fast8_t column, uint_fast8_t value)
{
   puzzle[row][column]->first = value;
   puzzle[row][column]->second.clear();
   // remove candidate from the row and column
   for(auto k = 0; k < 9; k++) {
      // row i
      puzzle[row][k]->second.erase(value);
      // column j
      puzzle[k][column]->second.erase(value);
   }
   // we need to find the top left of the block. 
   uint_fast8_t first_row = row - (row % 3);
   uint_fast8_t first_column = column - (column % 3);
   // remove the candidate from the block
   for(auto k = first_row; k < first_row + 3; k++) {
      for(auto l = first_column; l < first_column + 3; l++) {
         puzzle[k][l]->second.erase(value);
      }
   }
   return;
}

// get all the saved values in the row
std::set<uint_fast8_t> sudoku::get_row(uint_fast8_t r)
{
   std::set<uint_fast8_t> rv;
   for(auto i = 0; i < 9; i++) {
      rv.insert(puzzle[r][i]->first);
   }
   rv.erase(0);
   return rv;
}

// get all the saved values in the column
std::set<uint_fast8_t> sudoku::get_column(uint_fast8_t c)
{
   std::set<uint_fast8_t> rv;
   for(auto i = 0; i < 9; i++) {
      rv.insert(puzzle[i][c]->first);
   }
   rv.erase(0);
   return rv;
}

std::set<uint_fast8_t> sudoku::get_block(uint_fast8_t block)
{
   std::set<uint_fast8_t> rv;
   for(auto i = 0; i < 9; i++) {
      rv.insert(block_puzzle[block-1][i]->first);
   }
   rv.erase(0);
   return rv;
}

sudoku::puzzle_input_data_t sudoku::get_puzzle() const
{
   puzzle_input_data_t p;

   for(auto i = 0; i < 9; i++) {
      for(auto j=0; j < 9; j++) {
         p[i][j] = puzzle[i][j]->first;
      }
   }
   return p;
}

void sudoku::solve_single_candidates()
{
   while(true) {
      bool updated = false;
      for(auto i = 0; i < 9; i++) {
         for(auto j = 0; j < 9; j++) {
            if(puzzle[i][j]->first == 0 && puzzle[i][j]->second.size() == 1) {
               solve_cell(i, j, *(puzzle[i][j]->second.begin()));
               updated = true;
            }
         }
      }
      if(updated == false) break;
   }
   return;
}

void sudoku::solve_hidden_singles()
{
   // for each cell, for each candidate, check each house, if it is unique in any house then it's the solution for the cell
   for(auto i = 0; i < 9; i++) {
      for(auto j = 0; j < 9; j++) {
         for(const auto& candidate : puzzle[i][j]->second) {
            uint_fast8_t house_count = 0;
            // row i
            for(auto k = 0; k < 9; k++) {
               if(puzzle[i][k]->second.contains(candidate)) { house_count++; }
            }
            if(house_count == 1) { 
               solve_cell(i, j, candidate); 
               break; // next cell
            }
            house_count = 0;
            for(auto k = 0; k < 9; k++) {
               if(puzzle[k][j]->second.contains(candidate)) { house_count++; }
            }
            if(house_count == 1) {
               solve_cell(i, j, candidate); 
               break; // next cell
            }
            house_count = 0;
            value_t block_number = get_block_number(i, j);
            for(value_t k = 0; k < 9; k++) {
               if(block_puzzle[block_number - 1][k]->second.contains(candidate)) {house_count++; }
            }
            if(house_count == 1) {
               solve_cell(i, j, candidate); 
               break;
            }
         }
      }
   }
   return;
}

// we need an example for a block
// this only solves a hidden pair in a row and column

void sudoku::find_hidden_pairs(puzzle_data_p puzzle) 
{
   for(value_t i = 0; i < 9; i++) {
      std::array<std::set<value_t>, 9> candidate_cells;
      for(value_t j = 0; j < 9; j++) {
         for(const auto& candidate : puzzle[i][j]->second) {
            candidate_cells[candidate-1].insert(j);
         }
      }
      for(value_t candidate = 1; candidate < 10; candidate++) {
         if(candidate_cells[candidate-1].size() == 2) {
            for(value_t second_candidate = candidate+1; second_candidate < 10; second_candidate++) {
               if(candidate_cells[candidate-1] == candidate_cells[second_candidate-1]) {
                  for(const auto& j : candidate_cells[candidate-1]) {
                     puzzle[i][j]->second = {candidate, second_candidate};
                  }
               }
            }
         }
      }
   }
}

void sudoku::find_hidden_pairs()
{
   find_hidden_pairs(puzzle);
   find_hidden_pairs(transposed_puzzle);   
   return;
}

void sudoku::reduce_naked_pairs(puzzle_data_p puzzle)
{
   for(value_t i = 0; i < 9; i++) {
      for(value_t j = 0; j < 9; j++) {
         if(puzzle[i][j]->second.size() == 2) {
            // we have a pair
            // find the same pair after the current candidate 
            for(value_t k = j+1; k < 9; k++) {
               if(puzzle[i][j]->second == puzzle[i][k]->second) {
                  // we have the pair and that pair should only be candidates in [i][j] and [i][k]
                  for(value_t m = 0; m < 9; m++) {
                     // we skip the cells with the naked pair
                     if(m == j || m == k) continue;
                     for(const auto& candidate : puzzle[i][j]->second) { puzzle[i][m]->second.erase(candidate); }
                  }
               }
            }
         }
      }
   }   
   return;
}

void sudoku::reduce_naked_pairs()
{
   reduce_naked_pairs(puzzle);
   reduce_naked_pairs(transposed_puzzle);
   reduce_naked_pairs(block_puzzle);
   return;
}

// this finds a pair (or triple) that is only in one row or column in a box. If so remove it from the row/column outside the box
// for each block
// look at each row(column)
// if there is a candidate which is only in a single row(column)
//    remove the candidate from the rest of the row 

void sudoku::reduce_pointing_pairs(puzzle_data_p puzzle, value_t block)
{
   auto start = get_block_start(block);
   // for each candidate get a list of rows
   std::array<std::set<value_t>, 9> candidate_rows;
   for(value_t candidate = 1; candidate < 10; candidate++) {
      for(value_t i = start.first; i < start.first + 3; i++) {
         for(value_t j = start.second; j < start.second + 3; j++) {
            // for this cell for each candidate add i to the list
            for(const auto& candidate : puzzle[i][j]->second) {
               candidate_rows[candidate-1].insert(i);
            }
         }
      }
      // now we know which rows each candidate appears in
      for(value_t candidate = 1; candidate < 10; candidate++) {
         // for the candidate we see if there's only one row 
         if(candidate_rows[candidate-1].size() == 1) {
            // the canddiate is in a single row
            value_t i = *(candidate_rows[candidate-1].begin());
            for(value_t j = 0; j < 9; j++) {
               if(j < start.second || j >= start.second + 3) {
                  // remove the candidate if we are outside the block
                  puzzle[i][j]->second.erase(candidate);
               }
            }
         }
      }
   }
}

void sudoku::reduce_pointing_pairs()
{
   // for each block
   for(value_t block = 1; block < 10; block++) {
      reduce_pointing_pairs(puzzle, block);
      reduce_pointing_pairs(transposed_puzzle, block);
   }
   return;
}

void sudoku::reduce_box_line(puzzle_data_p puzzle)
{
   // for each row/column
   // record which block a candidate is in 
   // if the candidate is only in one box for that row/column
   // remove the candidate from other rows/columns in that box
   for(value_t i = 0; i < 9; i++) {
      std::array<std::set<value_t>, 9> candidate_block;
      for(value_t j = 0; j < 9; j++) {
         value_t block = get_block_number(i, j);
         for(const auto& candidate : puzzle[i][j]->second) {
            candidate_block[candidate-1].insert(block);
         }
      }
      for(value_t candidate = 1; candidate < 10; candidate++) {
         if(candidate_block[candidate-1].size() == 1) {
            auto start = get_block_start(*(candidate_block[candidate-1].begin()));
            for(value_t m = start.first; m < start.first + 3; m++) {
               for(value_t n = start.second; n < start.second + 3; n++) {
                  if(m == i) continue;
                  puzzle[m][n]->second.erase(candidate);
               }
            }
         }
      }
   }
   return;
}

void sudoku::reduce_box_line()
{
   reduce_box_line(puzzle);
   reduce_box_line(transposed_puzzle);
   return;
}

// for each row 
// collect the columns for each candidate
// if there is a candidate in two columns 
// find another row with that candidate in the same columns 
// if we find a match remove the candidate from those columns in other rows

void sudoku::reduce_x_wing(puzzle_data_p puzzle)
{
   for(value_t i = 0; i < 9; i++) {
      std::array<std::set<value_t>, 9> candidate_columns;
      for(value_t j = 0; j < 9; j++) {
         for(const auto& candidate : puzzle[i][j]->second) {
            candidate_columns[candidate-1].insert(j);
         }
      }
      for(value_t candidate = 1; candidate < 10; candidate++) {
         if(candidate_columns[candidate-1].size() == 2) {
            for(value_t k = i+1; k < 9; k++) {
               std::array<std::set<value_t>, 9> k_candidate_columns;
               for(value_t l = 0; l < 9; l++) {
                  for(const auto& candidate : puzzle[k][l]->second) {
                     k_candidate_columns[candidate-1].insert(l);
                  }
               }
               if(candidate_columns[candidate-1] == k_candidate_columns[candidate-1]) {
                  for(value_t m = 0; m < 9; m++) {
                     if(m == i || m == k) continue;
                     for(const auto& column : candidate_columns[candidate-1]) {
                        puzzle[m][column]->second.erase(candidate);
                     }
                  }   
               }
            }
         }
      }
   }
   return;
}

void sudoku::reduce_x_wing()
{
   reduce_x_wing(puzzle);
   reduce_x_wing(transposed_puzzle);
   return;
}

void sudoku::solve_puzzle()
{
   while(true) {
      puzzle_data_t current_puzzle_data = puzzle_data;
      solve_single_candidates();
      if(puzzle_data != current_puzzle_data) continue;
      if(is_solved()) break;
      solve_hidden_singles();
      if(puzzle_data != current_puzzle_data) continue;
      if(is_solved()) break;
      find_hidden_pairs();
      if(puzzle_data != current_puzzle_data) continue;
      if(is_solved()) break;
      reduce_naked_pairs();
      if(puzzle_data != current_puzzle_data) continue;
      if(is_solved()) break;
      reduce_pointing_pairs();
      if(puzzle_data != current_puzzle_data) continue;
      if(is_solved()) break;
      reduce_box_line();
      if(puzzle_data != current_puzzle_data) continue;
      if(is_solved()) break;
      reduce_x_wing();
      if(puzzle_data == current_puzzle_data) break; // we didn't update the puzzle this iteration. 
   }
   return;
}

bool sudoku::is_solved()
{
   for(auto i = 0; i < 9; i++) {
      for(auto j = 0; j < 9; j++) {
         if(puzzle[i][j]->first == 0) return false;
      }
   }
   return true;
}

void sudoku::print_candidate(uint_fast8_t row, uint_fast8_t column) const
{
 
   for(auto it = puzzle[row][column]->second.begin(); it != puzzle[row][column]->second.end(); it++) {
      std::cout << static_cast<unsigned>(*it);
      if(std::next(it) != puzzle[row][column]->second.end()) {
         std::cout << ", ";
      }
   }
}

void sudoku::print_differences(const sudoku& other) const
{
   for(auto i = 0; i < 9; i++) {
      for(auto j = 0; j < 9; j++) {
         if(puzzle_data[i][j] != other.puzzle_data[i][j]) {
            std::cout << "puzzle[" << i << "][" << j << "] = {" << static_cast<unsigned>(puzzle[i][j]->first) << ", {";
            for(auto it = puzzle[i][j]->second.begin(); it != puzzle[i][j]->second.end(); it++) {
               std::cout << static_cast<unsigned>(*it); 
               if(std::next(it) != puzzle[i][j]->second.end()) {
                  std::cout << ", ";
               }
            }
            std::cout << "} }" << std::endl;
            std::cout << "other.puzzle[" << i << "][" << j << "] = {" << static_cast<unsigned>(other.puzzle[i][j]->first) << ", {";
            for(auto it = other.puzzle[i][j]->second.begin(); it != other.puzzle[i][j]->second.end(); it++) {
               std::cout << static_cast<unsigned>(*it); 
               if(std::next(it) != other.puzzle[i][j]->second.end()) {
                  std::cout << ", ";
               }
            }
            std::cout << "} }" << std::endl;
         }
      }
   }
}

void sudoku::print_blanks() const
{
   for(auto i = 0; i < 9; i++) {
      for(auto j = 0; j < 9; j++) {
         if(puzzle[i][j]->second.size() > 0) {
            std::cout << "puzzle[" << i << "][" << j << "] = { " << static_cast<unsigned>(puzzle[i][j]->first) << " }, {";
            print_candidate(i, j);
            std::cout << "} }" << std::endl; 
         }
      }
   }
}

void sudoku::print_puzzle_cpp(std::string var_name) const
{
   std::cout << "   sudoku::puzzle_input_data_t " << var_name << " {{" << std::endl;
   for(auto i = 0; i < 9; i++) {
      std::cout << "      {";
      for(auto j = 0; j < 9; j++) {
         std::cout << static_cast<unsigned>(puzzle[i][j]->first);
         if(j < 8) {
            std::cout << ",";
         }
      }      
      std::cout << "}";
      if(i < 8) {
         std::cout << ",";
      }
      std::cout << std::endl;
   }
   std::cout << "   }};" << std::endl;
}

void sudoku::print() const
{
   std::cout << to_string() << std::endl;
}

void sudoku::print_transposed() const
{
   std::cout << to_string_transposed() << std::endl;
}

void sudoku::print_puzzle_raw() const
{
   for(auto i = 0; i < 9; i++) {
      for(auto j = 0; j < 9; j++) {
         std::cout << static_cast<unsigned>(puzzle[i][j]->first);
      }
      std::cout << std::endl;
   }
}

void sudoku::print_puzzle_candidates_cpp(std::string var_name) const 
{
   std::cout << "   sudoku::puzzle_data_t " << var_name << " {{ // puzzle" << std::endl;
   for(auto i = 0; i < 9; i++) {
      std::cout << "      {{ // row " << i+1 << std::endl;;
      for(auto j = 0; j < 9; j++) {
         std::cout << "         { " << static_cast<unsigned>(puzzle[i][j]->first) << ", ";
         if(puzzle[i][j]->second.size() > 0) {
            std::cout << "{{ ";
            for(auto it = puzzle[i][j]->second.begin(); it != puzzle[i][j]->second.end(); it++) {
               std::cout << static_cast<unsigned>(*it);
               if(std::next(it) != puzzle[i][j]->second.end()) {
                  std::cout << ", ";
               }
            }
            std::cout << " }} }";
         } else {
            std::cout << " sudoku::default_candidates }";
         }
         if(j < 8) {
            std::cout << ",";
         }
         std::cout << std::endl;
      }      
      std::cout << "      }}";
      if(i < 8) {
         std::cout << ",";
      }
      std::cout << std::endl;
   }
   std::cout << "   }};" << std::endl;
}

sudoku::value_t sudoku::get_block_number(value_t row, value_t column)
{
            value_t block = 0;
            if(row < 3 && column < 3) {
               block = 1;
            } else if (row < 3 && (column >=3 && column < 6)) {
               block = 2;
            } else if (row < 3 && column >= 6) {
               block = 3;
            } else if ( (row >= 3 && row < 6) && column < 3) {
               block = 4;
            } else if ( (row >= 3 && row < 6) && (column >= 3 && column < 6)) {
               block = 5;
            } else if ( (row >= 3 && row < 6) && column >= 6) {
               block = 6;
            } else if (row >= 6 && column < 3) {
               block = 7;
            } else if (row >= 6 && (column >= 3 && column < 6) ) {
               block = 8;
            } else if (row >= 6 && column >= 6) {
               block = 9;
            }
            return block;

}

std::pair<sudoku::value_t, sudoku::value_t> sudoku::get_block_start(value_t block)
{
   std::pair<value_t, value_t> start;
   switch(block) {
      case 1:
         start.first = 0;
         start.second = 0;
         break;
      case 2:
         start.first = 0;
         start.second = 3;
         break;
      case 3:
         start.first = 0; 
         start.second = 6;
         break;
      case 4:
         start.first = 3;
         start.second = 0;
         break;
      case 5:
         start.first = 3;
         start.second = 3;
         break;
      case 6:
         start.first = 3;
         start.second = 6;
         break;
      case 7:
         start.first = 6;
         start.second = 0;
         break;
      case 8:
         start.first = 6;
         start.second = 3; 
         break;
      case 9:
         start.first = 6;
         start.second = 6;
         break;
   }         
   return start;
}

bool operator==(const sudoku& lhs, const sudoku& rhs) 
{
   return lhs.is_equal(rhs);
}

std::ostream& operator<<(std::ostream& os, const sudoku& s)
{
   os << s.to_string() << std::endl;
   return os;
}
