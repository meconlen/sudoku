#include <algorithm>
#include <iostream>
#include <iterator>
#include <regex>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

#include "sudoku.hpp"

// NB: This code is very C-like but after attempting to rewrite much of it using iterators and C++ algorithms I don't belive it's valueable in this case.
// The reason is that we often need to do a computation or call a method with knowledge of what row/column we are acting on. The variables 
// i, j (or k, l or m, n) have good semantic meaning as indexes to a row/column of a matrix, which in the context of a Sudoku puzzle conveys meaning. 

// We often need to know the row or column we are working with, for example, given a candidate cell with two candidates, if we wish to find 
// a naked pair we must work with the row, column and block we are in. With an iterator we lose that information. We can reconstruct it each time if we must but 
// that makes the code harder to read and more care must be taken to compute that properly.

// Further, when was the last time you thought the following was a good idea
// std::array<puzzle_entry_t, 81> p = reinterpret_cast<std::array<puzzle_entry_t, 81>>(puzzle_data);
// which is used to then compute your indexes by doing &(*current) - &p[0] to get your current offset. 
// likewise if you have const puzzle_data_t x in a lambda you compute x - &p[0]; 

const sudoku::puzzle_candidate_t sudoku::default_candidates {};
const sudoku::puzzle_candidate_t sudoku::all_candidates {{1, 2, 3, 4, 5, 6, 7, 8, 9}};
const sudoku::puzzle_entry_t sudoku::empty_entry {0, default_candidates};
const sudoku::puzzle_row_t sudoku::empty_row {{empty_entry, empty_entry, empty_entry, empty_entry, empty_entry, empty_entry, empty_entry, empty_entry, empty_entry}};
const sudoku::puzzle_data_t sudoku::empty_puzzle {{empty_row, empty_row, empty_row, empty_row, empty_row, empty_row, empty_row, empty_row, empty_row}};


sudoku::sudoku(const puzzle_input_data_t& p)
{
   for(std::size_t i = 0; i < 9; i++) {
      for(std::size_t j = 0; j < 9; j++) {
         puzzle_data[i][j] = puzzle_entry_t(p[i][j], default_candidates);
         if(puzzle_data[i][j].first > 0) ++solved_cells;
      }
   }
}

