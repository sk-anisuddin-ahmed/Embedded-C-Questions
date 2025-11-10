/*
Problem: Count Different Bits
Given two integers, calculate how many bits differ between them
(i.e., bits that need flipping to convert one number into the other).

Example:
Input: a = 10 (1010), b = 20 (10100)
Output: 2 (bits at positions 2 and 4 need to be flipped)
*/

#include <stdio.h>

int countDifferentBits(int a, int b) 
{
    int xor = a ^ b;
    int cnt = 0;
    while (xor)
    {
        xor &= (xor - 1);
        cnt++;
    }
    return cnt;
}

int main() 
{
    int a = 10, b = 20;
    printf("Number of different bits between %d and %d is %d\n",
           a, b, countDifferentBits(a, b));
    
    return 0;
}