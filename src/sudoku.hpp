#pragma once 

#include <array>
#include <cstdint>
#include <iostream>
#include <set>
#include <string>
#include <utility>

class sudoku 
{
public:
   using value_t = uint_fast8_t;
   using puzzle_candidate_t = std::set<uint_fast8_t>;
   using puzzle_entry_t = std::pair<uint_fast8_t, puzzle_candidate_t>;
   using puzzle_row_t = std::array<puzzle_entry_t, 9>;
   using puzzle_data_t = std::array<puzzle_row_t, 9>;
   using puzzle_input_data_t = std::array<std::array<int_fast8_t, 9>, 9>;

   static const puzzle_candidate_t default_candidates;
   static const puzzle_candidate_t all_candidates;
   static const puzzle_entry_t empty_entry;
   static const puzzle_row_t empty_row;
   static const puzzle_data_t empty_puzzle;


   sudoku() = default;
   sudoku(const puzzle_input_data_t& p);
   sudoku(const puzzle_data_t& p) : puzzle(p) {}
   ~sudoku() = default;
   sudoku(const sudoku& other) = default;
   sudoku(sudoku&& other) = default;
   sudoku& operator=(const sudoku& other) = default;
   sudoku& operator=(sudoku&& other) = default; 

   bool is_equal(const sudoku& other) const;
   void print() const;
   std::string to_string() const;
   // set_candidates sets the candidates by removing anything seen in the block, row or column. 
   void set_candidates();
   void solve_cell(uint_fast8_t row, uint_fast8_t column, uint_fast8_t value); // this solves the cell with the value and removes the value from the candidate list for the houses 
   void solve_single_candidates(); // this solves where there's only a single candidate in a cell
   void solve_hidden_singles(); // this solves where there's only one cell in a house for a candidate 
   void find_hidden_pairs(); // this finds a hidden pair and removes candidates from those cells
   void reduce_naked_pairs(); // this finds naked pairs and removes candidates from the rest of the house
   void solve_puzzle();

   bool is_solved();
   puzzle_input_data_t get_puzzle() const;

   // utilities 
   void print_candidate(uint_fast8_t row, uint_fast8_t column) const;
   void print_differences(const sudoku& other) const;
   void print_blanks() const;
   void print_puzzle_cpp() const;
   void print_puzzle_raw() const; 

private:

   std::set<uint_fast8_t> get_row(uint_fast8_t r);
   std::set<uint_fast8_t> get_column(uint_fast8_t c);
   std::set<uint_fast8_t> get_block(uint_fast8_t b);

   puzzle_data_t puzzle{ empty_puzzle };

friend std::ostream& operator<<(std::ostream& os, const sudoku& s);

};

bool operator==(const sudoku& lhs, const sudoku& rhs);
std::ostream& operator<<(std::ostream& os, const sudoku& s);

