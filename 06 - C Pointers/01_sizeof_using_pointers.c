/*
Problem Statement:
Find the size of a data type without using the sizeof operator, using pointer arithmetic
*/

#include <stdio.h>

#define TypeCheck(type) (size_t)((char*)((type*) 0 + 1) - (char*)((char*) 0))

int main() 
{
    printf("Size of int: %zu bytes\n", TypeCheck(double));
    return 0;
}