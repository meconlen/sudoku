#include <iostream>

#include <gtest/gtest.h>

#include "sudoku.hpp"
#include "puzzles.hpp"


TEST(sudoku, operator_equal_equal)
{
   sudoku::puzzle_input_data_t p {{
      {0,0,3,0,2,0,6,0,0},
      {9,0,0,3,0,5,0,0,1},
      {0,0,1,8,0,6,4,0,0},
      {0,0,8,1,0,2,9,0,0},
      {7,0,0,0,0,0,0,0,8},
      {0,0,6,7,0,8,2,0,0},
      {0,0,2,6,0,9,5,0,0},
      {8,0,0,2,0,3,0,0,9},
      {0,0,5,0,1,0,3,0,0}
   }};
   sudoku s(p);
   EXPECT_EQ(s, s);
}

TEST(sudoku, update_candidates)
{
   sudoku::puzzle_input_data_t p1 {{
      {0,0,3,0,2,0,6,0,0},
      {9,0,0,3,0,5,0,0,1},
      {0,0,1,8,0,6,4,0,0},
      {0,0,8,1,0,2,9,0,0},
      {7,0,0,0,0,0,0,0,8},
      {0,0,6,7,0,8,2,0,0},
      {0,0,2,6,0,9,5,0,0},
      {8,0,0,2,0,3,0,0,9},
      {0,0,5,0,1,0,3,0,0}
   }};

   sudoku::puzzle_data_t p2 {{ //puzzle
      {{ // row
         { 0, sudoku::default_candidates }, // entry
         { 0, sudoku::default_candidates }, // entry
         { 3, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 2, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 6, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 0, sudoku::default_candidates }
      }},
      {{ 
         { 9, sudoku::default_candidates }, // entry
         { 0, sudoku::default_candidates }, // entry
         { 0, sudoku::default_candidates },
         { 3, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 5, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 1, sudoku::default_candidates }
      }},
      {{ 
         { 0, sudoku::default_candidates }, // entry
         { 0, sudoku::default_candidates }, // entry
         { 1, sudoku::default_candidates },
         { 8, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 6, sudoku::default_candidates },
         { 4, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 0, sudoku::default_candidates }
      }},
      {{ 
         { 0, sudoku::default_candidates }, // entry
         { 0, sudoku::default_candidates }, // entry
         { 8, sudoku::default_candidates },
         { 1, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 2, sudoku::default_candidates },
         { 9, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 0, sudoku::default_candidates }
      }},
      {{ 
         { 7, sudoku::default_candidates }, // entry
         { 0, sudoku::default_candidates }, // entry
         { 0, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 8, sudoku::default_candidates }
      }},
      {{ 
         { 0, sudoku::default_candidates }, // entry
         { 0, sudoku::default_candidates }, // entry
         { 6, sudoku::default_candidates },
         { 7, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 8, sudoku::default_candidates },
         { 2, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 0, sudoku::default_candidates }
      }},
      {{ 
         { 0, sudoku::default_candidates }, // entry
         { 0, sudoku::default_candidates }, // entry
         { 2, sudoku::default_candidates },
         { 6, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 9, sudoku::default_candidates },
         { 5, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 0, sudoku::default_candidates }
      }},
      {{ 
         { 8, sudoku::default_candidates }, // entry
         { 0, sudoku::default_candidates }, // entry
         { 0, sudoku::default_candidates },
         { 2, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 3, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 9, sudoku::default_candidates }
      }},
      {{ 
         { 0, sudoku::default_candidates }, // entry
         { 0, sudoku::default_candidates }, // entry
         { 5, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 1, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 3, sudoku::default_candidates },
         { 0, sudoku::default_candidates },
         { 0, sudoku::default_candidates }
      }}
   }};

   sudoku s1(p1);
   sudoku s2(p2);
   EXPECT_EQ(s1, s2);

}

TEST(sudoku, print)
{
   sudoku::puzzle_input_data_t p1 {{
      {0,0,3,0,2,0,6,0,0},
      {9,0,0,3,0,5,0,0,1},
      {0,0,1,8,0,6,4,0,0},
      {0,0,8,1,0,2,9,0,0},
      {7,0,0,0,0,0,0,0,8},
      {0,0,6,7,0,8,2,0,0},
      {0,0,2,6,0,9,5,0,0},
      {8,0,0,2,0,3,0,0,9},
      {0,0,5,0,1,0,3,0,0}
   }};

   sudoku s1(p1);
   s1.print();
}

