#!/bin/bash
for f in ./test_cases/case*/*.in
do
  echo "Testing file " "$f"
  ./a.exe < $f > $f.1.out
  ./a.exe < $f > $f.2.out
  ./a.exe < $f > $f.3.out

  #valgrind option
  # valgrind --leak-check=full --log-file="$f.valgrind" -v ./a.out < $f
done
