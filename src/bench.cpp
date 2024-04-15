#include <iostream>

#include <benchmark/benchmark.h>

#include "sudoku.hpp"
#include "puzzles.hpp"

static void BM_PUZZLE_1(benchmark::State& state) {
   for (auto _ : state) {
      sudoku s1(p01);
      s1.solve_puzzle();
   }
}

BENCHMARK(BM_PUZZLE_1);

static void BM_PUZZLE_2(benchmark::State& state) {
   for (auto _ : state) {
      sudoku s1(p02);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_2);

static void BM_PUZZLE_3(benchmark::State& state) {
   for (auto _ : state) {
      sudoku s1(p03);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_3);

static void BM_PUZZLE_4(benchmark::State& state) {
   for (auto _ : state) {
      sudoku s1(p04);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_4);

static void BM_PUZZLE_5(benchmark::State& state) {
   for (auto _ : state) {
      sudoku s1(p05);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_5);

static void BM_PUZZLE_6(benchmark::State& state) {
   for (auto _ : state) {
      sudoku s1(p06);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_6);

static void BM_PUZZLE_7(benchmark::State& state) {
   for (auto _ : state) {
      sudoku s1(p07);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_7);

static void BM_PUZZLE_8(benchmark::State& state) {
   for (auto _ : state) {
      sudoku s1(p08);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_8);

BENCHMARK_MAIN();
