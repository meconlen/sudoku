check_LTLIBRARIES = libgtest.la
libgtest_la_SOURCES = ../googletest/googletest/src/gtest-all.cc
libgtest_la_CPPFLAGS = -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/googletest/googletest
libgtest_la_LDFLAGS = -pthread

noinst_PROGRAMS = test bench

test_SOURCES = test.cpp euler.cpp sudoku.cpp
test_CPPFLAGS = -I ${top_srcdir}/googletest/googletest/include/
test_LDADD = libgtest.la
test_LDFLAGS = -pthread -lm

bench_SOURCES = bench.cpp sudoku.cpp
bench_LDFLAGS = -lbenchmark -pthread -lm

bin_PROGRAMS = test bench solver

solver_SOURCES = solver.cpp sudoku.cpp

TESTS = test
