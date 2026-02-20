/*
7. Memory Management and Buffer Overflow Prevention
Goal: Implement safe memory handling practices to prevent buffer overflows and related security issues.

Activity:

Allocate buffers dynamically to match expected input sizes.
Use safe input functions that limit the number of characters read.
Validate input sizes before copying or appending to buffers.
Practice freeing memory correctly to avoid leaks or dangling pointers.
*/

#include<stdio.h>
#define BUF_SIZE 100

