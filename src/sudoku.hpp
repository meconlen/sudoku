#pragma once 

#include <array>
#include <cstdint>
#include <iostream>
#include <set>
#include <string>
#include <utility>

#include "sudoku_set.hpp"

class sudoku 
{
   enum class orientation { row, column, block };
public:
   using value_t = uint_fast8_t;
   using puzzle_candidate_t = sudoku_set;
   using puzzle_entry_t = std::pair<uint_fast8_t, puzzle_candidate_t>;
   using puzzle_row_t = std::array<puzzle_entry_t, 9>;
   using puzzle_data_t = std::array<puzzle_row_t, 9>;
   using puzzle_input_data_t = std::array<std::array<value_t, 9>, 9>;

   static const puzzle_candidate_t default_candidates;
   static const puzzle_candidate_t all_candidates;
   static const puzzle_entry_t empty_entry;
   static const puzzle_row_t empty_row;
   static const puzzle_data_t empty_puzzle;


   sudoku() = default;
   sudoku(const puzzle_input_data_t& p);
   sudoku(const puzzle_data_t& p) : puzzle_data(p) {}
   sudoku(const std::string& p);
   ~sudoku() = default;
   sudoku(const sudoku& other) = default;
   sudoku(sudoku&& other) = default;
   sudoku& operator=(const sudoku& other) = default;
   sudoku& operator=(sudoku&& other) = default; 

   bool is_equal(const sudoku& other) const;
   void print() const;
   void print_transposed() const;
   std::string to_string() const;
   std::string to_string_transposed() const;
   // set_candidates sets the candidates by removing anything seen in the block, row or column. 
   void set_candidates();
   void solve_cell(uint_fast8_t row, uint_fast8_t column, uint_fast8_t value); // this solves the cell with the value and removes the value from the candidate list for the houses 
   void solve_single_candidates(); // this solves where there's only a single candidate in a cell
   void solve_hidden_singles(); // this solves where there's only one cell in a house for a candidate 
   void find_hidden_pairs(); // this finds a hidden pair and removes candidates from those cells
   void reduce_naked_pairs(); // this finds naked pairs and removes candidates from the rest of the house
   void reduce_pointing_pairs(); // this finds a pair (or triple) that is only in one row or column in a box. If so remove it from the row/column outside the box
   void reduce_box_line(); // if there is a box with a candidate in a row/column and that is the only
                           // box with that candidate in the row/column then we remove the candidate
                           // from the rest of the box
   void reduce_x_wing();
   void reduce_naked_triple();
   void find_hidden_triple();
   void solve_puzzle();

   bool is_solved() const;
   bool is_valid() const; // this will determine if a partially filled out puzzle contains any obvious
                     // contradictions in a row, column or box

   puzzle_input_data_t get_puzzle() const;

   // DFS 
   void solve_backtrack();

   // utilities 
   void print_candidate(uint_fast8_t row, uint_fast8_t column) const;
   void print_differences(const sudoku& other) const;
   void print_blanks() const;
   void print_puzzle_cpp(std::string var_name = "p00") const;
   void print_puzzle_raw() const; 
   void print_puzzle_candidates_cpp(std::string var_name = "p00") const;

private:

   // actual implementation of the algorithms 

   template<orientation O>
   bool are_houses_valid_impl() const;

   template<orientation O>
   void find_hidden_pairs_impl();

   template<orientation O>
   void reduce_naked_pairs_impl();

   template<orientation O>
   void reduce_pointing_pairs_impl(value_t block);

   template<orientation O>
   void reduce_box_line_impl();

   template<orientation O>
   void reduce_x_wing_impl();

   template<orientation O>
   void find_hidden_triple_impl();

   template<orientation O>
   void reduce_naked_triple_impl();


   // utilities 

   static constexpr value_t get_block_number(value_t row, value_t column); 
   static constexpr std::pair<value_t, value_t> get_block_start(value_t block);

