#include <iostream>
#include <gtest/gtest.h>
#include "sudoku.hpp"
#include "sudoku_puzzles.hpp"
#include "puzzles.hpp"

using namespace sudoku_puzzles;

TEST(sudoku_set, brace_initializer) {
   sudoku_set s0 {};
   EXPECT_EQ(s0.get_value(), 0);
   sudoku_set s1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
   EXPECT_EQ(s1.get_value(), 0b01111111110);
}

TEST(sudoku, string_constructor) {
   using namespace sudoku_puzzles::string_constructor;
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

TEST(sudoku, operator_equal_equal)
{
   using namespace sudoku_puzzles::euler;
   sudoku s1(p01);
   sudoku s2(p01);
   EXPECT_EQ(s1, s2);
}

TEST(sudoku, operator_not_equal)
{
   using namespace sudoku_puzzles::euler;
   sudoku s1(p01);
   sudoku s2(p02);
   EXPECT_NE(s1, s2);

}

TEST(sudoku, update_candidates)
{
   using namespace update_candidates;

   sudoku s1(p1);
   sudoku s2(p2);
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

TEST(sudoku, set_candidates) 
{
   using namespace set_candidates;
   s1.set_candidates();

   EXPECT_EQ(s1, s2);
   if(! (s1 == s2) ) {
      s1.print_differences(s2);
   }
}

// test using this example to find hidden singles 

TEST(sudoku, hidden_singles)
{
   using namespace hidden_singles;
   s1.solve_hidden_singles();\
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_differences(s2);
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp();
   }   
}

TEST(sudoku, naked_pairs)
{
   using namespace naked_pairs;
   s1.reduce_naked_pairs();
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_puzzle_candidates_cpp();
      s2.print_puzzle_candidates_cpp();
   }
}


TEST(sudoku, find_hidden_pairs_column)
{
   using namespace hidden_pairs_column;

   s1.find_hidden_pairs();
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_differences(s2);
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp();
   }

}


TEST(sudoku, find_hidden_pairs_row)
{
   using namespace hidden_pairs_column;
   s1.find_hidden_pairs();
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp();
   }

}

// example from https://www.sudokuwiki.org/Intersection_Removal#IR
// NB: The 4 in row 8, columns 2, 3 become a pointing pair only after the 4 
//    in row 7 columns 2, 3 become eliminated; so we call the function twice

TEST(sudoku, pointing_pair) 
{
   using namespace pointing_pair;
   s1.reduce_pointing_pairs();
   s1.reduce_pointing_pairs();

   EXPECT_EQ(s1, s2);

   if(!(s1 == s2)) {
      s1.print_differences(s2);
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp();
   }
}

// example from: https://www.sudokuwiki.org/Intersection_Removal#LBR

TEST(sudoku, reduce_box_line_row)
{
   using namespace reduce_box_line_row;

   s1.reduce_box_line();


   EXPECT_EQ(s1, s2);

   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp();
   }
}

// example from https://www.sudokuwiki.org/X_Wing_Strategy

TEST(sudoku, x_wing_column)
{
      
   using namespace reduce_x_wing_column;

   s1.reduce_x_wing();
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

TEST(sudoku, reduce_x_wing_row)
{
   using namespace reduce_x_wing_row;
   s1.reduce_x_wing();

   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   }   
}

