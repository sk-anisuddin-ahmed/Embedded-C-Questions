/*
Problem: Power of Two Check
Determine whether a given integer is a power of two using efficient 
bitwise operations.

Example:
Input: n = 16
Output: true (16 = 2^4)
Input: n = 12
Output: false (12 is not a power of 2)
*/

#include <stdio.h>

int isPowerOfTwo(int n) 
{    
    return !(n & (n - 1));
}

int main() 
{
    int n = 15;
    printf("%d is %s power of two\n", n, isPowerOfTwo(n) ? "a" : "not a");
    
    return 0;
}