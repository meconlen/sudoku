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
         puzzle[i][j] = puzzle_entry_t(p[i][j], default_candidates);
      }
   }
}

bool sudoku::is_equal(const sudoku& other) const
{
   return puzzle == other.puzzle;
}

std::string sudoku::to_string() const
{
   std::ostringstream os;
   for(auto i = 0; i < 9; i++) {
      os << static_cast<unsigned>(puzzle[i][0].first) << " " << static_cast<unsigned>(puzzle[i][1].first) << " " << static_cast<unsigned>(puzzle[i][2].first) << " | " << static_cast<unsigned>(puzzle[i][3].first) << " " << static_cast<unsigned>(puzzle[i][4].first) << " " << static_cast<unsigned>(puzzle[i][5].first) << " | " << static_cast<unsigned>(puzzle[i][6].first) << " " << static_cast<unsigned>(puzzle[i][7].first) << " " << static_cast<unsigned>(puzzle[i][8].first)<< " " << std::endl;
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
         if(puzzle[i][j].first == 0) {
            std::set<uint_fast8_t> row_set, column_set, block_set;
            row_set = get_row(i);
            column_set = get_column(j);
            
            if(i < 3 && j < 3) {
               block_set = get_block(1);
            } else if (i < 3 && (j >=3 && j < 6)) {
               block_set = get_block(2);
            } else if (i < 3 && j >= 6) {
               block_set = get_block(3);
            } else if ( (i >= 3 && i < 6) && j < 3) {
               block_set = get_block(4);
            } else if ( (i >= 3 && i < 6) && (j >= 3 && j < 6)) {
               block_set = get_block(5);
            } else if ( (i >= 3 && i < 6) && j >= 6) {
               block_set = get_block(6);
            } else if (i >= 6 && j < 3) {
               block_set = get_block(7);
            } else if (i >= 6 && (j >= 3 && j < 6) ) {
               block_set = get_block(8);
            } else if (i >= 6 && j >= 6) {
               block_set = get_block(9);
            }

            puzzle[i][j].second = all_candidates;
            for(auto& x : row_set) {
               puzzle[i][j].second.erase(x);
            }
            for(auto& x : column_set) {
               puzzle[i][j].second.erase(x);
            }
            for(auto& x : block_set) {
               puzzle[i][j].second.erase(x);
            }
         }
      }
   }
   return;
}

void sudoku::solve_cell(uint_fast8_t row, uint_fast8_t column, uint_fast8_t value)
{
   puzzle[row][column].first = value;
   puzzle[row][column].second.clear();
   // remove candidate from the row and column
   for(auto k = 0; k < 9; k++) {
      // row i
      puzzle[row][k].second.erase(value);
      // column j
      puzzle[k][column].second.erase(value);
   }
   // we need to find the top left of the block. 
   uint_fast8_t first_row = row - (row % 3);
   uint_fast8_t first_column = column - (column % 3);
   // remove the candidate from the block
   for(auto k = first_row; k < first_row + 3; k++) {
      for(auto l = first_column; l < first_column + 3; l++) {
         puzzle[k][l].second.erase(value);
      }
   }
   return;
}

void sudoku::print() const
{
   std::cout << to_string() << std::endl;
}

std::set<uint_fast8_t> sudoku::get_row(uint_fast8_t r)
{
   std::set<uint_fast8_t> rv;
   for(auto i = 0; i < 9; i++) {
      rv.insert(puzzle[r][i].first);
   }
   rv.erase(0);
   return rv;
}

std::set<uint_fast8_t> sudoku::get_column(uint_fast8_t c)
{
   std::set<uint_fast8_t> rv;
   for(auto i = 0; i < 9; i++) {
      rv.insert(puzzle[i][c].first);
   }
   rv.erase(0);
   return rv;
}

std::set<uint_fast8_t> sudoku::get_block(uint_fast8_t b)
{
   std::set<uint_fast8_t> rv;
   uint_fast8_t first_row = 0;
   uint_fast8_t first_column = 0;
   switch(b) {
      case 1:
         first_row = 0;
         first_column = 0;
         break;
      case 2:
         first_row = 0;
         first_column = 3;
         break;
      case 3:
         first_row = 0; 
         first_column = 6;
         break;
      case 4:
         first_row = 3;
         first_column = 0;
         break;
      case 5:
         first_row = 3;
         first_column = 3;
         break;
      case 6:
         first_row = 3;
         first_column = 6;
         break;
      case 7:
         first_row = 6;
         first_column = 0;
         break;
      case 8:
         first_row = 6;
         first_column = 3; 
         break;
      case 9:
         first_row = 6;
         first_column = 6;
         break;
   }
   for(auto i = first_row; i < first_row + 3; i++) {
      for(auto j = first_column; j < first_column +3; j++) {
         rv.insert(puzzle[i][j].first);
      }
   }
   rv.erase(0);
   return rv;

}

