/*
Problem: Power of Four
Determine whether a given number is a power of four efficiently.
A number is a power of four if it is a power of two and its only set bit
is at an even position (0-based indexing).

Example:
Input: 16 (10000)
Output: true (16 is 4^2)
Input: 8 (1000)
Output: false (8 is 2^3, not a power of 4)
*/

#include <stdio.h>
#include <stdbool.h>

int isPowerOfFour(int n) 
{
    if (n == 0) return false;
    if (n & (n - 1)) return false;
    return ((n & 0x55555555) > 0);
}

int main() 
{
    int n = 16;
    printf("%d is %s power of four\n", n, isPowerOfFour(n) ? "a" : "not a");

    return 0;
}