   sudoku_set get_row(uint_fast8_t r) const;
   sudoku_set get_column(uint_fast8_t c) const;
   sudoku_set get_block(uint_fast8_t block) const;

   std::pair<value_t, value_t> first_unsolved() const;

   template<orientation O>
   constexpr const puzzle_entry_t& cell(const value_t& i, const value_t& j) const;

   template<orientation O>
   constexpr puzzle_entry_t& cell(const value_t& i, const value_t& j);

   template<orientation O>
   std::array<sudoku_set, 9> get_candidate_columns_o(value_t row);

   // this converts (i, j) from a particular orientation (row, column (transposed) or block orientation) into standard (row) orientation. 

   template<orientation O>
   constexpr value_t orient_row(value_t i, value_t j) const;

   template<orientation O>
   constexpr value_t orient_column(value_t i, value_t j) const;


   puzzle_data_t puzzle_data{ empty_puzzle };
   value_t solved_cells{0};

   friend std::ostream& operator<<(std::ostream& os, const sudoku& s);
};

template<>
inline constexpr sudoku::value_t sudoku::orient_row<sudoku::orientation::row>(value_t i, value_t j) const
{
   return i;
}

template<>
inline constexpr sudoku::value_t sudoku::orient_row<sudoku::orientation::column>(value_t i, value_t j) const
{
   return j;
}

template<>
inline constexpr sudoku::value_t sudoku::orient_row<sudoku::orientation::block>(value_t i, value_t j) const
{
   return (i / 3) * 3 + (j / 3);
}

template<>
inline constexpr sudoku::value_t sudoku::orient_column<sudoku::orientation::row>(value_t i, value_t j) const
{
   return j;
}

template<>
inline constexpr sudoku::value_t sudoku::orient_column<sudoku::orientation::column>(value_t i, value_t j) const
{
   return i;
}

template<>
inline constexpr sudoku::value_t sudoku::orient_column<sudoku::orientation::block>(value_t i, value_t j) const
{
   return (i % 3) * 3 + (j % 3);
}

template<sudoku::orientation O>
inline constexpr const sudoku::puzzle_entry_t& sudoku::cell(const sudoku::value_t& i, const sudoku::value_t& j) const
{
   return puzzle_data[orient_row<O>(i, j)][orient_column<O>(i, j)];
}

template<sudoku::orientation O>
inline constexpr sudoku::puzzle_entry_t& sudoku::cell(const sudoku::value_t& i, const sudoku::value_t& j)
{
   return puzzle_data[orient_row<O>(i, j)][orient_column<O>(i, j)];
}

template<sudoku::orientation O>
std::array<sudoku_set, 9> sudoku::get_candidate_columns_o(value_t row)
{
   std::array<sudoku_set, 9> candidate_columns;
   for(value_t j = 0; j < 9; j++) {
      for(auto candidate : cell<O>(row, j).second) {
         candidate_columns[candidate-1].insert(j);
      }      
   }
   return candidate_columns;
}


template<sudoku::orientation O>
inline void sudoku::find_hidden_pairs_impl()
{
   for(value_t i = 0; i < 9; i++) {
      std::array<sudoku_set, 9> candidate_cells;
      for(value_t j = 0; j < 9; j++) {
         for(const auto& candidate : cell<O>(i, j).second) {
            candidate_cells[candidate-1].insert(j);
         }
      }
      for(value_t candidate = 1; candidate < 10; candidate++) {
         if(candidate_cells[candidate-1].size() == 2) {
            for(value_t second_candidate = candidate+1; second_candidate < 10; second_candidate++) {
               if(candidate_cells[candidate-1] == candidate_cells[second_candidate-1]) {
                  for(const auto& j : candidate_cells[candidate-1]) {
                     cell<O>(i, j).second = {candidate, second_candidate};
                  }
               }
            }
         }
      }
   }   
}