TEST(sudoku, set_candidates) 
{
   sudoku::puzzle_input_data_t p1 {{
      {0,0,3,0,2,0,6,0,0},
      {9,0,0,3,0,5,0,0,1},
      {0,0,1,8,0,6,4,0,0},
      {0,0,8,1,0,2,9,0,0},
      {7,0,0,0,0,0,0,0,8},
      {0,0,6,7,0,8,2,0,0},
      {0,0,2,6,0,9,5,0,0},
      {8,0,0,2,0,3,0,0,9},
      {0,0,5,0,1,0,3,0,0}
   }};

// The puzzle
/*
0 0 3 | 0 2 0 | 6 0 0 
9 0 0 | 3 0 5 | 0 0 1 
0 0 1 | 8 0 6 | 4 0 0 
------+-------+-------
0 0 8 | 1 0 2 | 9 0 0 
7 0 0 | 0 0 0 | 0 0 8 
0 0 6 | 7 0 8 | 2 0 0 
------+-------+-------
0 0 2 | 6 0 9 | 5 0 0 
8 0 0 | 2 0 3 | 0 0 9 
0 0 5 | 0 1 0 | 3 0 0 
*/

// {{ false, false, false, false, false, false, false, false, false }}
   sudoku::puzzle_data_t p2 {{ //puzzle
      {{ // row
         { 0, {{ 4, 5 }} }, // entry
         { 0, {{ 4, 5, 7, 8 }} }, // entry
         { 3, sudoku::default_candidates },
         { 0, {{ 4, 9 }} },
         { 2, sudoku::default_candidates },
         { 0, {{ 1, 4, 7 }} },
         { 6, sudoku::default_candidates },
         { 0, {{ 5, 7, 8, 9 }} },
         { 0, {{ 7, 5 }} }
      }},
      {{ 
         { 9, sudoku::default_candidates }, // entry
         { 0, {{ 2, 4, 6, 7, 8 }} }, // entry
         { 0, {{ 4, 7 }} },
         { 3, sudoku::default_candidates },
         { 0, {{ 4, 7 }} },
         { 5, sudoku::default_candidates },
         { 0, {{ 7, 8 }} },
         { 0, {{ 2, 7, 8 }} },
         { 1, sudoku::default_candidates }
      }},
      {{ 
         { 0, {{ 2, 5 }} }, // entry
         { 0, {{ 2, 5, 7 }} }, // entry
         { 1, sudoku::default_candidates },
         { 8, sudoku::default_candidates },
         { 0, {{ 7, 9 }} },
         { 6, sudoku::default_candidates },
         { 4, sudoku::default_candidates },
         { 0, {{ 2, 3, 5, 7, 9 }} },
         { 0, {{ 2, 3, 5, 7 }} }
      }},
      {{ 
         { 0, {{ 3, 4, 5 }} }, // entry
         { 0, {{ 3, 4, 5 }} }, // entry
         { 8, sudoku::default_candidates },
         { 1, sudoku::default_candidates },
         { 0, {{ 3, 4, 5, 6 }} },
         { 2, sudoku::default_candidates },
         { 9, sudoku::default_candidates },
         { 0, {{ 3, 4, 5, 6, 7 }} },
         { 0, {{ 3, 4, 5, 6, 7 }} }
      }},
      {{ 
         { 7, sudoku::default_candidates }, // entry
         { 0, {{ 1, 2, 3, 4, 5, 9 }} }, // entry
         { 0, {{ 4, 9 }} },
         { 0, {{ 4, 5, 9 }} },
         { 0, {{ 3, 4, 5, 6, 9 }} },
         { 0, {{ 4 }} },
         { 0, {{ 1 }} },
         { 0, {{ 1, 3, 4, 5, 6 }} },
         { 8, sudoku::default_candidates }
      }},
      {{ 
         { 0, {{ 1, 3, 4, 5 }} }, // entry
         { 0, {{ 1, 3, 4, 5, 9 }} }, // entry
         { 6, sudoku::default_candidates },
         { 7, sudoku::default_candidates },
         { 0, {{ 3, 4, 5, 9 }} },
         { 8, sudoku::default_candidates },
         { 2, sudoku::default_candidates },
         { 0, {{ 1, 3, 4, 5 }} },
         { 0, {{ 3, 4, 5 }} }
      }},
      {{ 
         { 0, {{ 1, 4, 3 }} }, // entry
         { 0, {{ 1, 4, 3, 7 }} }, // entry
         { 2, sudoku::default_candidates },
         { 6, sudoku::default_candidates },
         { 0, {{ 4, 7, 8 }} },
         { 9, sudoku::default_candidates },
         { 5, sudoku::default_candidates },
         { 0, {{ 1, 4, 7, 8 }} },
         { 0, {{ 4, 7 }} }
      }},
      {{ 
         { 8, sudoku::default_candidates }, // entry
         { 0, {{ 1, 4, 6, 7 }} }, // entry
         { 0, {{ 4, 7 }} },
         { 2, sudoku::default_candidates },
         { 0, {{ 4, 5, 7 }} },
         { 3, sudoku::default_candidates },
         { 0, {{ 1, 7 }} },
         { 0, {{ 1, 4, 6, 7 }} },
         { 9, sudoku::default_candidates }
      }},
      {{ 
         { 0, {{ 4, 6 }} }, // entry
         { 0, {{ 4, 6, 7, 9 }} }, // entry
         { 5, sudoku::default_candidates },
         { 0, {{ 4 }} },
         { 1, sudoku::default_candidates },
         { 0, {{ 4, 7 }} },
         { 3, sudoku::default_candidates },
         { 0, {{ 2, 4, 6, 7, 8 }} },
         { 0, {{ 2, 4, 6, 7 }} }
      }}
   }};


   sudoku s1(p1);
   s1.set_candidates();
   sudoku s2(p2);

   if(! (s1 == s2) ) {
      s1.print_differences(s2);
   }

   EXPECT_EQ(s1, s2);
}

