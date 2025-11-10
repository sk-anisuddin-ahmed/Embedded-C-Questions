/*
Problem: Minimum Bit Flips
Given two integers A and B, find the minimum number of bit flips
required to convert integer A to integer B.

Example:
Input: A = 10 (1010), B = 20 (10100)
Output: 2 (need to flip two bits to convert A to B)
*/

#include <stdio.h>

int minBitFlips(int a, int b) 
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
    printf("Number of required to flip between %d and %d is %d\n", a, b, minBitFlips(a, b));
    
    return 0;

    return 0;
}