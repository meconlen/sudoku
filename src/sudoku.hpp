#pragma once 

#include <array>
#include <cstdint>
#include <iostream>
#include <set>
#include <string>
#include <utility>

// open issues
// find_hidden_pairs for row and column. Currently only does this for a block (careful here, the example is actually a row, we need a test case for a block)
// reduce_naked_pairs for a column and block
// reduce_pointing_pairs for a column

class sudoku 
{
public:
   using value_t = uint_fast8_t;
   using puzzle_candidate_t = std::set<uint_fast8_t>;
   using puzzle_entry_t = std::pair<uint_fast8_t, puzzle_candidate_t>;
   using puzzle_row_t = std::array<puzzle_entry_t, 9>;
   using puzzle_data_t = std::array<puzzle_row_t, 9>;
   using puzzle_input_data_t = std::array<std::array<int_fast8_t, 9>, 9>;

   using puzzle_entry_p = puzzle_entry_t*;
   using puzzle_row_p = std::array<puzzle_entry_p, 9>;
   using puzzle_data_p = std::array<puzzle_row_p, 9>;


   static const puzzle_candidate_t default_candidates;
   static const puzzle_candidate_t all_candidates;
   static const puzzle_entry_t empty_entry;
   static const puzzle_row_t empty_row;
   static const puzzle_data_t empty_puzzle;


   sudoku() = default;
   sudoku(const puzzle_input_data_t& p);
   sudoku(const puzzle_data_t& p) : puzzle_data(p) {}
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
   void solve_puzzle();

   bool is_solved();
   puzzle_input_data_t get_puzzle() const;

   // utilities 
   void print_candidate(uint_fast8_t row, uint_fast8_t column) const;
   void print_differences(const sudoku& other) const;
   void print_blanks() const;
   void print_puzzle_cpp(std::string var_name = "p00") const;
   void print_puzzle_raw() const; 
   void print_puzzle_candidates_cpp(std::string var_name = "p00") const;

private:

   // private versions of algorithms 

   inline void find_hidden_pairs(puzzle_data_p puzzle);
   inline void reduce_naked_pairs(puzzle_data_p puzzle);
   inline void reduce_pointing_pairs(puzzle_data_p puzzle, value_t block);
   inline void reduce_box_line(puzzle_data_p puzzle);
   inline void reduce_x_wing(puzzle_data_p puzzle);

   // utilities 

   static value_t get_block_number(value_t row, value_t column); 
   static std::pair<value_t, value_t> get_block_start(value_t block);

   std::set<uint_fast8_t> get_row(uint_fast8_t r);
   std::set<uint_fast8_t> get_column(uint_fast8_t c);
   std::set<uint_fast8_t> get_block(uint_fast8_t block);
 

   puzzle_data_t puzzle_data{ empty_puzzle };

   puzzle_data_p puzzle {{
      {{ &puzzle_data[0][0], &puzzle_data[0][1], &puzzle_data[0][2], &puzzle_data[0][3], &puzzle_data[0][4], &puzzle_data[0][5], &puzzle_data[0][6], &puzzle_data[0][7], &puzzle_data[0][8] }},
      {{ &puzzle_data[1][0], &puzzle_data[1][1], &puzzle_data[1][2], &puzzle_data[1][3], &puzzle_data[1][4], &puzzle_data[1][5], &puzzle_data[1][6], &puzzle_data[1][7], &puzzle_data[1][8] }},
      {{ &puzzle_data[2][0], &puzzle_data[2][1], &puzzle_data[2][2], &puzzle_data[2][3], &puzzle_data[2][4], &puzzle_data[2][5], &puzzle_data[2][6], &puzzle_data[2][7], &puzzle_data[2][8] }},
      {{ &puzzle_data[3][0], &puzzle_data[3][1], &puzzle_data[3][2], &puzzle_data[3][3], &puzzle_data[3][4], &puzzle_data[3][5], &puzzle_data[3][6], &puzzle_data[3][7], &puzzle_data[3][8] }},
      {{ &puzzle_data[4][0], &puzzle_data[4][1], &puzzle_data[4][2], &puzzle_data[4][3], &puzzle_data[4][4], &puzzle_data[4][5], &puzzle_data[4][6], &puzzle_data[4][7], &puzzle_data[4][8] }},
      {{ &puzzle_data[5][0], &puzzle_data[5][1], &puzzle_data[5][2], &puzzle_data[5][3], &puzzle_data[5][4], &puzzle_data[5][5], &puzzle_data[5][6], &puzzle_data[5][7], &puzzle_data[5][8] }},
      {{ &puzzle_data[6][0], &puzzle_data[6][1], &puzzle_data[6][2], &puzzle_data[6][3], &puzzle_data[6][4], &puzzle_data[6][5], &puzzle_data[6][6], &puzzle_data[6][7], &puzzle_data[6][8] }},
      {{ &puzzle_data[7][0], &puzzle_data[7][1], &puzzle_data[7][2], &puzzle_data[7][3], &puzzle_data[7][4], &puzzle_data[7][5], &puzzle_data[7][6], &puzzle_data[7][7], &puzzle_data[7][8] }},
      {{ &puzzle_data[8][0], &puzzle_data[8][1], &puzzle_data[8][2], &puzzle_data[8][3], &puzzle_data[8][4], &puzzle_data[8][5], &puzzle_data[8][6], &puzzle_data[8][7], &puzzle_data[8][8] }},
   }};

