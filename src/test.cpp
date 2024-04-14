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
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } 
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

   EXPECT_EQ(s1, s2);
   if(! (s1 == s2) ) {
      s1.print_differences(s2);
   }
}

// test using this example to find hidden singles 

TEST(sudoku, hidden_singles)
{
   sudoku::puzzle_data_t p1 {{ // puzzle
      {{ // row 1
         { 2,  sudoku::default_candidates },
         { 0, {{ 4, 5, 9 }} },
         { 0, {{ 1, 5, 6, 9 }} },
         { 0, {{ 1, 5, 9 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 5, 9 }} },
         { 0, {{ 1, 5, 9 }} },
         { 3,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates }
      }},
      {{ // row 2
         { 0, {{ 4, 5, 8 }} },
         { 0, {{ 4, 5, 8, 9 }} },
         { 0, {{ 1, 5, 9 }} },
         { 0, {{ 1, 2, 3, 5, 8, 9 }} },
         { 0, {{ 1, 5, 9 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 1, 2, 5, 9 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 4, 5 }} }
      }},
      {{ // row 3
         { 3,  sudoku::default_candidates },
         { 0, {{ 5, 7, 8, 9 }} },
         { 0, {{ 1, 5, 9 }} },
         { 0, {{ 1, 2, 5, 8, 9 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 2, 5, 8, 9 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 1, 2, 5, 9 }} },
         { 0, {{ 1, 5 }} }
      }},
      {{ // row 4
         { 0, {{ 4, 5, 6 }} },
         { 0, {{ 3, 4, 5, 9 }} },
         { 8,  sudoku::default_candidates },
         { 0, {{ 1, 5, 6, 9 }} },
         { 2,  sudoku::default_candidates },
         { 0, {{ 1, 4, 5, 9 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 5, 9 }} },
         { 0, {{ 1, 3, 5 }} }
      }},
      {{ // row 5
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 3, 4, 5, 9 }} },
         { 0, {{ 2, 3, 5, 9 }} },
         { 0, {{ 5, 7, 8, 9 }} },
         { 0, {{ 5, 9 }} },
         { 0, {{ 4, 5, 7, 8, 9 }} },
         { 0, {{ 2, 3, 5, 8, 9 }} },
         { 0, {{ 2, 5, 8, 9 }} },
         { 6,  sudoku::default_candidates }
      }},
      {{ // row 6
         { 0, {{ 5, 6 }} },
         { 0, {{ 2, 5, 9 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 5, 6, 8, 9 }} },
         { 3,  sudoku::default_candidates },
         { 0, {{ 1, 5, 8, 9 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 2, 5, 8, 9 }} },
         { 0, {{ 1, 5 }} }
      }},
      {{ // row 7
         { 0, {{ 5, 7 }} },
         { 0, {{ 2, 3, 5, 7 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 2, 3, 5, 7 }} },
         { 8,  sudoku::default_candidates },
         { 0, {{ 1, 2, 3, 5, 7 }} },
         { 0, {{ 1, 3, 5 }} },
         { 0, {{ 1, 5, 6 }} },
         { 9,  sudoku::default_candidates }
      }},
      {{ // row 8
         { 0, {{ 5, 7, 8 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 2, 3, 5 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 5, 9 }} },
         { 0, {{ 1, 2, 3, 5, 7, 9 }} },
         { 0, {{ 1, 3, 5, 8 }} },
         { 0, {{ 1, 5, 8 }} },
         { 0, {{ 1, 3, 5, 7 }} }
      }},
      {{ // row 9
         { 9,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 3, 5 }} },
         { 0, {{ 3, 5, 7 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 3, 5, 7 }} },
         { 0, {{ 3, 5, 8 }} },
         { 0, {{ 4, 5, 8 }} },
         { 2,  sudoku::default_candidates }
      }}
   }};

   sudoku s1(p1);
   s1.solve_hidden_singles();

   sudoku::puzzle_data_t p2 {{ // puzzle
      {{ // row 1
         { 2,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 1, 5, 9 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 5, 9 }} },
         { 0, {{ 1, 5, 9 }} },
         { 3,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates }
      }},
      {{ // row 2
         { 0, {{ 5 }} },
         { 0, {{ 5, 8, 9 }} },
         { 0, {{ 1, 5, 9 }} },
         { 3,  sudoku::default_candidates },
         { 0, {{ 1, 5, 9 }} },
         { 6,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates }
      }},
      {{ // row 3
         { 3,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 5, 9 }} },
         { 0, {{ 1, 2, 5, 8, 9 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 2, 5, 8, 9 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 1, 5, 9 }} },
         { 0, {{ 1, 5 }} }
      }},
      {{ // row 4
         { 4,  sudoku::default_candidates },
         { 0, {{ 3, 5, 9 }} },
         { 8,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 0, {{ 1, 5, 9 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 5, 9 }} },
         { 0, {{ 1, 3, 5 }} }
      }},
      {{ // row 5
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 3, 5, 9 }} },
         { 0, {{ 2, 3, 5, 9 }} },
         { 0, {{ 5, 7, 8, 9 }} },
         { 0, {{ 5, 9 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 3, 5, 8, 9 }} },
         { 0, {{ 2, 5, 8, 9 }} },
         { 6,  sudoku::default_candidates }
      }},
      {{ // row 6
         { 6,  sudoku::default_candidates },
         { 0, {{ 2, 5, 9 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 5, 8, 9 }} },
         { 3,  sudoku::default_candidates },
         { 0, {{ 1, 5, 8, 9 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 2, 5, 8, 9 }} },
         { 0, {{ 1, 5 }} }
      }},
      {{ // row 7
         { 0, {{ 5, 7 }} },
         { 0, {{ 2, 3, 5 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 2, 5, 7 }} },
         { 8,  sudoku::default_candidates },
         { 0, {{ 1, 2, 3, 5, 7 }} },
         { 0, {{ 1, 3, 5 }} },
         { 6,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates }
      }},
      {{ // row 8
         { 8,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 2, 3, 5 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 5, 9 }} },
         { 0, {{ 1, 2, 3, 5, 9 }} },
         { 0, {{ 1, 3, 5 }} },
         { 0, {{ 1, 5 }} },
         { 7,  sudoku::default_candidates }
      }},
      {{ // row 9
         { 9,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 3, 5 }} },
         { 0, {{ 5, 7 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 3, 5, 7 }} },
         { 0, {{ 3, 5, 8 }} },
         { 4,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates }
      }}
   }};
   sudoku s2(p2);
   EXPECT_EQ(s1, s2);

   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp();
   }   
}


// test puzzle from https://www.sudokuwiki.org/Naked_Candidates#NP