TEST(sudoku, is_valid_true)
{
   sudoku s1("351286497492157638786934512275469183938521764614873259829645371163792845547318926");
   EXPECT_EQ(s1.is_valid(), true);
   if(!(s1.is_valid())) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
   sudoku s2("300200000000107000706030500070009080900020004010800050009040301000702000000008006");
   EXPECT_EQ(s2.is_valid(), true);
   if(!(s2.is_valid())) {
      s2.print_puzzle_cpp("p1");
      s2.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(sudoku, is_valid_false)
{
   sudoku s1("353286497492157638786934512275469183938521764614873259829645371163792845547318926");
   EXPECT_EQ(s1.is_valid(), false);
   if((s1.is_valid())) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
   sudoku s2("303200000000107000706030500070009080900020004010800050009040301000702000000008006");
   EXPECT_EQ(s2.is_valid(), false);
   if((s2.is_valid())) {
      s2.print_puzzle_cpp("p1");
      s2.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(sudoku, solve_backtrack)
{
   sudoku s1("300200000000107000706030500070009080900020004010800050009040301000702000000008006");
   sudoku s2("351286497492157638786934512275469183938521764614873259829645371163792845547318926");
   s1.solve_backtrack();
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   }   
}

// example from https://www.sudokuwiki.org/Naked_Candidates#NP
// the first puzzle ({5, 8, 9} in row 5) actually
// contains a column and block naked triple after the first 
// triple is removed. s2 is the final result. 


TEST(sudoku, naked_triple)
{
   sudoku::puzzle_data_t p1 {{ // puzzle
      {{ // row 1
         { 0, {{ 3, 6 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 6 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 3, 5 }} },
         { 8,  sudoku::default_candidates },
         { 0, {{ 1, 3, 5 }} },
         { 2,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates }
      }},
      {{ // row 2
         { 0, {{ 3, 6, 9 }} },
         { 0, {{ 1, 6, 9 }} },
         { 2,  sudoku::default_candidates },
         { 0, {{ 1, 5, 7, 9 }} },
         { 0, {{ 1, 3, 5 }} },
         { 0, {{ 5, 6, 7, 9 }} },
         { 0, {{ 1, 3, 5, 8 }} },
         { 0, {{ 3, 5, 6, 8 }} },
         { 4,  sudoku::default_candidates }
      }},
      {{ // row 3
         { 8,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 9 }} },
         { 2,  sudoku::default_candidates },
         { 0, {{ 6, 9 }} },
         { 0, {{ 1, 3 }} },
         { 0, {{ 3, 6 }} },
         { 7,  sudoku::default_candidates }
      }},
      {{ // row 4
         { 0, {{ 5, 6, 9 }} },
         { 0, {{ 1, 6, 9 }} },
         { 8,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 0, {{ 5, 9 }} },
         { 0, {{ 1, 6 }} }
      }},
      {{ // row 5
         { 0, {{ 4, 5, 6, 7, 9 }} },
         { 2,  sudoku::default_candidates },
         { 0, {{ 1, 5, 6, 7, 9 }} },
         { 0, {{ 5, 8, 9 }} },
         { 0, {{ 5, 8 }} },
         { 0, {{ 5, 9 }} },
         { 0, {{ 3, 5, 8, 9 }} },
         { 0, {{ 3, 4, 5, 8, 9 }} },
         { 0, {{ 1, 6 }} }
      }},
      {{ // row 6
         { 0, {{ 4, 5, 9 }} },
         { 0, {{ 4, 9 }} },
         { 3,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 4, 5, 8, 9 }} },
         { 0, {{ 5, 8 }} }
      }},
      {{ // row 7
         { 0, {{ 4, 5, 7 }} },
         { 0, {{ 4, 8 }} },
         { 0, {{ 5, 7 }} },
         { 0, {{ 5, 7, 8 }} },
         { 9,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates }
      }},
      {{ // row 8
         { 2,  sudoku::default_candidates },
         { 0, {{ 6, 8, 9 }} },
         { 0, {{ 5, 6, 7, 9 }} },
         { 0, {{ 1, 5, 7, 8 }} },
         { 0, {{ 1, 5, 8 }} },
         { 0, {{ 5, 7 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 5, 8, 9 }} },
         { 3,  sudoku::default_candidates }
      }},
      {{ // row 9
         { 1,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 0, {{ 5, 9 }} },
         { 6,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 0, {{ 5, 8, 9 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 5, 8 }} }
      }}
   }};
   sudoku s1(p1);
   sudoku::puzzle_data_t p2 {{ // puzzle
      {{ // row 1
         { 0, {{ 3, 6 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 6 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 3, 5 }} },
         { 8,  sudoku::default_candidates },
         { 0, {{ 5 }} },
         { 2,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates }
      }},
      {{ // row 2
         { 0, {{ 3, 6, 9 }} },
         { 0, {{ 1, 6, 9 }} },
         { 2,  sudoku::default_candidates },
         { 0, {{ 1, 5, 7, 9 }} },
         { 0, {{ 1, 3, 5 }} },
         { 0, {{ 5, 6, 7, 9 }} },
         { 0, {{ 8 }} },
         { 0, {{ 3, 6 }} },
         { 4,  sudoku::default_candidates }
      }},
      {{ // row 3
         { 8,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 9 }} },
         { 2,  sudoku::default_candidates },
         { 0, {{ 6, 9 }} },
         { 0, {{ 1 }} },
         { 0, {{ 3, 6 }} },
         { 7,  sudoku::default_candidates }
      }},
      {{ // row 4
         { 0, {{ 5, 6, 9 }} },
         { 0, {{ 1, 6, 9 }} },
         { 8,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 0, {{ 5, 9 }} },
         { 0, {{ 1, 6 }} }
      }},
      {{ // row 5
         { 0, {{ 4, 6, 7 }} },
         { 2,  sudoku::default_candidates },
         { 0, {{ 1, 6, 7 }} },
         { 0, {{ 5, 8, 9 }} },
         { 0, {{ 5, 8 }} },
         { 0, {{ 5, 9 }} },
         { 0, {{ 3 }} },
         { 0, {{ 4 }} },
         { 0, {{ 1, 6 }} }
      }},
      {{ // row 6
         { 0, {{ 4, 5, 9 }} },
         { 0, {{ 4, 9 }} },
         { 3,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 5, 8, 9 }} },
         { 0, {{ 5, 8 }} }
      }},
      {{ // row 7
         { 0, {{ 4, 5, 7 }} },
         { 0, {{ 4, 8 }} },
         { 0, {{ 5, 7 }} },
         { 0, {{ 5, 7, 8 }} },
         { 9,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates }
      }},
      {{ // row 8
         { 2,  sudoku::default_candidates },
         { 0, {{ 6, 8, 9 }} },
         { 0, {{ 5, 6, 7, 9 }} },
         { 0, {{ 1, 5, 7, 8 }} },
         { 0, {{ 1, 5, 8 }} },
         { 0, {{ 5, 7 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 5, 8, 9 }} },
         { 3,  sudoku::default_candidates }
      }},
      {{ // row 9
         { 1,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 0, {{ 5, 9 }} },
         { 6,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 0, {{ 9 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 5, 8 }} }
      }}
   }};
   sudoku s2(p2);
   s1.reduce_naked_triple();
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   }   
}