// solve_single_candidates
TEST(sudoku, p01) 
{
   sudoku::puzzle_input_data_t p1 {{
      {0,0,3,0,2,0,6,0,0},
      {9,0,0,3,0,5,0,0,1},
      {0,0,1,8,0,6,4,0,0},
      {0,0,8,1,0,2,9,0,0},
      {7,0,0,0,0,0,0,0,8},
      {0,0,6,7,0,8,2,0,0},
      {0,0,2,6,0,9,5,0,0},
      {8,0,0,2,0,3,0,0,9},
      {0,0,5,0,1,0,3,0,0}
   }};

// The puzzle
/*
0 0 3 | 0 2 0 | 6 0 0 
9 0 0 | 3 0 5 | 0 0 1 
0 0 1 | 8 0 6 | 4 0 0 
------+-------+-------
0 0 8 | 1 0 2 | 9 0 0 
7 0 0 | 0 0 0 | 0 0 8 
0 0 6 | 7 0 8 | 2 0 0 
------+-------+-------
0 0 2 | 6 0 9 | 5 0 0 
8 0 0 | 2 0 3 | 0 0 9 
0 0 5 | 0 1 0 | 3 0 0 
*/

   sudoku s1(p01);
   s1.set_candidates();
   s1.solve_puzzle();

   sudoku::puzzle_input_data_t p2 {{
      {4,8,3,9,2,1,6,5,7},
      {9,6,7,3,4,5,8,2,1},
      {2,5,1,8,7,6,4,9,3},
      {5,4,8,1,3,2,9,7,6},
      {7,2,9,5,6,4,1,3,8},
      {1,3,6,7,9,8,2,4,5},
      {3,7,2,6,8,9,5,1,4},
      {8,1,4,2,5,3,7,6,9},
      {6,9,5,4,1,7,3,8,2}
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1.get_puzzle(), s2.get_puzzle());
   if(s1.get_puzzle() != s2.get_puzzle()) {
      s1.print();
   }
}

// solve_unique_candidates
TEST(sudoku, p02) 
{
   sudoku::puzzle_input_data_t p1 {{
      {2,0,0,0,8,0,3,0,0},
      {0,6,0,0,7,0,0,8,4},
      {0,3,0,5,0,0,2,0,9},
      {0,0,0,1,0,5,4,0,8},
      {0,0,0,0,0,0,0,0,0},
      {4,0,2,7,0,6,0,0,0},
      {3,0,1,0,0,7,0,4,0},
      {7,2,0,0,4,0,0,6,0},
      {0,0,4,0,1,0,0,0,3},
   }};



   sudoku s1(p02);
   s1.set_candidates();
   s1.solve_puzzle();

   sudoku::puzzle_input_data_t p2 {{
      {2,4,5,9,8,1,3,7,6},
      {1,6,9,2,7,3,5,8,4},
      {8,3,7,5,6,4,2,1,9},
      {9,7,6,1,2,5,4,3,8},
      {5,1,3,4,9,8,6,2,7},
      {4,8,2,7,3,6,9,5,1},
      {3,9,1,6,5,7,8,4,2},
      {7,2,8,3,4,9,1,6,5},
      {6,5,4,8,1,2,7,9,3},
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1.get_puzzle(), s2.get_puzzle());

   if(s1.get_puzzle() != s2.get_puzzle()) {
      s1.print_differences(s2);
   }
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}