TEST(sudoku, naked_pairs)
{
   sudoku::puzzle_data_t p1 {{ // puzzle
      {{ // row 1
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 6 }} },
         { 0, {{ 1, 6 }} },
         { 0, {{ 1, 2, 5 }} },
         { 0, {{ 1, 2, 5, 6, 7 }} },
         { 0, {{ 2, 5, 6, 7 }} },
         { 9,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates }
      }},
      {{ // row 2
         { 0, {{ 7, 8 }} },
         { 3,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 0, {{ 5, 8 }} },
         { 9,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 5, 6 }} },
         { 0, {{ 5, 6, 7 }} }
      }},
      {{ // row 3
         { 0, {{ 1, 7, 8 }} },
         { 9,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 0, {{ 1, 6, 7, 8 }} },
         { 0, {{ 6, 7 }} },
         { 2,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 6, 7 }} }
      }},
      {{ // row 4
         { 3,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 8 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 2, 5, 8 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 5, 8 }} },
         { 0, {{ 1, 2, 5, 8 }} },
         { 4,  sudoku::default_candidates }
      }},
      {{ // row 5
         { 5,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 0, {{ 4, 8 }} },
         { 0, {{ 4, 8 }} },
         { 1,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates }
      }},
      {{ // row 6
         { 6,  sudoku::default_candidates },
         { 0, {{ 1, 8 }} },
         { 4,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 2, 5, 8 }} },
         { 3,  sudoku::default_candidates },
         { 0, {{ 5, 8 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 1, 2, 5 }} }
      }},
      {{ // row 7
         { 9,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 2, 4 }} },
         { 0, {{ 1, 2, 4, 6 }} },
         { 8,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 0, {{ 1, 2, 6 }} },
         { 0, {{ 1, 2, 6 }} }
      }},
      {{ // row 8
         { 0, {{ 1, 8 }} },
         { 0, {{ 1, 6, 8 }} },
         { 3,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 0, {{ 1, 2, 5, 6, 7 }} },
         { 0, {{ 2, 5, 6, 7 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 2, 5, 6, 8 }} },
         { 0, {{ 1, 2, 5, 6 }} }
      }},
      {{ // row 9
         { 2,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 6, 8 }} },
         { 0, {{ 1, 5 }} },
         { 3,  sudoku::default_candidates },
         { 0, {{ 5, 6 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 5, 6, 8 }} },
         { 9,  sudoku::default_candidates }
      }}
   }};

   sudoku s1(p1);
   s1.set_candidates();
   s1.reduce_naked_pairs();

   sudoku::puzzle_data_t p2 {{ // puzzle
      {{ // row 1
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 6 }} },
         { 0, {{ 1, 6 }} },
         { 0, {{ 2, 5 }} },
         { 0, {{ 2, 5, 7 }} },
         { 0, {{ 2, 5, 7 }} },
         { 9,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates }
      }},
      {{ // row 2
         { 0, {{ 7 }} },
         { 3,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 0, {{ 5, 8 }} },
         { 9,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 5, 6 }} },
         { 0, {{ 5, 6, 7 }} }
      }},
      {{ // row 3
         { 0, {{ 8 }} },
         { 9,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 0, {{ 1, 8 }} },
         { 0, {{ 6, 7 }} },
         { 2,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 6, 7 }} }
      }},
      {{ // row 4
         { 3,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 8 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 2, 5 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 5, 8 }} },
         { 0, {{ 1, 2 }} },
         { 4,  sudoku::default_candidates }
      }},
      {{ // row 5
         { 5,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 0, {{ 4, 8 }} },
         { 0, {{ 4, 8 }} },
         { 1,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates }
      }},
      {{ // row 6
         { 6,  sudoku::default_candidates },
         { 0, {{ 1, 8 }} },
         { 4,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 2, 5 }} },
         { 3,  sudoku::default_candidates },
         { 0, {{ 5, 8 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 1, 2 }} }
      }},
      {{ // row 7
         { 9,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 2, 4 }} },
         { 0, {{ 1, 2, 4, 6 }} },
         { 8,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 0, {{ 1, 2, 6 }} },
         { 0, {{ 1, 2, 6 }} }
      }},
      {{ // row 8
         { 0, {{ 1, 8 }} },
         { 0, {{ 1, 6, 8 }} },
         { 3,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 0, {{ 1, 2, 5, 6, 7 }} },
         { 0, {{ 2, 5, 6, 7 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 2, 5, 6, 8 }} },
         { 0, {{ 1, 2, 5, 6 }} }
      }},
      {{ // row 9
         { 2,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 6, 8 }} },
         { 0, {{ 1, 5 }} },
         { 3,  sudoku::default_candidates },
         { 0, {{ 5, 6 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 5, 6, 8 }} },
         { 9,  sudoku::default_candidates }
      }}
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_puzzle_candidates_cpp();
      s2.print_puzzle_candidates_cpp();
   }
}

// example from https://hodoku.sourceforge.net/en/tech_hidden.php

