#!/bin/bash
gcc -Wall -Wextra -pedantic -fPIC -c *.c
gcc -shared -Wl,-soname,liball.so -o liball.so *.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
