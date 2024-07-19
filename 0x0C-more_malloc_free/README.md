# Memory Allocation and String Manipulation Functions

This repository contains various C functions for memory allocation and string manipulation. Each function performs specific tasks related to dynamic memory management, string concatenation, and more.

## Table of Contents

- [Tasks Overview](#tasks-overview)
- [Function Prototypes](#function-prototypes)

## Tasks Overview

### Task 0: Allocate Memory Using `malloc`
- **Function:** `void *malloc_checked(unsigned int b);`
- **Description:** Allocates memory using `malloc`. If `malloc` fails, the function causes normal process termination with a status value of 98.

### Task 1: Concatenate Two Strings
- **Function:** `char *string_nconcat(char *s1, char *s2, unsigned int n);`
- **Description:** Concatenates two strings, `s1` and the first `n` bytes of `s2`. The returned pointer points to a newly allocated space in memory, containing `s1` followed by `s2`, and null-terminated. If `n` is greater than or equal to the length of `s2`, the entire `s2` is used. If the function fails, it returns `NULL`.

### Task 2: Allocate Memory for an Array
- **Function:** `void *_calloc(unsigned int nmemb, unsigned int size);`
- **Description:** Allocates memory for an array of `nmemb` elements of `size` bytes each. The memory is set to zero. If `nmemb` or `size` is 0, or if `malloc` fails, the function returns `NULL`.

### Task 3: Create an Array of Integers
- **Function:** `int *array_range(int min, int max);`
- **Description:** Creates an array of integers containing all values from `min` (included) to `max` (included), ordered from `min` to `max`. Returns a pointer to the newly created array. If `min` is greater than `max`, or if `malloc` fails, the function returns `NULL`.

### Task 4 (Bonus): Reallocate Memory Block
- **Function:** `void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);`
- **Description:** Reallocates a memory block using `malloc` and `free`. If `new_size` is equal to `old_size`, the function returns `ptr` without any changes. If `ptr` is `NULL`, the function behaves like `malloc(new_size)`. If `new_size` is 0 and `ptr` is not `NULL`, the function frees `ptr` and returns `NULL`. Otherwise, the function reallocates the memory block.

### Task 5 (Bonus): Multiply Two Positive Numbers
- **Program:** `mul num1 num2`
- **Description:** Multiplies two positive numbers passed in base 10. Prints the result followed by a new line. If the number of arguments is incorrect or if the arguments are not composed of digits, the program prints `Error` followed by a new line and exits with a status of 98.

## Function Prototypes

```c
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
