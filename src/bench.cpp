#include <iostream>

#include <benchmark/benchmark.h>

#include "sudoku.hpp"

static void BM_PUZZLE_1(benchmark::State& state) {
   for (auto _ : state) {
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
      s1.set_candidates();
      s1.solve_single_candidates();
   }
}

BENCHMARK(BM_PUZZLE_1);

static void BM_PUZZLE_2(benchmark::State& state) {
   for (auto _ : state) {
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
      sudoku s1(p1);
      s1.set_candidates();
      s1.solve_puzzle();
   }
}

BENCHMARK(BM_PUZZLE_2);

BENCHMARK_MAIN();
