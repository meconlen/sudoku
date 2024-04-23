cxx_flags = -Werror -Wall -pedantic -Wcast-align -Wcast-align -Wcast-qual \
-Wctor-dtor-privacy -Wdisabled-optimization -Weffc++ -Wextra -Wfloat-equal \
-Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs \
-Wnoexcept -Wno-unused -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual \
-Wparentheses -Wpointer-arith -Wredundant-decls -Wreturn-type -Wshadow \
-Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wswitch-default -Wundef \
-Wuninitialized -Wunreachable-code -Wunused -Wwrite-strings -Wmissing-braces

check_LTLIBRARIES = libgtest.la
libgtest_la_SOURCES = ../googletest/googletest/src/gtest-all.cc
libgtest_la_CPPFLAGS = -isystem$ $(top_srcdir)/googletest/googletest/include -isystem $(top_srcdir)/googletest/googletest
libgtest_la_LDFLAGS = -pthread

noinst_PROGRAMS = test bench

test_SOURCES = test.cpp euler.cpp sudoku.cpp
test_CPPFLAGS = -isystem ${top_srcdir}/googletest/googletest/include/
test_CXXFLAGS = ${cxx_flags}
test_LDADD = libgtest.la
test_LDFLAGS = -pthread -lm

bench_SOURCES = bench.cpp sudoku.cpp
bench_CXXFLAGS = ${cxx_flags}
bench_LDFLAGS = -lbenchmark -pthread -lm

bin_PROGRAMS = test bench solver

solver_SOURCES = solver.cpp sudoku.cpp
solver_CXXFLAGS = ${cxx_flags}

TESTS = test