template<sudoku::orientation O>
inline void sudoku::reduce_naked_pairs_impl()
{
   for(value_t i = 0; i < 9; i++) {
      for(value_t j = 0; j < 9; j++) {
         if(cell<O>(i, j).second.size() == 2) {
            // we have a pair
            // find the same pair after the current candidate 
            for(value_t k = j+1; k < 9; k++) {
               if(cell<O>(i, j).second == cell<O>(i, k).second) {
                  // we have the pair and that pair should only be candidates in [i][j] and [i][k]
                  for(value_t m = 0; m < 9; m++) {
                     // we skip the cells with the naked pair
                     if(m == j || m == k) continue;
                     cell<O>(i, m).second.remove(cell<O>(i, j).second);
                  }
               }
            }
         }
      }
   }
}

// this finds a pair (or triple) that is only in one row or column in a box. If so remove it from the row/column outside the box
// for each block
// look at each row(column)
// if there is a candidate which is only in a single row(column)
//    remove the candidate from the rest of the row 

template<sudoku::orientation O>
inline void sudoku::reduce_pointing_pairs_impl(sudoku::value_t block)
{
   auto start = get_block_start(block);
   std::array<sudoku_set, 9> candidate_rows;
   for(value_t i = start.first; i < start.first + 3; i++) {
      for(value_t j = start.second; j < start.second + 3; j++) {
         // for this cell for each candidate add i to the list
         for(const auto& candidate : cell<O>(i, j).second) {
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
               cell<O>(i, j).second.erase(candidate);
            }
         }
      }
   }
   return;
}

template<sudoku::orientation O>
inline void sudoku::reduce_box_line_impl()
{
   // for each row/column
   // record which block a candidate is in 
   // if the candidate is only in one box for that row/column
   // remove the candidate from other rows/columns in that box
   for(value_t i = 0; i < 9; i++) {
      std::array<sudoku_set, 9> candidate_block;
      for(value_t j = 0; j < 9; j++) {
         value_t block = get_block_number(i, j);
         for(const auto& candidate : cell<O>(i, j).second) {
            candidate_block[candidate-1].insert(block);
         }
      }
      for(value_t candidate = 1; candidate < 10; candidate++) {
         if(candidate_block[candidate-1].size() == 1) {
            auto start = get_block_start(*(candidate_block[candidate-1].begin()));
            for(value_t m = start.first; m < start.first + 3; m++) {
               for(value_t n = start.second; n < start.second + 3; n++) {
                  if(m == i) continue;
                  cell<O>(m, n).second.erase(candidate);
               }
            }
         }
      }
   }
}

// for each row 
// collect the columns for each candidate
// if there is a candidate in two columns 
// find another row with that candidate in the same columns 
// if we find a match remove the candidate from those columns in other rows


template<sudoku::orientation O>
inline void sudoku::reduce_x_wing_impl()
{
   for(value_t i = 0; i < 9; i++) {
      std::array<sudoku_set, 9> candidate_columns;
      for(value_t j = 0; j < 9; j++) {
         for(const auto& candidate : cell<O>(i, j).second) {
            candidate_columns[candidate-1].insert(j);
         }
      }
      for(value_t candidate = 1; candidate < 10; candidate++) {
         if(candidate_columns[candidate-1].size() == 2) {
            for(value_t k = i+1; k < 9; k++) {
               std::array<sudoku_set, 9> k_candidate_columns;
               for(value_t l = 0; l < 9; l++) {
                  for(const auto& k_candidate : cell<O>(k, l).second) {
                     k_candidate_columns[k_candidate-1].insert(l);
                  }
               }
               if(candidate_columns[candidate-1] == k_candidate_columns[candidate-1]) {
                  for(value_t m = 0; m < 9; m++) {
                     if(m == i || m == k) continue;
                     for(const auto& column : candidate_columns[candidate-1]) {
                        cell<O>(m, column).second.erase(candidate);
                     }
                  }   
               }
            }
         }
      }
   }   
}

