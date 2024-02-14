#!/bin/bash
# $1 is the path to the file to compile
clang++ -std=c++20 -o "$1/a.out" "$1/main.cpp" && "$1/a.out"
