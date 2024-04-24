# Introduction 

This code solves Problem 96 of Project Euler. The binary solver returns the answer. 

This code can be used to solve sudoku puzzles. You can instantiate `sudoku` with a string of 81 numbers using the number `0` for blanks. 

# Notes on building

This currently only builds with `gcc` due to the flags I used. I will patch this up in the future so it can build with `clang`. In the meantime you can edit
`src/Makefile.am` to remove any flags that give you problems. 