TEST(sudoku, find_hidden_pairs_column)
{
   sudoku::puzzle_data_t p1 {{ // puzzle
      {{ // row 1
         { 0, {{ 5, 6 }} },
         { 4,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 0, {{ 6, 7 }} },
         { 0, {{ 5, 7, 8 }} },
         { 0, {{ 6, 7, 8 }} }
      }},
      {{ // row 2
         { 0, {{ 5, 6 }} },
         { 8,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 0, {{ 2, 3, 6 }} },
         { 0, {{ 2, 3, 5 }} },
         { 0, {{ 2, 6 }} }
      }},
      {{ // row 3
         { 3,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates }
      }},
      {{ // row 4
         { 0, {{ 2, 4 }} },
         { 9,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 3, 7 }} },
         { 5,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 0, {{ 2, 3, 4, 7 }} },
         { 0, {{ 2, 7 }} }
      }},
      {{ // row 5
         { 0, {{ 1, 4 }} },
         { 7,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 0, {{ 3, 9 }} },
         { 2,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 0, {{ 1, 3, 4, 6 }} },
         { 0, {{ 3, 4, 9 }} },
         { 0, {{ 1, 6, 9 }} }
      }},
      {{ // row 6
         { 0, {{ 1, 2 }} },
         { 3,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 0, {{ 7, 9 }} },
         { 4,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 1, 2, 7 }} },
         { 0, {{ 2, 7, 9 }} },
         { 5,  sudoku::default_candidates }
      }},
      {{ // row 7
         { 8,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 4 }} },
         { 0, {{ 4, 9 }} },
         { 0, {{ 1, 9 }} }
      }},
      {{ // row 8
         { 7,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates }
      }},
      {{ // row 9
         { 9,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 0, {{ 2, 7 }} },
         { 0, {{ 2, 7, 8 }} },
         { 0, {{ 2, 7, 8 }} }
      }}
   }};


   sudoku s1(p1);
   s1.find_hidden_pairs();

   sudoku::puzzle_data_t p2 {{ // puzzle
      {{ // row 1
         { 0, {{ 5, 6 }} },
         { 4,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 0, {{ 6, 7 }} },
         { 0, {{ 5, 7, 8 }} },
         { 0, {{ 6, 7, 8 }} }
      }},
      {{ // row 2
         { 0, {{ 5, 6 }} },
         { 8,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 0, {{ 2, 3, 6 }} },
         { 0, {{ 2, 3, 5 }} },
         { 0, {{ 2, 6 }} }
      }},
      {{ // row 3
         { 3,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates }
      }},
      {{ // row 4
         { 0, {{ 2, 4 }} },
         { 9,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 3, 7 }} },
         { 5,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 0, {{ 2, 3, 4, 7 }} },
         { 0, {{ 2, 7 }} }
      }},
      {{ // row 5
         { 0, {{ 1, 4 }} },
         { 7,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 0, {{ 3, 9 }} },
         { 2,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 0, {{ 1, 3, 4, 6 }} },
         { 0, {{ 3, 4, 9 }} },
         { 0, {{ 1, 9 }} }
      }},
      {{ // row 6
         { 0, {{ 1, 2 }} },
         { 3,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 0, {{ 7, 9 }} },
         { 4,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 1, 2, 7 }} },
         { 0, {{ 2, 7, 9 }} },
         { 5,  sudoku::default_candidates }
      }},
      {{ // row 7
         { 8,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 4 }} },
         { 0, {{ 4, 9 }} },
         { 0, {{ 1, 9 }} }
      }},
      {{ // row 8
         { 7,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates }
      }},
      {{ // row 9
         { 9,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 0, {{ 2, 7 }} },
         { 0, {{ 2, 7, 8 }} },
         { 0, {{ 2, 7, 8 }} }
      }}
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1, s2);

   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp();
   }

}

// example from https://hodoku.sourceforge.net/en/tech_hidden.php

