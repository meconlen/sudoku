# Introduction 

This code solves Problem 96 of Project Euler. The binary solver returns the answer. 

This code can be used to solve sudoku puzzles. You can instantiate `sudoku` with a string of 81 numbers using the number `0` for blanks. 

# Prerequisites  

## Mac

### Packages 

Install the following brews (or similar for your package manager)

* `autoconf`
* `automake`
* `google-benchmark`

## Linux

On Debian install the following (substitute for your Linux system as necessary)

* `g++`
* `autoconf`
* `automake`
* `libtool`
* `make`
* `libbenchmark-dev`
* `git`

# Build

## Mac 

Run the following (substitute for `/opt/homebrew/` if you use a different package manager)

```
git submodule update --init --recursive
autoreconf -vfi 
./configure CPPFLAGS="-O3 -g -march=native -I/opt/homebrew/include" LDFLAGS="-L/opt/homebrew/lib"
make
```

## Linux

Run the following

```
git submodule update --init --recursive
autoreconf -vfi
./configure CPPFLAGS="-O3 -g -march=native"
make
```

# Binaries 

In the source directory you will have three binaries 

## `solver`

This binary will solve Project Euler Problem 96

## `test`

This runs the unit tests

## `bench`

This runs benchmarks to evaluate changes


