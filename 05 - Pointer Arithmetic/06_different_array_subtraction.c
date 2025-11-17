/*
Problem: Pointer subtraction between different arrays
Given two pointers pointing to elements in different arrays,
what happens when you subtract them and how compiler interprets result.

Example:
int *a points to arr1[1], int *b points to arr2[2]
Result: Undefined behavior - pointers must be in same array
*/

#include <stdio.h>

int main()
{
    int arr1[] = {10, 20, 30};
    int arr2[] = {40, 50, 60};
    int *a = arr1 + 1;
    int *b = arr2 + 2;
    
    printf("Subtraction b - a: %ld (UNDEFINED BEHAVIOR)\n", b - a);
    
    return 0;
}