TEST(sudoku, find_hidden_pairs_row)
{

sudoku::puzzle_data_t p1 {{ // puzzle
   {{ // row 1
      { 0, {{ 2, 3, 4, 5, 7, 8, 9 }} },
      { 0, {{ 1, 2, 3, 4, 5, 7, 8 }} },
      { 0, {{ 1, 2, 3, 8, 9 }} },
      { 0, {{ 1, 5, 8, 9 }} },
      { 6,  sudoku::default_candidates },
      { 0, {{ 1, 5, 8, 9 }} },
      { 0, {{ 1, 5, 8 }} },
      { 0, {{ 1, 5 }} },
      { 0, {{ 2, 9 }} }
   }},
   {{ // row 2
      { 0, {{ 5, 8, 9 }} },
      { 0, {{ 1, 5, 8 }} },
      { 0, {{ 1, 8, 9 }} },
      { 0, {{ 1, 5, 8, 9 }} },
      { 4,  sudoku::default_candidates },
      { 2,  sudoku::default_candidates },
      { 7,  sudoku::default_candidates },
      { 3,  sudoku::default_candidates },
      { 6,  sudoku::default_candidates }
   }},
   {{ // row 3
      { 0, {{ 2, 5, 8, 9 }} },
      { 0, {{ 1, 2, 5, 8 }} },
      { 6,  sudoku::default_candidates },
      { 7,  sudoku::default_candidates },
      { 3,  sudoku::default_candidates },
      { 0, {{ 1, 5, 8, 9 }} },
      { 0, {{ 1, 5, 8 }} },
      { 4,  sudoku::default_candidates },
      { 0, {{ 2, 9 }} }
   }},
   {{ // row 4
      { 0, {{ 2, 3, 5 }} },
      { 9,  sudoku::default_candidates },
      { 4,  sudoku::default_candidates },
      { 0, {{ 1, 2, 3 }} },
      { 0, {{ 2, 7 }} },
      { 0, {{ 1, 3, 7 }} },
      { 0, {{ 1, 5 }} },
      { 6,  sudoku::default_candidates },
      { 8,  sudoku::default_candidates }
   }},
   {{ // row 5
      { 0, {{ 2, 3, 5, 8 }} },
      { 0, {{ 1, 2, 3, 5, 8 }} },
      { 0, {{ 1, 2, 3, 8 }} },
      { 0, {{ 1, 2, 3, 8 }} },
      { 9,  sudoku::default_candidates },
      { 6,  sudoku::default_candidates },
      { 4,  sudoku::default_candidates },
      { 0, {{ 1, 5 }} },
      { 7,  sudoku::default_candidates }
   }},
   {{ // row 6
      { 6,  sudoku::default_candidates },
      { 0, {{ 1, 8 }} },
      { 7,  sudoku::default_candidates },
      { 0, {{ 1, 4, 8 }} },
      { 5,  sudoku::default_candidates },
      { 0, {{ 1, 4, 8 }} },
      { 9,  sudoku::default_candidates },
      { 2,  sudoku::default_candidates },
      { 3,  sudoku::default_candidates }
   }},
   {{ // row 7
      { 1,  sudoku::default_candidates },
      { 0, {{ 2, 3, 4, 7 }} },
      { 0, {{ 2, 3, 9 }} },
      { 0, {{ 2, 3, 4, 6, 9 }} },
      { 0, {{ 2, 7 }} },
      { 0, {{ 3, 4, 7, 9 }} },
      { 0, {{ 3, 6 }} },
      { 8,  sudoku::default_candidates },
      { 5,  sudoku::default_candidates }
   }},
   {{ // row 8
      { 0, {{ 3, 4, 9 }} },
      { 6,  sudoku::default_candidates },
      { 0, {{ 3, 9 }} },
      { 0, {{ 3, 4, 5, 9 }} },
      { 8,  sudoku::default_candidates },
      { 0, {{ 3, 4, 5, 9 }} },
      { 2,  sudoku::default_candidates },
      { 7,  sudoku::default_candidates },
      { 1,  sudoku::default_candidates }
   }},
   {{ // row 9
      { 0, {{ 2, 3, 7, 8 }} },
      { 0, {{ 2, 3, 7, 8 }} },
      { 5,  sudoku::default_candidates },
      { 0, {{ 2, 3, 6 }} },
      { 1,  sudoku::default_candidates },
      { 0, {{ 3, 7 }} },
      { 0, {{ 3, 6 }} },
      { 9,  sudoku::default_candidates },
      { 4,  sudoku::default_candidates }
   }}
}};

   sudoku s1(p1);
   s1.find_hidden_pairs();

   sudoku::puzzle_data_t p2 {{ // puzzle
      {{ // row 1
         { 0, {{ 4, 7 }} },
         { 0, {{ 4, 7 }} },
         { 0, {{ 1, 2, 3, 8, 9 }} },
         { 0, {{ 1, 5, 8, 9 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 1, 5, 8, 9 }} },
         { 0, {{ 1, 5, 8 }} },
         { 0, {{ 1, 5 }} },
         { 0, {{ 2, 9 }} }
      }},
      {{ // row 2
         { 0, {{ 5, 8, 9 }} },
         { 0, {{ 1, 5, 8 }} },
         { 0, {{ 1, 8, 9 }} },
         { 0, {{ 1, 5, 8, 9 }} },
         { 4,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates }
      }},
      {{ // row 3
         { 0, {{ 2, 5, 8, 9 }} },
         { 0, {{ 1, 2, 5, 8 }} },
         { 6,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 0, {{ 1, 5, 8, 9 }} },
         { 0, {{ 1, 5, 8 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 2, 9 }} }
      }},
      {{ // row 4
         { 0, {{ 2, 3, 5 }} },
         { 9,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 2, 3 }} },
         { 0, {{ 2, 7 }} },
         { 0, {{ 1, 3, 7 }} },
         { 0, {{ 1, 5 }} },
         { 6,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates }
      }},
      {{ // row 5
         { 0, {{ 2, 3, 5, 8 }} },
         { 0, {{ 1, 2, 3, 5, 8 }} },
         { 0, {{ 1, 2, 3, 8 }} },
         { 0, {{ 1, 2, 3, 8 }} },
         { 9,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 1, 5 }} },
         { 7,  sudoku::default_candidates }
      }},
      {{ // row 6
         { 6,  sudoku::default_candidates },
         { 0, {{ 1, 8 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 1, 4, 8 }} },
         { 5,  sudoku::default_candidates },
         { 0, {{ 1, 4, 8 }} },
         { 9,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates }
      }},
      {{ // row 7
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 3, 4, 7 }} },
         { 0, {{ 2, 3, 9 }} },
         { 0, {{ 2, 3, 4, 6, 9 }} },
         { 0, {{ 2, 7 }} },
         { 0, {{ 3, 4, 7, 9 }} },
         { 0, {{ 3, 6 }} },
         { 8,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates }
      }},
      {{ // row 8
         { 0, {{ 3, 4, 9 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 3, 9 }} },
         { 0, {{ 3, 4, 5, 9 }} },
         { 8,  sudoku::default_candidates },
         { 0, {{ 3, 4, 5, 9 }} },
         { 2,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates }
      }},
      {{ // row 9
         { 0, {{ 2, 3, 7, 8 }} },
         { 0, {{ 2, 3, 7, 8 }} },
         { 5,  sudoku::default_candidates },
         { 0, {{ 2, 3, 6 }} },
         { 1,  sudoku::default_candidates },
         { 0, {{ 3, 7 }} },
         { 0, {{ 3, 6 }} },
         { 9,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates }
      }}
   }};
   sudoku s2(p2);
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
   sudoku::puzzle_data_t p1 {{ // puzzle
      {{ // row 1
         { 0, {{ 7, 8, 9 }} },
         { 3,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 0, {{ 4, 7, 8 }} },
         { 0, {{ 4, 5, 7, 8 }} },
         { 6,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 4, 5, 8, 9 }} },
         { 0, {{ 7, 8 }} }
      }},
      {{ // row 2
         { 4,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 5, 6, 8, 9 }} },
         { 0, {{ 2, 3, 7, 8 }} },
         { 0, {{ 3, 5, 7, 8 }} },
         { 0, {{ 2, 3, 5, 7 }} },
         { 0, {{ 2, 3, 6, 7, 9 }} },
         { 0, {{ 2, 3, 5, 8, 9 }} },
         { 0, {{ 2, 3, 6, 7, 8 }} }
      }},
      {{ // row 3
         { 0, {{ 6, 7, 8 }} },
         { 0, {{ 7, 8 }} },
         { 0, {{ 5, 6, 8 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 3, 4, 5, 7, 8 }} },
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 3, 4, 6, 7 }} },
         { 0, {{ 2, 3, 4, 5, 8 }} },
         { 0, {{ 2, 3, 6, 7, 8 }} }
      }},
      {{ // row 4
         { 5,  sudoku::default_candidates },
         { 0, {{ 2, 7, 8 }} },
         { 0, {{ 1, 8 }} },
         { 0, {{ 1, 6 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 3, 7 }} },
         { 0, {{ 2, 3, 6 }} },
         { 0, {{ 2, 3, 8 }} },
         { 4,  sudoku::default_candidates }
      }},
      {{ // row 5
         { 0, {{ 2, 8, 9 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 4, 8, 9 }} },
         { 0, {{ 3, 4, 8 }} },
         { 0, {{ 3, 4, 5, 8 }} },
         { 0, {{ 3, 4, 5 }} },
         { 0, {{ 2, 3, 9 }} },
         { 7,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates }
      }},
      {{ // row 6
         { 3,  sudoku::default_candidates },
         { 0, {{ 4, 7, 8, 9 }} },
         { 0, {{ 1, 4, 8, 9 }} },
         { 0, {{ 1, 6 }} },
         { 2,  sudoku::default_candidates },
         { 0, {{ 4, 7 }} },
         { 0, {{ 6, 9 }} },
         { 0, {{ 8, 9 }} },
         { 5,  sudoku::default_candidates }
      }},
      {{ // row 7
         { 0, {{ 1, 2, 6, 9 }} },
         { 0, {{ 2, 4, 9 }} },
         { 0, {{ 1, 3, 4, 6, 9 }} },
         { 5,  sudoku::default_candidates },
         { 0, {{ 1, 3, 4, 6, 7 }} },
         { 8,  sudoku::default_candidates },
         { 0, {{ 2, 3, 4, 7 }} },
         { 0, {{ 2, 3, 4 }} },
         { 0, {{ 2, 3, 7 }} }
      }},
      {{ // row 8
         { 0, {{ 2, 6, 8 }} },
         { 0, {{ 2, 4, 8 }} },
         { 0, {{ 3, 4, 6, 8 }} },
         { 0, {{ 2, 3, 4, 6, 7 }} },
         { 0, {{ 3, 4, 6, 7 }} },
         { 0, {{ 2, 3, 4, 7 }} },
         { 5,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates }
      }},
      {{ // row 9
         { 0, {{ 1, 2 }} },
         { 5,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 2, 3, 4 }} },
         { 0, {{ 1, 3, 4 }} },
         { 9,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 2, 3 }} }
      }}
   }};

   sudoku s1(p1);
   s1.reduce_pointing_pairs();
   s1.reduce_pointing_pairs();
   
   sudoku::puzzle_data_t p2 {{ // puzzle
      {{ // row 1
         { 0, {{ 7, 8, 9 }} },
         { 3,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 0, {{ 4, 7, 8 }} },
         { 0, {{ 4, 5, 7, 8 }} },
         { 6,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 4, 5, 9 }} },
         { 0, {{ 7, 8 }} }
      }},
      {{ // row 2
         { 4,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 5, 6, 8, 9 }} },
         { 0, {{ 2, 3, 7, 8 }} },
         { 0, {{ 3, 5, 7, 8 }} },
         { 0, {{ 2, 3, 5 }} },
         { 0, {{ 3, 7, 9 }} },
         { 0, {{ 3, 5, 9 }} },
         { 0, {{ 3, 6, 7, 8 }} }
      }},
      {{ // row 3
         { 0, {{ 6, 7, 8 }} },
         { 0, {{ 8 }} },
         { 0, {{ 5, 6, 8 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 3, 4, 5, 7, 8 }} },
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 3, 4, 7 }} },
         { 0, {{ 2, 3, 4, 5 }} },
         { 0, {{ 2, 3, 6, 7, 8 }} }
      }},
      {{ // row 4
         { 5,  sudoku::default_candidates },
         { 0, {{ 2, 7, 8 }} },
         { 0, {{ 1, 8 }} },
         { 0, {{ 1, 6 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 3, 7 }} },
         { 0, {{ 2, 3, 6 }} },
         { 0, {{ 2, 3, 8 }} },
         { 4,  sudoku::default_candidates }
      }},
      {{ // row 5
         { 0, {{ 2, 9 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 4, 9 }} },
         { 0, {{ 3, 4, 8 }} },
         { 0, {{ 3, 4, 5, 8 }} },
         { 0, {{ 3, 4, 5 }} },
         { 0, {{ 2, 3, 9 }} },
         { 7,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates }
      }},
      {{ // row 6
         { 3,  sudoku::default_candidates },
         { 0, {{ 4, 7, 8, 9 }} },
         { 0, {{ 1, 4, 8, 9 }} },
         { 0, {{ 1, 6 }} },
         { 2,  sudoku::default_candidates },
         { 0, {{ 4, 7 }} },
         { 0, {{ 6, 9 }} },
         { 0, {{ 8, 9 }} },
         { 5,  sudoku::default_candidates }
      }},
      {{ // row 7
         { 0, {{ 1, 2, 6, 9 }} },
         { 0, {{ 2, 9 }} },
         { 0, {{ 3, 6, 9 }} },
         { 5,  sudoku::default_candidates },
         { 0, {{ 1, 3, 6 }} },
         { 8,  sudoku::default_candidates },
         { 0, {{ 2, 3, 4, 7 }} },
         { 0, {{ 2, 3, 4 }} },
         { 0, {{ 2, 3, 7 }} }
      }},
      {{ // row 8
         { 0, {{ 2, 6, 8 }} },
         { 0, {{ 2, 4, 8 }} },
         { 0, {{ 3, 4, 6, 8 }} },
         { 0, {{ 2, 3, 7 }} },
         { 0, {{ 3, 6, 7 }} },
         { 0, {{ 2, 3 }} },
         { 5,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates }
      }},
      {{ // row 9
         { 0, {{ 1, 2 }} },
         { 5,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 2, 3, 4 }} },
         { 0, {{ 1, 3, 4 }} },
         { 9,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 2, 3 }} }
      }}
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1, s2);

   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp();
   }

}