   puzzle_data_p transposed_puzzle {{
      {{ &puzzle_data[0][0], &puzzle_data[1][0], &puzzle_data[2][0], &puzzle_data[3][0], &puzzle_data[4][0], &puzzle_data[5][0], &puzzle_data[6][0], &puzzle_data[7][0], &puzzle_data[8][0] }},
      {{ &puzzle_data[0][1], &puzzle_data[1][1], &puzzle_data[2][1], &puzzle_data[3][1], &puzzle_data[4][1], &puzzle_data[5][1], &puzzle_data[6][1], &puzzle_data[7][1], &puzzle_data[8][1] }},
      {{ &puzzle_data[0][2], &puzzle_data[1][2], &puzzle_data[2][2], &puzzle_data[3][2], &puzzle_data[4][2], &puzzle_data[5][2], &puzzle_data[6][2], &puzzle_data[7][2], &puzzle_data[8][2] }},
      {{ &puzzle_data[0][3], &puzzle_data[1][3], &puzzle_data[2][3], &puzzle_data[3][3], &puzzle_data[4][3], &puzzle_data[5][3], &puzzle_data[6][3], &puzzle_data[7][3], &puzzle_data[8][3] }},
      {{ &puzzle_data[0][4], &puzzle_data[1][4], &puzzle_data[2][4], &puzzle_data[3][4], &puzzle_data[4][4], &puzzle_data[5][4], &puzzle_data[6][4], &puzzle_data[7][4], &puzzle_data[8][4] }},
      {{ &puzzle_data[0][5], &puzzle_data[1][5], &puzzle_data[2][5], &puzzle_data[3][5], &puzzle_data[4][5], &puzzle_data[5][5], &puzzle_data[6][5], &puzzle_data[7][5], &puzzle_data[8][5] }},
      {{ &puzzle_data[0][6], &puzzle_data[1][6], &puzzle_data[2][6], &puzzle_data[3][6], &puzzle_data[4][6], &puzzle_data[5][6], &puzzle_data[6][6], &puzzle_data[7][6], &puzzle_data[8][6] }},
      {{ &puzzle_data[0][7], &puzzle_data[1][7], &puzzle_data[2][7], &puzzle_data[3][7], &puzzle_data[4][7], &puzzle_data[5][7], &puzzle_data[6][7], &puzzle_data[7][7], &puzzle_data[8][7] }},
      {{ &puzzle_data[0][8], &puzzle_data[1][8], &puzzle_data[2][8], &puzzle_data[3][8], &puzzle_data[4][8], &puzzle_data[5][8], &puzzle_data[6][8], &puzzle_data[7][8], &puzzle_data[8][8] }},
   }};

   puzzle_data_p block_puzzle {{
      {{ &puzzle_data[0][0], &puzzle_data[0][1], &puzzle_data[0][2], &puzzle_data[1][0], &puzzle_data[1][1], &puzzle_data[1][2], &puzzle_data[2][0], &puzzle_data[2][1], &puzzle_data[2][2] }},
      {{ &puzzle_data[0][3], &puzzle_data[0][4], &puzzle_data[0][5], &puzzle_data[1][3], &puzzle_data[1][4], &puzzle_data[1][5], &puzzle_data[2][3], &puzzle_data[2][4], &puzzle_data[2][5] }},
      {{ &puzzle_data[0][6], &puzzle_data[0][7], &puzzle_data[0][8], &puzzle_data[1][6], &puzzle_data[1][7], &puzzle_data[1][8], &puzzle_data[2][6], &puzzle_data[2][7], &puzzle_data[2][8] }},
      {{ &puzzle_data[3][0], &puzzle_data[3][1], &puzzle_data[3][2], &puzzle_data[4][0], &puzzle_data[4][1], &puzzle_data[4][2], &puzzle_data[5][0], &puzzle_data[5][1], &puzzle_data[5][2] }},
      {{ &puzzle_data[3][3], &puzzle_data[3][4], &puzzle_data[3][5], &puzzle_data[4][3], &puzzle_data[4][4], &puzzle_data[4][5], &puzzle_data[5][3], &puzzle_data[5][4], &puzzle_data[5][5] }},
      {{ &puzzle_data[3][6], &puzzle_data[3][7], &puzzle_data[3][8], &puzzle_data[4][6], &puzzle_data[4][7], &puzzle_data[4][8], &puzzle_data[5][6], &puzzle_data[5][7], &puzzle_data[5][8] }},
      {{ &puzzle_data[6][0], &puzzle_data[6][1], &puzzle_data[6][2], &puzzle_data[7][0], &puzzle_data[7][1], &puzzle_data[7][2], &puzzle_data[8][0], &puzzle_data[8][1], &puzzle_data[8][2] }},
      {{ &puzzle_data[6][3], &puzzle_data[6][4], &puzzle_data[6][5], &puzzle_data[7][3], &puzzle_data[7][4], &puzzle_data[7][5], &puzzle_data[8][3], &puzzle_data[8][4], &puzzle_data[8][5] }},
      {{ &puzzle_data[6][6], &puzzle_data[6][7], &puzzle_data[6][8], &puzzle_data[7][6], &puzzle_data[7][7], &puzzle_data[7][8], &puzzle_data[8][6], &puzzle_data[8][7], &puzzle_data[8][8] }}
   }};

   friend std::ostream& operator<<(std::ostream& os, const sudoku& s);

};

bool operator==(const sudoku& lhs, const sudoku& rhs);
std::ostream& operator<<(std::ostream& os, const sudoku& s);

