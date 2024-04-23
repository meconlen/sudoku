#pragma once

#include "sudoku.hpp"


namespace sudoku_puzzles {

namespace set_candidates {
   extern sudoku::puzzle_input_data_t p1;

   inline sudoku::puzzle_input_data_t p1 {{
      {{0,0,3,0,2,0,6,0,0}},
      {{9,0,0,3,0,5,0,0,1}},
      {{0,0,1,8,0,6,4,0,0}},
      {{0,0,8,1,0,2,9,0,0}},
      {{7,0,0,0,0,0,0,0,8}},
      {{0,0,6,7,0,8,2,0,0}},
      {{0,0,2,6,0,9,5,0,0}},
      {{8,0,0,2,0,3,0,0,9}},
      {{0,0,5,0,1,0,3,0,0}}
   }};
   inline sudoku s1(p1);

   inline sudoku::puzzle_data_t p2 {{ //puzzle
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
   inline sudoku s2(p2);
}

namespace string_constructor{
   inline std::string p1 {"814976532659123478732854169948265317275341896163798245391682754587439621426517983"};
   inline sudoku s1(p1);
   inline sudoku::puzzle_input_data_t p2 {{
      {{8,1,4,9,7,6,5,3,2}},
      {{6,5,9,1,2,3,4,7,8}},
      {{7,3,2,8,5,4,1,6,9}},
      {{9,4,8,2,6,5,3,1,7}},
      {{2,7,5,3,4,1,8,9,6}},
      {{1,6,3,7,9,8,2,4,5}},
      {{3,9,1,6,8,2,7,5,4}},
      {{5,8,7,4,3,9,6,2,1}},
      {{4,2,6,5,1,7,9,8,3}}
   }};
   inline sudoku s2(p2);
}

namespace update_candidates {
   sudoku::puzzle_input_data_t p1 {{
      {{0,0,3,0,2,0,6,0,0}},
      {{9,0,0,3,0,5,0,0,1}},
      {{0,0,1,8,0,6,4,0,0}},
      {{0,0,8,1,0,2,9,0,0}},
      {{7,0,0,0,0,0,0,0,8}},
      {{0,0,6,7,0,8,2,0,0}},
      {{0,0,2,6,0,9,5,0,0}},
      {{8,0,0,2,0,3,0,0,9}},
      {{0,0,5,0,1,0,3,0,0}}
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

}

namespace hidden_singles {
   inline sudoku::puzzle_data_t p1 {{ // puzzle
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

   inline sudoku s1(p1);

   inline sudoku::puzzle_data_t p2 {{ // puzzle
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
   inline sudoku s2(p2);
}

// test puzzle from https://www.sudokuwiki.org/Naked_Candidates#NP

namespace naked_pairs {
   inline sudoku::puzzle_data_t p1 {{ // puzzle
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

   inline sudoku s1(p1);
   inline sudoku::puzzle_data_t p2 {{ // puzzle
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
   inline sudoku s2(p2);
}

// example from https://hodoku.sourceforge.net/en/tech_hidden.php

namespace hidden_pairs_column {
   inline sudoku::puzzle_data_t p1 {{ // puzzle
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
   inline sudoku s1(p1);
   inline sudoku::puzzle_data_t p2 {{ // puzzle
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

   inline sudoku s2(p2);
}

// example from https://hodoku.sourceforge.net/en/tech_hidden.php

namespace hidden_pairs_row {
   inline sudoku::puzzle_data_t p1 {{ // puzzle
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

   inline sudoku s1(p1);
   inline sudoku::puzzle_data_t p2 {{ // puzzle
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
   inline sudoku s2(p2);
}

// example from https://www.sudokuwiki.org/Intersection_Removal#IR
// NB: The 4 in row 8, columns 2, 3 become a pointing pair only after the 4 
//    in row 7 columns 2, 3 become eliminated; so we call the function twice

namespace pointing_pair{
   inline sudoku::puzzle_data_t p1 {{ // puzzle
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

   inline sudoku s1(p1);
   inline sudoku::puzzle_data_t p2 {{ // puzzle
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

   inline sudoku s2(p2);
}

// example from: https://www.sudokuwiki.org/Intersection_Removal#LBR

namespace reduce_box_line_row {

   inline sudoku::puzzle_data_t p1 {{ // puzzle
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

   inline sudoku s1(p1);
   inline sudoku::puzzle_data_t p2 {{ // puzzle
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
   inline sudoku s2(p2);
}

// example from https://www.sudokuwiki.org/X_Wing_Strategy

namespace reduce_x_wing_column {
   inline sudoku::puzzle_data_t p1 {{ // puzzle
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

   inline sudoku s1(p1);
   inline sudoku::puzzle_data_t p2 {{ // puzzle
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
   inline sudoku s2(p2);
}

namespace reduce_x_wing_row {
   inline sudoku::puzzle_data_t p1 {{ // puzzle
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
   inline sudoku s1(p1);
   inline sudoku::puzzle_data_t p2 {{ // puzzle
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
   inline sudoku s2(p2);
}

// example from https://www.sudokuwiki.org/Naked_Candidates#NP

namespace naked_triple
{
   inline sudoku::puzzle_data_t p1 {{ // puzzle
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
   inline sudoku s1(p1);
   inline sudoku::puzzle_data_t p2 {{ // puzzle
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
   inline sudoku s2(p2);
}

// from https://www.sudokuwiki.org/Hidden_Candidates#HP

namespace find_hidden_triple
{
   inline sudoku::puzzle_data_t p1 {{ // puzzle
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
   inline sudoku s1(p1);
   inline sudoku::puzzle_data_t p2 {{ // puzzle
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
   inline sudoku s2(p2);
}



}