// example from: https://www.sudokuwiki.org/Intersection_Removal#LBR

TEST(sudoku, reduce_box_line_row)
{
   sudoku::puzzle_data_t p1 {{ // puzzle
      {{ // row 1
         { 0, {{ 4, 5 }} },
         { 1,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 2, 4, 5 }} },
         { 0, {{ 2, 4, 5, 9 }} },
         { 7,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 0, {{ 4, 9 }} },
         { 3,  sudoku::default_candidates }
      }},
      {{ // row 2
         { 0, {{ 3, 4, 5 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 2, 3, 5 }} },
         { 8,  sudoku::default_candidates },
         { 0, {{ 2, 3, 4, 5, 6 }} },
         { 0, {{ 3, 4, 5, 6 }} },
         { 0, {{ 1, 2, 4, 7 }} },
         { 0, {{ 4, 7 }} },
         { 0, {{ 1, 4, 5, 7 }} }
      }},
      {{ // row 3
         { 8,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 2, 3, 5 }} },
         { 0, {{ 2, 3, 4, 5 }} },
         { 0, {{ 2, 3, 4, 5, 9 }} },
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 4 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 4, 5, 9 }} }
      }},
      {{ // row 4
         { 0, {{ 1, 2, 7 }} },
         { 4,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 0, {{ 1, 2, 5, 7 }} },
         { 0, {{ 1, 2, 5, 6, 7 }} },
         { 0, {{ 5, 6 }} },
         { 3,  sudoku::default_candidates },
         { 0, {{ 7, 9 }} },
         { 0, {{ 1, 7, 9 }} }
      }},
      {{ // row 5
         { 6,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 0, {{ 1, 7 }} },
         { 0, {{ 1, 3, 4, 7 }} },
         { 0, {{ 1, 3, 4, 7 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 1, 4, 7 }} },
         { 8,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates }
      }},
      {{ // row 6
         { 0, {{ 1, 2, 7 }} },
         { 3,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 0, {{ 1, 2, 4, 7 }} },
         { 0, {{ 1, 2, 4, 7, 8 }} },
         { 0, {{ 4, 8 }} },
         { 6,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 0, {{ 1, 4, 7 }} }
      }},
      {{ // row 7
         { 0, {{ 1, 3, 5, 7 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 1, 3, 5, 7 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 1, 5, 7, 8 }} },
         { 0, {{ 5, 8 }} },
         { 0, {{ 4, 7 }} },
         { 2,  sudoku::default_candidates },
         { 0, {{ 4, 7, 8 }} }
      }},
      {{ // row 8
         { 0, {{ 1, 5, 7 }} },
         { 8,  sudoku::default_candidates },
         { 0, {{ 1, 5, 7 }} },
         { 0, {{ 1, 4, 5, 7 }} },
         { 0, {{ 1, 4, 5, 7 }} },
         { 2,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates }
      }},
      {{ // row 9
         { 9,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 3, 7, 8 }} },
         { 0, {{ 3, 8 }} },
         { 5,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 7, 8 }} }
      }}
   }};

   sudoku s1(p1);
   s1.reduce_box_line();

   sudoku::puzzle_data_t p2 {{ // puzzle
      {{ // row 1
         { 0, {{ 4, 5 }} },
         { 1,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 2, 4, 5 }} },
         { 0, {{ 2, 4, 5, 9 }} },
         { 7,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 0, {{ 4, 9 }} },
         { 3,  sudoku::default_candidates }
      }},
      {{ // row 2
         { 0, {{ 3, 4, 5 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 2, 3, 5 }} },
         { 8,  sudoku::default_candidates },
         { 0, {{ 3, 4, 5, 6 }} },
         { 0, {{ 3, 4, 5, 6 }} },
         { 0, {{ 1, 2, 7 }} },
         { 0, {{ 4, 7 }} },
         { 0, {{ 1, 5, 7 }} }
      }},
      {{ // row 3
         { 8,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates },
         { 0, {{ 2, 3, 5 }} },
         { 0, {{ 3, 4, 5 }} },
         { 0, {{ 3, 4, 5, 9 }} },
         { 1,  sudoku::default_candidates },
         { 0, {{ 2 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 5, 9 }} }
      }},
      {{ // row 4
         { 0, {{ 1, 2, 7 }} },
         { 4,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 0, {{ 1, 2, 5, 7 }} },
         { 0, {{ 1, 2, 5, 6, 7 }} },
         { 0, {{ 5, 6 }} },
         { 3,  sudoku::default_candidates },
         { 0, {{ 7, 9 }} },
         { 0, {{ 1, 7, 9 }} }
      }},
      {{ // row 5
         { 6,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 0, {{ 1, 7 }} },
         { 0, {{ 1, 3, 4, 7 }} },
         { 0, {{ 1, 3, 4, 7 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 1, 4, 7 }} },
         { 8,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates }
      }},
      {{ // row 6
         { 0, {{ 1, 2, 7 }} },
         { 3,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 0, {{ 1, 2, 4, 7 }} },
         { 0, {{ 1, 2, 4, 7, 8 }} },
         { 0, {{ 4, 8 }} },
         { 6,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 0, {{ 1, 4, 7 }} }
      }},
      {{ // row 7
         { 0, {{ 1, 3, 5, 7 }} },
         { 6,  sudoku::default_candidates },
         { 0, {{ 1, 3, 5, 7 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 1, 5, 7, 8 }} },
         { 0, {{ 5, 8 }} },
         { 0, {{ 4, 7 }} },
         { 2,  sudoku::default_candidates },
         { 0, {{ 4, 7, 8 }} }
      }},
      {{ // row 8
         { 0, {{ 1, 5, 7 }} },
         { 8,  sudoku::default_candidates },
         { 0, {{ 1, 5, 7 }} },
         { 0, {{ 1, 4, 5, 7 }} },
         { 0, {{ 1, 4, 5, 7 }} },
         { 2,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 3,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates }
      }},
      {{ // row 9
         { 9,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 3, 7, 8 }} },
         { 0, {{ 3, 8 }} },
         { 5,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 7, 8 }} }
      }}
   }};   
   sudoku s2(p2);
   EXPECT_EQ(s1, s2);

   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp();
   }
}

