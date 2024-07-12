#!/bin/bash
set -e
gcc -c -Wall *.c
ar rcs liball.a *.o
