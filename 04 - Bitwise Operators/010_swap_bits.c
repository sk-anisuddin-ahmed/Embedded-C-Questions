/*
Problem: Swap Bits
Given a number and two bit positions, swap the bits at those positions using
bitwise operations.

Example:
Input: n = 12 (1100), i = 1, j = 2
Output: 10 (1010) - after swapping bits at positions 1 and 2
*/

#include <stdio.h>

int swapBits(int n, int i, int j) 
{
    int bitVali = (((1 << i) & n) > 0);
    int bitValj = (((1 << j) & n) > 0);
    if (bitVali != bitValj) 
    {
        n ^= (1 << i);
        n ^= (1 << j);
    }
    return n;
}

int main() 
{
    int n = 12, i = 1, j = 2;
    printf("After swapping bits at positions %d and %d, %d becomes %d\n",
           i, j, n, swapBits(n, i, j));
    
    return 0;
}