// example from https://www.sudokuwiki.org/X_Wing_Strategy

TEST(sudoku, x_wing_column)
{
   sudoku::puzzle_data_t p1 {{ // puzzle
      {{ // row 1
         { 1,  sudoku::default_candidates },
         { 0, {{ 3, 7, 8 }} },
         { 0, {{ 3, 7 }} },
         { 0, {{ 2, 3, 4, 7, 8 }} },
         { 0, {{ 2, 7, 8 }} },
         { 0, {{ 2, 3, 4, 7, 8 }} },
         { 5,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates }
      }},
      {{ // row 2
         { 4,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 0, {{ 3, 7 }} },
         { 5,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 3, 7 }} },
         { 8,  sudoku::default_candidates }
      }},
      {{ // row 3
         { 0, {{ 3, 7, 8 }} },
         { 5,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 7, 8 }} },
         { 9,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 3, 7 }} }
      }},
      {{ // row 4
         { 0, {{ 3, 5, 7 }} },
         { 0, {{ 3, 7 }} },
         { 9,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 2, 7 }} },
         { 8,  sudoku::default_candidates },
         { 0, {{ 2, 5 }} },
         { 1,  sudoku::default_candidates }
      }},
      {{ // row 5
         { 0, {{ 5, 7 }} },
         { 6,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 2, 7, 8, 9 }} },
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 7, 8 }} },
         { 0, {{ 3, 7, 9 }} },
         { 0, {{ 2, 5 }} },
         { 0, {{ 3, 7 }} }
      }},
      {{ // row 6
         { 2,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 0, {{ 7, 9 }} },
         { 3,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 7, 9 }} },
         { 4,  sudoku::default_candidates }
      }},
      {{ // row 7
         { 0, {{ 3, 7, 8 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 3, 7 }} },
         { 5,  sudoku::default_candidates },
         { 0, {{ 2, 7, 8, 9 }} },
         { 0, {{ 2, 3, 7, 8 }} },
         { 0, {{ 3, 7, 9 }} },
         { 1,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates }
      }},
      {{ // row 8
         { 9,  sudoku::default_candidates },
         { 0, {{ 3, 7, 8 }} },
         { 5,  sudoku::default_candidates },
         { 0, {{ 3, 7, 8 }} },
         { 6,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 3, 7, 8 }} },
         { 2,  sudoku::default_candidates }
      }},
      {{ // row 9
         { 6,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 3, 4, 7, 8 }} },
         { 0, {{ 7, 8, 9 }} },
         { 0, {{ 3, 4, 7, 8 }} },
         { 0, {{ 3, 7, 9 }} },
         { 0, {{ 3, 7, 8, 9 }} },
         { 5,  sudoku::default_candidates }
      }}
   }};

   sudoku s1(p1);
   s1.reduce_x_wing();

   sudoku::puzzle_data_t p2 {{ // puzzle
      {{ // row 1
         { 1,  sudoku::default_candidates },
         { 0, {{ 3, 7, 8 }} },
         { 0, {{ 3, 7 }} },
         { 0, {{ 2, 3, 4, 8 }} },
         { 0, {{ 2, 7, 8 }} },
         { 0, {{ 2, 3, 4, 7, 8 }} },
         { 5,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates }
      }},
      {{ // row 2
         { 4,  sudoku::default_candidates },
         { 9,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 0, {{ 3, 7 }} },
         { 5,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 3, 7 }} },
         { 8,  sudoku::default_candidates }
      }},
      {{ // row 3
         { 0, {{ 3, 7, 8 }} },
         { 5,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 7, 8 }} },
         { 9,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 3, 7 }} }
      }},
      {{ // row 4
         { 0, {{ 3, 5, 7 }} },
         { 0, {{ 3, 7 }} },
         { 9,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 2, 7 }} },
         { 8,  sudoku::default_candidates },
         { 0, {{ 2, 5 }} },
         { 1,  sudoku::default_candidates }
      }},
      {{ // row 5
         { 0, {{ 5, 7 }} },
         { 6,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 2, 8, 9 }} },
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 7, 8 }} },
         { 0, {{ 3, 7, 9 }} },
         { 0, {{ 2, 5 }} },
         { 0, {{ 3, 7 }} }
      }},
      {{ // row 6
         { 2,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 8,  sudoku::default_candidates },
         { 0, {{ 7, 9 }} },
         { 3,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 7, 9 }} },
         { 4,  sudoku::default_candidates }
      }},
      {{ // row 7
         { 0, {{ 3, 7, 8 }} },
         { 4,  sudoku::default_candidates },
         { 0, {{ 3, 7 }} },
         { 5,  sudoku::default_candidates },
         { 0, {{ 2, 7, 8, 9 }} },
         { 0, {{ 2, 3, 7, 8 }} },
         { 0, {{ 3, 7, 9 }} },
         { 1,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates }
      }},
      {{ // row 8
         { 9,  sudoku::default_candidates },
         { 0, {{ 3, 7, 8 }} },
         { 5,  sudoku::default_candidates },
         { 0, {{ 3, 8 }} },
         { 6,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 3, 8 }} },
         { 2,  sudoku::default_candidates }
      }},
      {{ // row 9
         { 6,  sudoku::default_candidates },
         { 2,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 3, 4, 8 }} },
         { 0, {{ 7, 8, 9 }} },
         { 0, {{ 3, 4, 7, 8 }} },
         { 0, {{ 3, 7, 9 }} },
         { 0, {{ 3, 8, 9 }} },
         { 5,  sudoku::default_candidates }
      }}
   }};
   sudoku s2(p2);
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