// from https://www.sudokuwiki.org/Hidden_Candidates#HP
// note: after the row and column there's a triple in block 2 (0-indexed)
// block:
// row = 2
// columns = { 5, 7, 8, }
// candidates = { 7, 8, 9, }

TEST(sudoku, find_hidden_triple)
{
   sudoku::puzzle_data_t p1 {{ // puzzle
      {{ // row 1
         { 0, {{ 4, 7, 8, 9 }} },
         { 0, {{ 4, 8, 9 }} },
         { 0, {{ 4, 7 }} },
         { 0, {{ 2, 4, 5, 6, 7, 8 }} },
         { 0, {{ 4, 7, 8 }} },
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 4, 6, 9 }} },
         { 3,  sudoku::default_candidates },
         { 0, {{ 2, 4, 5, 7, 8, 9 }} }
      }},
      {{ // row 2
         { 2,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 4, 5, 6, 7, 8 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 5, 7, 8 }} },
         { 0, {{ 4, 6 }} },
         { 0, {{ 5, 6 }} },
         { 0, {{ 4, 5, 7, 8 }} }
      }},
      {{ // row 3
         { 0, {{ 4, 7, 8, 9 }} },
         { 6,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 0, {{ 2, 4, 7, 8 }} },
         { 0, {{ 4, 7, 8 }} },
         { 3,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 8, 9 }} },
         { 0, {{ 2, 4, 7, 8, 9 }} }
      }},
      {{ // row 4
         { 6,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 0, {{ 1, 5 }} },
         { 0, {{ 1, 5 }} }
      }},
      {{ // row 5
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 4, 9 }} },
         { 3,  sudoku::default_candidates },
         { 0, {{ 7, 8 }} },
         { 5,  sudoku::default_candidates },
         { 0, {{ 7, 8 }} },
         { 0, {{ 2, 4, 9 }} },
         { 0, {{ 2, 9 }} },
         { 6,  sudoku::default_candidates }
      }},
      {{ // row 6
         { 0, {{ 4, 5, 9 }} },
         { 0, {{ 2, 4, 5, 9 }} },
         { 0, {{ 2, 4 }} },
         { 1,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 2, 8, 9 }} },
         { 0, {{ 2, 4, 8, 9 }} }
      }},
      {{ // row 7
         { 0, {{ 4, 8 }} },
         { 0, {{ 1, 2, 4, 8 }} },
         { 9,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 2, 8 }} },
         { 5,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 2 }} }
      }},
      {{ // row 8
         { 0, {{ 5, 7 }} },
         { 0, {{ 2, 5 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 2, 5, 7 }} },
         { 1,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates }
      }},
      {{ // row 9
         { 3,  sudoku::default_candidates },
         { 0, {{ 1, 2, 4, 5, 8 }} },
         { 0, {{ 2, 4, 7 }} },
         { 0, {{ 2, 4, 5, 7, 8 }} },
         { 0, {{ 4, 7, 8 }} },
         { 0, {{ 2, 5, 7, 8 }} },
         { 0, {{ 2, 6, 9 }} },
         { 0, {{ 1, 6 }} },
         { 0, {{ 1, 2, 9 }} }
      }}
   }};
   sudoku s1(p1);
   sudoku::puzzle_data_t p2 {{ // puzzle
      {{ // row 1
         { 0, {{ 4, 7, 8, 9 }} },
         { 0, {{ 4, 8, 9 }} },
         { 0, {{ 4, 7 }} },
         { 0, {{ 2, 5, 6 }} },
         { 0, {{ 4, 7, 8 }} },
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 6 }} },
         { 3,  sudoku::default_candidates },
         { 0, {{ 2, 5 }} }
      }},
      {{ // row 2
         { 2,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 4, 5, 6, 7, 8 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 5, 7, 8 }} },
         { 0, {{ 4, 6 }} },
         { 0, {{ 5, 6 }} },
         { 0, {{ 7, 8 }} }
      }},
      {{ // row 3
         { 0, {{ 4, 7, 8, 9 }} },
         { 6,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 0, {{ 2, 4, 7, 8 }} },
         { 0, {{ 4, 7, 8 }} },
         { 3,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 8, 9 }} },
         { 0, {{ 7, 8 }} }
      }},
      {{ // row 4
         { 6,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 0, {{ 1, 5 }} },
         { 0, {{ 1, 5 }} }
      }},
      {{ // row 5
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 4, 9 }} },
         { 3,  sudoku::default_candidates },
         { 0, {{ 7, 8 }} },
         { 5,  sudoku::default_candidates },
         { 0, {{ 7, 8 }} },
         { 0, {{ 2, 4, 9 }} },
         { 0, {{ 2, 9 }} },
         { 6,  sudoku::default_candidates }
      }},
      {{ // row 6
         { 0, {{ 4, 5, 9 }} },
         { 0, {{ 2, 4, 5, 9 }} },
         { 0, {{ 2, 4 }} },
         { 1,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 2, 8, 9 }} },
         { 0, {{ 4, 8 }} }
      }},
      {{ // row 7
         { 0, {{ 4, 8 }} },
         { 0, {{ 1, 2, 4, 8 }} },
         { 9,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 2, 8 }} },
         { 5,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 2 }} }
      }},
      {{ // row 8
         { 0, {{ 5, 7 }} },
         { 0, {{ 2, 5 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 2, 5, 7 }} },
         { 1,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates }
      }},
      {{ // row 9
         { 3,  sudoku::default_candidates },
         { 0, {{ 1, 2, 4, 5, 8 }} },
         { 0, {{ 2, 4, 7 }} },
         { 0, {{ 2, 4, 5, 7, 8 }} },
         { 0, {{ 4, 7, 8 }} },
         { 0, {{ 2, 5, 7, 8 }} },
         { 0, {{ 2, 6, 9 }} },
         { 0, {{ 1, 6 }} },
         { 0, {{ 1, 2, 9 }} }
      }}
   }};
   sudoku s2(p2);
   s1.find_hidden_triple();
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   }
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}