sudoku::puzzle_input_data_t sudoku::get_puzzle() const
{
   puzzle_input_data_t p;

   for(auto i = 0; i < 9; i++) {
      for(auto j=0; j < 9; j++) {
         p[i][j] = puzzle[i][j].first;
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
            if(puzzle[i][j].first == 0 && puzzle[i][j].second.size() == 1) {
               solve_cell(i, j, *(puzzle[i][j].second.begin()));
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
         for(const auto& candidate : puzzle[i][j].second) {
            uint_fast8_t house_count = 0;
            // row i
            for(auto k = 0; k < 9; k++) {
               if(puzzle[i][k].second.contains(candidate)) { house_count++; }
            }
            if(house_count == 1) { 
               solve_cell(i, j, candidate); 
               break; // next cell
            }
            house_count = 0;
            for(auto k = 0; k < 9; k++) {
               if(puzzle[k][j].second.contains(candidate)) { house_count++; }
            }
            if(house_count == 1) {
               solve_cell(i, j, candidate); 
               break; // next cell
            }
            house_count = 0;
            uint_fast8_t first_row = i - (i % 3);
            uint_fast8_t first_column = j - (j % 3); 
            for(auto k = first_row; k < first_row + 3; k++) {
               for(auto l = first_column; l < first_column + 3; l++) {
                  if(puzzle[k][l].second.contains(candidate)) { house_count++; }                  
               }
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

// We find two cells in a house with the same pair of candidates which are not shared with another house
//

// for each house 
// compile a list of cells each candidate is in 
// candidate_cells[candidate] = set of cells in the house 
// for each candidate 
//    if there are two cells with that candidate 
//       if we find another candidate with the same pair of cells 
//          for those two cells fix the candidate list to be only those two candidates 

// this currently works for the test block 
// we need to extend this to a row and column
// and abstract out the first_row, first_column from a block
// now we need to handle naked_pairs 
void sudoku::find_hidden_pairs()
{
   // our first test case with this is p05
   // the hidden pair is found in a block 
   for(auto block = 0; block < 9; block++) {
      std::array<std::set<std::pair<value_t, value_t>>, 9> candidate_cells;
      uint_fast8_t first_row = 0;
      uint_fast8_t first_column = 0;
      switch(block) {
         case 1:
            first_row = 0;
            first_column = 0;
            break;
         case 2:
            first_row = 0;
            first_column = 3;
            break;
         case 3:
            first_row = 0; 
            first_column = 6;
            break;
         case 4:
            first_row = 3;
            first_column = 0;
            break;
         case 5:
            first_row = 3;
            first_column = 3;
            break;
         case 6:
            first_row = 3;
            first_column = 6;
            break;
         case 7:
            first_row = 6;
            first_column = 0;
            break;
         case 8:
            first_row = 6;
            first_column = 3; 
            break;
         case 9:
            first_row = 6;
            first_column = 6;
            break;
      }      
      // fill out the candidate list 
      for(value_t row = first_row; row < first_row + 3; row++) {
         for(value_t column = first_column; column < first_column + 3; column++) {
            for(const auto& candidate : puzzle[row][column].second) {
               candidate_cells[candidate - 1].insert({row, column});
            }
         }
      }
      // loop over the candidates to find ones with two cells 
      for(auto candidate = 1; candidate < 10; candidate++) {
         if(candidate_cells[candidate - 1].size() == 2) {
            // find another candidate with the same cell list 
            for(auto second_candidate = candidate + 1; second_candidate < 10; second_candidate++) {
               if(candidate_cells[candidate - 1] == candidate_cells[second_candidate - 1]) {
                  // we have a match, create a candidate set with the two candidates 
                  puzzle_candidate_t candidate_set;
                  candidate_set.insert(candidate);
                  candidate_set.insert(second_candidate);
                  // for each cell in candidate_cells[candidate - 1] set the puzzle[][].second to candidate_set
                  for(const auto& cell : candidate_cells[candidate - 1]) {
                     puzzle[cell.first][cell.second].second = candidate_set;
                  }
               }
            }
         }
      }
   }
   return;
}

// We need this for a row for p06
// currently only handles a row (since that's all we have a test for)

void sudoku::reduce_naked_pairs()
{
   for(value_t i = 0; i < 9; i++) {
      for(value_t j = 0; j < 9; j++) {
         if(puzzle[i][j].second.size() == 2) {
            // we have a pair
            // find the same pair after the current candidate 
            for(value_t k = j+1; k < 9; k++) {
               if(puzzle[i][j].second == puzzle[i][k].second) {
                  // we have the pair and that pair should only be candidates in [i][j] and [i][k]
                  for(value_t m = 0; m < 9; m++) {
                     // we skip the cells with the naked pair
                     if(m == j || m == k) continue;
                     for(const auto& candidate : puzzle[i][j].second) { puzzle[i][m].second.erase(candidate); }
                  }
               }
            }
         }
      }
   }
   return;
}

// this finds a pair (or triple) that is only in one row or column in a box. If so remove it from the row/column outside the box
// we currently only have a test case for a row 

// for each block
// look at each row(column)
// if there is a candidate which is only in a single row(column)
//    remove the candidate from the rest of the row 

void reduce_pointing_pairs()
{
   return;
}

void sudoku::solve_puzzle()
{
   while(true) {
      sudoku current_puzzle = puzzle;
      solve_single_candidates();
      solve_hidden_singles();
      find_hidden_pairs();
      reduce_naked_pairs();
      reduce_pointing_pairs();
      if(puzzle == current_puzzle) break; // we didn't update the puzzle this iteration. 
   }
   return;
}

bool sudoku::is_solved()
{
   for(auto i = 0; i < 9; i++) {
      for(auto j = 0; j < 9; j++) {
         if(puzzle[i][j].first == 0) return false;
      }
   }
   return true;
}

void sudoku::print_candidate(uint_fast8_t row, uint_fast8_t column) const
{
 
   for(auto it = puzzle[row][column].second.begin(); it != puzzle[row][column].second.end(); it++) {
      std::cout << static_cast<unsigned>(*it);
      if(std::next(it) != puzzle[row][column].second.end()) {
         std::cout << ", ";
      }
   }
}

void sudoku::print_differences(const sudoku& other) const
{
   for(auto i = 0; i < 9; i++) {
      for(auto j = 0; j < 9; j++) {
         if(puzzle[i][j] != other.puzzle[i][j]) {
            std::cout << "puzzle[" << i << "][" << j << "] = {" << static_cast<unsigned>(puzzle[i][j].first) << ", {";
            for(auto it = puzzle[i][j].second.begin(); it != puzzle[i][j].second.end(); it++) {
               std::cout << static_cast<unsigned>(*it); 
               if(std::next(it) != puzzle[i][j].second.end()) {
                  std::cout << ", ";
               }
            }
            std::cout << "} }" << std::endl;
            std::cout << "other.puzzle[" << i << "][" << j << "] = {" << static_cast<unsigned>(other.puzzle[i][j].first) << ", {";
            for(auto it = other.puzzle[i][j].second.begin(); it != other.puzzle[i][j].second.end(); it++) {
               std::cout << static_cast<unsigned>(*it); 
               if(std::next(it) != other.puzzle[i][j].second.end()) {
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
         if(puzzle[i][j].second.size() > 0) {
            std::cout << "puzzle[" << i << "][" << j << "] = { " << static_cast<unsigned>(puzzle[i][j].first) << " }, {";
            print_candidate(i, j);
            std::cout << "} }" << std::endl; 
         }
      }
   }
}

void sudoku::print_puzzle_cpp() const
{
   std::cout << "sudoku::puzzle_input_data_t p00 {{" << std::endl;
   for(auto i = 0; i < 9; i++) {
      std::cout << "   {";
      for(auto j = 0; j < 9; j++) {
         std::cout << static_cast<unsigned>(puzzle[i][j].first);
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
   std::cout << "}};" << std::endl;
}

void sudoku::print_puzzle_raw() const
{
   for(auto i = 0; i < 9; i++) {
      for(auto j = 0; j < 9; j++) {
         std::cout << static_cast<unsigned>(puzzle[i][j].first);
      }
      std::cout << std::endl;
   }
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