TEST(sudoku, reduce_x_wing_row)
{
   sudoku::puzzle_data_t p1 {{ // puzzle
      {{ // row 1
         { 0, {{ 1, 3, 5, 8 }} },
         { 0, {{ 2, 3, 5 }} },
         { 0, {{ 1, 3, 5, 8 }} },
         { 0, {{ 3, 5, 6, 8 }} },
         { 0, {{ 6, 7, 8 }} },
         { 0, {{ 3, 5, 6, 7, 8 }} },
         { 0, {{ 6, 7 }} },
         { 9,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates }
      }},
      {{ // row 2
         { 7,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 4, 8 }} },
         { 9,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 4, 8 }} },
         { 0, {{ 2, 3 }} },
         { 5,  sudoku::default_candidates },
         { 0, {{ 2, 3 }} }
      }},
      {{ // row 3
         { 0, {{ 3, 4, 5 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 3, 4, 5 }} },
         { 0, {{ 3, 4, 5, 6 }} },
         { 0, {{ 4, 6, 7 }} },
         { 2,  sudoku::default_candidates },
         { 0, {{ 6, 7 }} },
         { 8,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates }
      }},
      {{ // row 4
         { 0, {{ 3, 4, 6 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 2, 3, 4, 6, 9 }} },
         { 0, {{ 2, 4, 6, 8 }} },
         { 5,  sudoku::default_candidates },
         { 0, {{ 4, 6, 8 }} },
         { 0, {{ 2, 3, 4, 8, 9 }} },
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 3, 8, 9 }} }
      }},
      {{ // row 5
         { 0, {{ 1, 3, 4, 5, 6 }} },
         { 0, {{ 2, 3, 5 }} },
         { 0, {{ 1, 2, 3, 4, 5, 6 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 2, 4, 6, 8 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 2, 3, 4, 5, 8 }} },
         { 0, {{ 2, 3 }} },
         { 0, {{ 2, 3, 8 }} }
      }},
      {{ // row 6
         { 0, {{ 4, 5 }} },
         { 8,  sudoku::default_candidates },
         { 0, {{ 2, 4, 5, 9 }} },
         { 0, {{ 2, 4 }} },
         { 3,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 4, 5, 9 }} },
         { 6,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates }
      }},
      {{ // row 7
         { 2,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 3, 5, 6, 8 }} },
         { 1,  sudoku::default_candidates },
         { 0, {{ 6, 8 }} },
         { 0, {{ 3, 5, 6, 8 }} },
         { 0, {{ 3, 8, 9 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 3, 6, 8, 9 }} }
      }},
      {{ // row 8
         { 0, {{ 3, 6, 8 }} },
         { 1,  sudoku::default_candidates },
         { 0, {{ 3, 6, 7, 8 }} },
         { 0, {{ 2, 3, 6, 8 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 3, 6, 7, 8 }} },
         { 0, {{ 2, 3, 8 }} },
         { 4,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates }
      }},
      {{ // row 9
         { 9,  sudoku::default_candidates },
         { 0, {{ 3, 5 }} },
         { 0, {{ 3, 5, 6, 7, 8 }} },
         { 0, {{ 2, 3, 4, 5, 6, 8 }} },
         { 0, {{ 2, 4, 6, 7, 8 }} },
         { 0, {{ 3, 4, 5, 6, 7, 8 }} },
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 3 }} },
         { 0, {{ 2, 3, 6, 8 }} }
      }}
   }};
   sudoku s1(p1);
   s1.reduce_x_wing();
   sudoku::puzzle_data_t p2 {{ // puzzle
      {{ // row 1
         { 0, {{ 1, 3, 5, 8 }} },
         { 0, {{ 2, 3, 5 }} },
         { 0, {{ 1, 3, 5, 8 }} },
         { 0, {{ 3, 5, 6, 8 }} },
         { 0, {{ 6, 7, 8 }} },
         { 0, {{ 3, 5, 6, 7, 8 }} },
         { 0, {{ 6, 7 }} },
         { 9,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates }
      }},
      {{ // row 2
         { 7,  sudoku::default_candidates },
         { 6,  sudoku::default_candidates },
         { 0, {{ 4, 8 }} },
         { 9,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 4, 8 }} },
         { 0, {{ 2, 3 }} },
         { 5,  sudoku::default_candidates },
         { 0, {{ 2, 3 }} }
      }},
      {{ // row 3
         { 0, {{ 3, 4, 5 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 3, 4, 5 }} },
         { 0, {{ 3, 4, 5, 6 }} },
         { 0, {{ 4, 6, 7 }} },
         { 2,  sudoku::default_candidates },
         { 0, {{ 6, 7 }} },
         { 8,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates }
      }},
      {{ // row 4
         { 0, {{ 3, 4, 6 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 2, 3, 4, 6, 9 }} },
         { 0, {{ 2, 4, 6, 8 }} },
         { 5,  sudoku::default_candidates },
         { 0, {{ 4, 6, 8 }} },
         { 0, {{ 2, 3, 4, 8, 9 }} },
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 3, 8, 9 }} }
      }},
      {{ // row 5
         { 0, {{ 1, 3, 4, 5, 6 }} },
         { 0, {{ 3, 5 }} },
         { 0, {{ 1, 3, 4, 5, 6 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 2, 4, 6, 8 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 3, 4, 5, 8 }} },
         { 0, {{ 2, 3 }} },
         { 0, {{ 3, 8 }} }
      }},
      {{ // row 6
         { 0, {{ 4, 5 }} },
         { 8,  sudoku::default_candidates },
         { 0, {{ 2, 4, 5, 9 }} },
         { 0, {{ 2, 4 }} },
         { 3,  sudoku::default_candidates },
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 4, 5, 9 }} },
         { 6,  sudoku::default_candidates },
         { 7,  sudoku::default_candidates }
      }},
      {{ // row 7
         { 2,  sudoku::default_candidates },
         { 4,  sudoku::default_candidates },
         { 0, {{ 3, 5, 6, 8 }} },
         { 1,  sudoku::default_candidates },
         { 0, {{ 6, 8 }} },
         { 0, {{ 3, 5, 6, 8 }} },
         { 0, {{ 3, 8, 9 }} },
         { 7,  sudoku::default_candidates },
         { 0, {{ 3, 6, 8, 9 }} }
      }},
      {{ // row 8
         { 0, {{ 3, 6, 8 }} },
         { 1,  sudoku::default_candidates },
         { 0, {{ 3, 6, 7, 8 }} },
         { 0, {{ 2, 3, 6, 8 }} },
         { 9,  sudoku::default_candidates },
         { 0, {{ 3, 6, 7, 8 }} },
         { 0, {{ 2, 3, 8 }} },
         { 4,  sudoku::default_candidates },
         { 5,  sudoku::default_candidates }
      }},
      {{ // row 9
         { 9,  sudoku::default_candidates },
         { 0, {{ 3, 5 }} },
         { 0, {{ 3, 5, 6, 7, 8 }} },
         { 0, {{ 3, 4, 5, 6, 8 }} },
         { 0, {{ 2, 4, 6, 7, 8 }} },
         { 0, {{ 3, 4, 5, 6, 7, 8 }} },
         { 1,  sudoku::default_candidates },
         { 0, {{ 2, 3 }} },
         { 0, {{ 3, 6, 8 }} }
      }}
   }};
   sudoku s2(p2);
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   }   
}