template<sudoku::orientation O>
inline void sudoku::reduce_naked_triple_impl()
{
   for(value_t i = 0; i < 9; i++) { // for each row
      // get the columns each candidate appears in for the current row
      // std::array<sudoku_set, 9> candidate_columns = get_candidate_columns_o<O>(i);
      for(value_t c1 = 1; c1 < 10; c1++) {
         for(value_t c2 = c1 + 1; c2 < 10; c2++) {
            for(value_t c3 = c2 + 1; c3 < 10; c3++) {
               // we want three cells where these are the only candidates 
               // so we need to know if the cell candidates is a subset 
               // of {c1, c2, c3}
               sudoku_set candidate_set { c1, c2, c3 };
               sudoku_set candidate_set_columns; // which unsolved columns in the row are a subset of the candidate_set
               for(value_t column = 0; column < 9; column++) {
                  if(cell<O>(i, column).first == 0 && candidate_set.includes(cell<O>(i, column).second)) {
                           candidate_set_columns.insert(column);
                  }
               }
               // if we have three columns which are a subset of {c1, c2, c3}
               if(candidate_set_columns.size() == 3) {
                  for(value_t column = 0; column < 9; column++) {
                     // skip c1, c2, c3
                     if(candidate_set_columns.contains(column)) continue;

                     // for(const auto& candidate : candidate_set) {
                     //    puzzle[i][column]->second.erase(candidate);
                     // }
                     cell<O>(i, column).second.remove(candidate_set);
                  }
               }
            }
         }
      }
   }   
}



template<sudoku::orientation O>
inline void sudoku::find_hidden_triple_impl()
{
   for(value_t i = 0; i < 9; i++) {
      // we need a oriented version of get_candidate_columns
      // std::array<sudoku_set, 9> candidate_columns = get_candidate_columns_o<O>(i); 
      for(value_t c1 = 1; c1 < 10; c1++) {
         for(value_t c2 = c1 + 1; c2 < 10; c2++) {
            for(value_t c3 = c2 + 1; c3 < 10; c3++) {
               // we want three cells where these are the only cells for the three candidates 
               sudoku_set candidate_set { c1, c2, c3 };
               sudoku_set candidates_found, candidate_set_columns;
               for(value_t column = 0; column < 9; column++) {
                  // we want to know if any element of candidate_set is in the cell 
                  // and all elements of the candidate_set must be found 
                  if(cell<O>(i, column).first == 0) {
                     sudoku_set intersection = candidate_set & cell<O>(i, column).second;
                     // if the intersection is non-null then we add the column to the 
                     // candidate_set_colums and mark which candidates we have found
                     if(intersection.size() > 0) {
                        // for(const auto& c : intersection) {
                        //    candidates_found.insert(c);
                        // }
                        candidates_found = candidates_found | intersection;
                        candidate_set_columns.insert(column);
                     }
                  }
               }
               // we have three cells of which {c1, c2, c3} is a subset
               // and we have identified that all three candidates were found
               if(candidate_set_columns.size() == 3 && candidates_found.size() == 3) {
                  // for each of the three columns in the candidate_set_columns
                  // we want to remove every candidate that isn't in the candidate_set
                  for(const auto& column : candidate_set_columns) {
                     cell<O>(i, column).second = cell<O>(i, column).second & candidate_set;
                  }
               }
            }
         }
      }
   }
   return;
}

template<sudoku::orientation O>
inline bool sudoku::are_houses_valid_impl() const 
{
   for(value_t i = 0; i < 9; i++) {
      std::array<bool, 9> values {{false, false, false, false, false, false, false, false, false}};
      for(value_t j = 0; j < 9; j++) {
         if(cell<O>(i, j).first != 0) {
            if(values[cell<O>(i, j).first - 1]) {
               return false;
            } else {
               values[cell<O>(i, j).first -1] = true;
            }
         }
      }
   }
   return true;
}

bool operator==(const sudoku& lhs, const sudoku& rhs);
std::ostream& operator<<(std::ostream& os, const sudoku& s);