sudoku::sudoku(const std::string& p)
{
   auto it = p.begin();
   for(value_t i = 0; i < 9; i++) {
      for(value_t j = 0; j < 9; j++) {
         puzzle_data[i][j].first = *it++ - '0';
         if(puzzle_data[i][j].first > 0) ++solved_cells;
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
   for(std::size_t i = 0; i < 9; i++) {
      os << static_cast<unsigned>(puzzle_data[i][0].first) << " " << static_cast<unsigned>(puzzle_data[i][1].first) << " " << static_cast<unsigned>(puzzle_data[i][2].first) << " | " << static_cast<unsigned>(puzzle_data[i][3].first) << " " << static_cast<unsigned>(puzzle_data[i][4].first) << " " << static_cast<unsigned>(puzzle_data[i][5].first) << " | " << static_cast<unsigned>(puzzle_data[i][6].first) << " " << static_cast<unsigned>(puzzle_data[i][7].first) << " " << static_cast<unsigned>(puzzle_data[i][8].first)<< " " << std::endl;
      if(i % 3 == 2 && i != 8) {
         os << "------+-------+-------" << std::endl;
      }
   }
   return os.str();
}

std::string sudoku::to_string_transposed() const
{
   std::ostringstream os;
   for(std::size_t i = 0; i < 9; i++) {
      os << static_cast<unsigned>(puzzle_data[0][i].first) << " " << static_cast<unsigned>(puzzle_data[1][i].first) << " " << static_cast<unsigned>(puzzle_data[2][i].first) << " | " << static_cast<unsigned>(puzzle_data[3][i].first) << " " << static_cast<unsigned>(puzzle_data[4][i].first) << " " << static_cast<unsigned>(puzzle_data[5][i].first) << " | " << static_cast<unsigned>(puzzle_data[6][i].first) << " " << static_cast<unsigned>(puzzle_data[7][i].first) << " " << static_cast<unsigned>(puzzle_data[8][i].first)<< " " << std::endl;
      if(i % 3 == 2 && i != 8) {
         os << "------+-------+-------" << std::endl;
      }
   }
   return os.str();
}

void sudoku::set_candidates()
{
   for(std::size_t i = 0; i < 9; i++) {
      for(std::size_t j = 0; j < 9; j++) {
         if(puzzle_data[i][j].first == 0) {
            sudoku_set row_set, column_set, block_set;
            row_set = get_row(i);
            column_set = get_column(j);
            value_t block_number = get_block_number(i, j);
            block_set = get_block(block_number);
            puzzle_data[i][j].second = all_candidates;
            puzzle_data[i][j].second.remove(row_set | column_set | block_set);
         }
      }
   }
   return;
}

void sudoku::solve_cell(uint_fast8_t row, uint_fast8_t column, uint_fast8_t value)
{
   puzzle_data[row][column].first = value;
   ++solved_cells;
   puzzle_data[row][column].second.clear();
   // remove candidate from the row and column
   for(std::size_t k = 0; k < 9; k++) {
      // row i
      puzzle_data[row][k].second.erase(value);
      // column j
      puzzle_data[k][column].second.erase(value);
   }
   // we need to find the top left of the block. 
   uint_fast8_t first_row = row - (row % 3);
   uint_fast8_t first_column = column - (column % 3);
   // remove the candidate from the block
   for(value_t k = first_row; k < first_row + 3; k++) {
      for(value_t l = first_column; l < first_column + 3; l++) {
         puzzle_data[k][l].second.erase(value);
      }
   }
   return;
}

// get all the saved values in the row
sudoku_set sudoku::get_row(uint_fast8_t r) const
{
   sudoku_set rv;
   for(std::size_t i = 0; i < 9; i++) {
      rv.insert(puzzle_data[r][i].first);
   }
   rv.erase(0);
   return rv;
}

// get all the saved values in the column
sudoku_set sudoku::get_column(uint_fast8_t c) const
{
   sudoku_set rv;
   for(std::size_t i = 0; i < 9; i++) {
      rv.insert(puzzle_data[i][c].first);
   }
   rv.erase(0);
   return rv;
}

sudoku_set sudoku::get_block(uint_fast8_t block) const
{
   sudoku_set rv;
   for(std::size_t i = 0; i < 9; i++) {
      rv.insert(cell<orientation::block>(block-1, i).first);
   }
   rv.erase(0);
   return rv;
}

sudoku::puzzle_input_data_t sudoku::get_puzzle() const
{
   puzzle_input_data_t p;

   for(std::size_t i = 0; i < 9; i++) {
      for(std::size_t j=0; j < 9; j++) {
         p[i][j] = puzzle_data[i][j].first;
      }
   }
   return p;
}

void sudoku::solve_single_candidates()
{
   while(true) {
      bool updated = false;
      for(std::size_t i = 0; i < 9; i++) {
         for(std::size_t j = 0; j < 9; j++) {
            if(puzzle_data[i][j].second.size() == 1) {
               solve_cell(i, j, *(puzzle_data[i][j].second.begin()));
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
   for(std::size_t i = 0; i < 9; i++) {
      for(std::size_t j = 0; j < 9; j++) {
         for(const auto& candidate : puzzle_data[i][j].second) {
            uint_fast8_t house_count = 0;
            // row i
            for(std::size_t k = 0; k < 9; k++) {
               if(puzzle_data[i][k].second.contains(candidate)) { house_count++; }
            }
            if(house_count == 1) { 
               solve_cell(i, j, candidate); 
               break; // next cell
            }
            house_count = 0;
            for(std::size_t k = 0; k < 9; k++) {
               if(puzzle_data[k][j].second.contains(candidate)) { house_count++; }
            }
            if(house_count == 1) {
               solve_cell(i, j, candidate); 
               break; // next cell
            }
            house_count = 0;
            value_t block_number = get_block_number(i, j);
            for(value_t k = 0; k < 9; k++) {
               // if(block_puzzle[block_number - 1][k]->second.contains(candidate)) {house_count++; }
               if(puzzle_data[orient_row<orientation::block>(block_number - 1, k)][orient_column<orientation::block>(block_number - 1, k)].second.contains(candidate)) { house_count++; }
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

void sudoku::find_hidden_pairs()
{
   find_hidden_pairs_impl<sudoku::orientation::row>();
   find_hidden_pairs_impl<sudoku::orientation::column>();
   find_hidden_pairs_impl<sudoku::orientation::block>();
   return;
}

void sudoku::reduce_naked_pairs()
{
   reduce_naked_pairs_impl<orientation::row>();
   reduce_naked_pairs_impl<orientation::column>();
   reduce_naked_pairs_impl<orientation::block>();
}

void sudoku::reduce_pointing_pairs()
{
   for(value_t block = 1; block < 10; block++) {
      reduce_pointing_pairs_impl<orientation::row>(block);
      reduce_pointing_pairs_impl<orientation::column>(block);
   }
   return;
}

void sudoku::reduce_box_line()
{
   reduce_box_line_impl<orientation::row>();
   reduce_box_line_impl<orientation::column>();
}

void sudoku::reduce_x_wing()
{
   reduce_x_wing_impl<orientation::row>();
   reduce_x_wing_impl<orientation::column>();
   return;
}

void sudoku::reduce_naked_triple()
{
   reduce_naked_triple_impl<orientation::row>();
   reduce_naked_triple_impl<orientation::column>();
   reduce_naked_triple_impl<orientation::block>();

   return;
}

void sudoku::find_hidden_triple()
{
   find_hidden_triple_impl<orientation::row>();
   find_hidden_triple_impl<orientation::column>();
   find_hidden_triple_impl<orientation::block>();
}

void sudoku::solve_puzzle()
{
   set_candidates();
   while(true) {
      puzzle_data_t current_puzzle_data = puzzle_data;
      solve_single_candidates();
      if(is_solved()) break;
      if(puzzle_data != current_puzzle_data) continue;
      solve_hidden_singles();
      if(is_solved()) break;
      if(puzzle_data != current_puzzle_data) continue;
      find_hidden_pairs();
      if(is_solved()) break;
      if(puzzle_data != current_puzzle_data) continue;
      reduce_naked_pairs();
      if(is_solved()) break;
      if(puzzle_data != current_puzzle_data) continue;
      reduce_pointing_pairs();
      if(is_solved()) break;
      if(puzzle_data != current_puzzle_data) continue;
      reduce_box_line();
      if(is_solved()) break;
      if(puzzle_data != current_puzzle_data) continue;
      reduce_x_wing();
      if(is_solved()) break;
      if(puzzle_data != current_puzzle_data) continue;
      reduce_naked_triple();
      if(is_solved()) break;
      if(puzzle_data != current_puzzle_data) continue;
      find_hidden_triple();
      if(puzzle_data == current_puzzle_data) break; // we didn't update the puzzle this iteration. 
   }
   return;
}

std::pair<sudoku::value_t, sudoku::value_t> sudoku::first_unsolved() const
{
   for(value_t i = 0; i < 9; i++) {
      for(value_t j = 0; j < 9; j++) {
         if(puzzle_data[i][j].first == 0) return {i, j};
      }
   }
   return {10, 10};
}

// Sometimes the simplest things are best. 
// This algorithm tries every number without respect to whether it's a valid
// candidate or not. This turns out to be faster than setting candidates 
// and only iterating over the set candidates. 

void sudoku::solve_backtrack()
{
   auto unsolved = first_unsolved();
   if(unsolved.first == 10 || unsolved.second == 10) return;
   for(value_t candidate_value = 1; candidate_value < 10; candidate_value++) {
      puzzle_data[unsolved.first][unsolved.second].first = candidate_value;
      ++solved_cells;
      if(is_valid()) solve_backtrack();
      if(is_solved() && is_valid()) return;
      --solved_cells;
   }
   puzzle_data[unsolved.first][unsolved.second].first = 0;
   return;
}

bool sudoku::is_solved() const
{
   if(solved_cells == 81) return true;
   return false;
}

bool sudoku::is_valid() const
{
   if(! are_houses_valid_impl<orientation::row>()) return false;
   if(! are_houses_valid_impl<orientation::column>()) return false;
   if(! are_houses_valid_impl<orientation::block>()) return false;
   return true;
}

void sudoku::print_candidate(uint_fast8_t row, uint_fast8_t column) const
{
 
   for(auto it = puzzle_data[row][column].second.cbegin(); it != puzzle_data[row][column].second.cend(); it++) {
      std::cout << static_cast<unsigned>(*it);
      if(std::next(it) != puzzle_data[row][column].second.cend()) {
         std::cout << ", ";
      }
   }
}

void sudoku::print_differences(const sudoku& other) const
{
   for(std::size_t i = 0; i < 9; i++) {
      for(std::size_t j = 0; j < 9; j++) {
         if(puzzle_data[i][j] != other.puzzle_data[i][j]) {
            std::cout << "puzzle[" << i << "][" << j << "] = {" << static_cast<unsigned>(puzzle_data[i][j].first) << ", " << puzzle_data[i][j].second.get_value() << " = {";
            for(auto it = puzzle_data[i][j].second.cbegin(); it != puzzle_data[i][j].second.cend(); it++) {
               std::cout << static_cast<unsigned>(*it); 
               if(std::next(it) != puzzle_data[i][j].second.cend()) {
                  std::cout << ", ";
               }
            }
            std::cout << "} }" << std::endl;
            std::cout << "other.puzzle[" << i << "][" << j << "] = {" << static_cast<unsigned>(other.puzzle_data[i][j].first) << ", " << other.puzzle_data[i][j].second.get_value() << " = " << ", {";
            for(auto it = other.puzzle_data[i][j].second.cbegin(); it != other.puzzle_data[i][j].second.cend(); it++) {
               std::cout << static_cast<unsigned>(*it); 
               if(std::next(it) != other.puzzle_data[i][j].second.cend()) {
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
   for(std::size_t i = 0; i < 9; i++) {
      for(std::size_t j = 0; j < 9; j++) {
         if(puzzle_data[i][j].second.size() > 0) {
            std::cout << "puzzle[" << i << "][" << j << "] = { " << static_cast<unsigned>(puzzle_data[i][j].first) << " }, {";
            print_candidate(i, j);
            std::cout << "} }" << std::endl; 
         }
      }
   }
}

void sudoku::print_puzzle_cpp(std::string var_name) const
{
   std::cout << "   sudoku::puzzle_input_data_t " << var_name << " {{" << std::endl;
   for(std::size_t i = 0; i < 9; i++) {
      std::cout << "      {";
      for(std::size_t j = 0; j < 9; j++) {
         std::cout << static_cast<unsigned>(puzzle_data[i][j].first);
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
   for(std::size_t i = 0; i < 9; i++) {
      for(std::size_t j = 0; j < 9; j++) {
         std::cout << static_cast<unsigned>(puzzle_data[i][j].first);
      }
      std::cout << std::endl;
   }
}

void sudoku::print_puzzle_candidates_cpp(std::string var_name) const 
{
   std::cout << "   sudoku::puzzle_data_t " << var_name << " {{ // puzzle" << std::endl;
   for(std::size_t i = 0; i < 9; i++) {
      std::cout << "      {{ // row " << i+1 << std::endl;;
      for(std::size_t j = 0; j < 9; j++) {
         std::cout << "         { " << static_cast<unsigned>(puzzle_data[i][j].first) << ", ";
         if(puzzle_data[i][j].second.size() > 0) {
            std::cout << "{{ ";
            for(auto it = puzzle_data[i][j].second.cbegin(); it != puzzle_data[i][j].second.cend(); it++) {
               std::cout << static_cast<unsigned>(*it);
               if(std::next(it) != puzzle_data[i][j].second.cend()) {
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

constexpr sudoku::value_t sudoku::get_block_number(value_t row, value_t column)
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

constexpr std::pair<sudoku::value_t, sudoku::value_t> sudoku::get_block_start(value_t block)
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
      default:
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