// solve_single_candidates
TEST(sudoku, p01) 
{
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
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

// solve_unique_candidates
TEST(sudoku, p02) 
{
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
      {6,5,4,8,1,2,7,9,3}
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

// solve_unique_candidates
TEST(sudoku, p03) 
{
   sudoku s1(p03);
   s1.set_candidates();
   s1.solve_puzzle();

   sudoku::puzzle_input_data_t p2 {{
      {4,6,2,8,3,1,9,5,7},
      {7,9,5,4,2,6,1,8,3},
      {3,8,1,7,9,5,4,2,6},
      {1,7,3,9,8,4,2,6,5},
      {6,5,9,3,1,2,7,4,8},
      {2,4,8,5,6,7,3,1,9},
      {9,2,6,1,7,8,5,3,4},
      {8,3,4,2,5,9,6,7,1},
      {5,1,7,6,4,3,8,9,2},
   }};

   sudoku s2(p2);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } }

TEST(sudoku, p04) 
{
   sudoku s1(p04);
   s1.set_candidates();
   s1.solve_puzzle();

   sudoku::puzzle_input_data_t p2 {{
      {1,3,7,2,5,6,8,4,9},
      {9,2,8,3,1,4,5,6,7},
      {4,6,5,8,9,7,3,1,2},
      {6,7,3,5,4,2,9,8,1},
      {8,1,9,6,7,3,2,5,4},
      {5,4,2,1,8,9,7,3,6},
      {2,5,6,7,3,1,4,9,8},
      {3,9,1,4,2,8,6,7,5},
      {7,8,4,9,6,5,1,2,3}
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

// naked pairs 
TEST(sudoku, p05) 
{
   sudoku s1(p05);
   s1.set_candidates();
   s1.solve_puzzle();

   sudoku::puzzle_input_data_t p2 {{
      {5,2,3,8,1,6,7,4,9},
      {7,8,4,5,9,3,1,2,6},
      {6,9,1,4,7,2,8,3,5},
      {2,3,9,1,4,5,6,8,7},
      {4,5,7,2,6,8,9,1,3},
      {1,6,8,9,3,7,2,5,4},
      {3,4,2,7,8,9,5,6,1},
      {9,1,5,6,2,4,3,7,8},
      {8,7,6,3,5,1,4,9,2}
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

TEST(sudoku, p06) 
{
   sudoku s1(p06);
   s1.set_candidates();
   s1.solve_puzzle();

   sudoku::puzzle_input_data_t p2 {{
      {1,7,6,9,2,3,5,8,4},
      {5,2,4,8,1,7,6,3,9},
      {8,9,3,6,5,4,2,7,1},
      {9,5,7,3,4,8,1,6,2},
      {6,3,8,1,9,2,4,5,7},
      {4,1,2,7,6,5,3,9,8},
      {2,6,5,4,8,9,7,1,3},
      {7,8,1,2,3,6,9,4,5},
      {3,4,9,5,7,1,8,2,6}
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

// we need the X-wing next 

TEST(sudoku, p07) 
{
   sudoku s1(p07);
   s1.set_candidates();
   s1.solve_puzzle();

   sudoku::puzzle_input_data_t p2 {{
      {1,4,3,9,8,6,2,5,7},
      {6,7,9,4,2,5,3,8,1},
      {2,8,5,7,3,1,6,9,4},
      {9,6,2,3,5,4,1,7,8},
      {3,5,7,6,1,8,9,4,2},
      {4,1,8,2,7,9,5,6,3},
      {8,2,1,5,6,7,4,3,9},
      {7,9,6,1,4,3,8,2,5},
      {5,3,4,8,9,2,7,1,6}
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1, s2);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

TEST(sudoku, transposed_puzzle)
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
   std::cout << std::endl;
   s.print();
   std::cout << std::endl;
   s.print_transposed();

}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}