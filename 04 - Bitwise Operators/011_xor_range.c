/*
Problem: XOR in Range
Find the XOR of all numbers between L and R (inclusive) without iterating
through each number.

Example:
Input: L = 3, R = 7
Output: 3 (3 ^ 4 ^ 5 ^ 6 ^ 7)
*/

#include <stdio.h>

int xorUptoN(int n) 
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

int findRangeXOR(int L, int R) 
{
    return xorUptoN(R) ^ xorUptoN(L - 1);
}

int main() 
{
    int L = 3, R = 7;
    printf("XOR of all numbers in range [%d, %d] is %d\n", L, R, findRangeXOR(L, R));
    
    return 0;
}