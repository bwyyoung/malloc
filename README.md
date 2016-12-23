
# 42 Malloc
This project is based on an assignment given by ecole 42. 

The python test script is originally authored by gbersac
(https://github.com/gbersac/malloc-42/blob/master/test/test.py) 
but corrected and modified to suit the requirements set by the assignment.

Read the pdf for the requirements.

## Features
- Binary Tree system for TINY, SMALL, and LARGE mallocs.
- Highly efficient Malloc with *minimal* overhead
- Example: A malloc of 1024 * 1024 bytes (256 Pages) only needs an additional 9 Pages for program structs
- quick malloc, realloc and free due to fast search algorithm
- structs are each exactly 4096 bytes (1 page on x86_64 Darwin) each.
- separation of struct's memory space, from user's malloc memory space for security & stability.
- show_alloc_mem & show_malloc_ex() showcase additional information