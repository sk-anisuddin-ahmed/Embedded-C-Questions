/*
Problem: XOR from 1 to N
Compute the XOR of all integers in the range from 1 up to n without iterating
over the entire range.

Example:
Input: n = 5
Output: 1 (1 ^ 2 ^ 3 ^ 4 ^ 5 = 1)
*/

#include <stdio.h>

int xorOneToN(int n) 
{
    switch (n % 4) 
    {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
    return 0;
}

int main() 
{
    int n = 5;
    printf("XOR of all numbers from 1 to %d is %d\n", n, xorOneToN(n));
    
    return 0;
}