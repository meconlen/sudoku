#include <iostream>

#include <benchmark/benchmark.h>

#include "sudoku.hpp"
#include "puzzles.hpp"

static void BM_PUZZLE_1(benchmark::State& state) {
   for (auto _ : state) {
      sudoku s1(p01);
      s1.set_candidates();
      s1.solve_single_candidates();
   }
}

BENCHMARK(BM_PUZZLE_1);

static void BM_PUZZLE_2(benchmark::State& state) {
   for (auto _ : state) {
      sudoku s1(p02);
      s1.set_candidates();
      s1.solve_puzzle();
   }
}

BENCHMARK(BM_PUZZLE_2);

BENCHMARK_MAIN();
