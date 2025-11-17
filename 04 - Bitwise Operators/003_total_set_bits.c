/*
Problem: Total Set Bits Count
Calculate the total count of set bits (1s) in the binary representation 
of all numbers from 1 up to a given number n.

Example:
Input: n = 3
Output: 4 (1 -> 1, 2 -> 10, 3 -> 11, total = 4 set bits)
*/

#include <stdio.h>

int largestPower(int n)
{
    if (n == 0) return 0;
    int out = 0;
    while ((1 << out) <= n) out++;
    return (out - 1);
}

int totalSetBits(int n) 
{
    if (n == 0) return 0;
    int largePower = largestPower(n);
    int largePowerTotalBits = (1 << (largePower - 1))  * largePower;
    int remainingNumsTopBits = n - (1 << largePower);
    return largePowerTotalBits + remainingNumsTopBits + totalSetBits(remainingNumsTopBits);
}

int main() 
{
    int n = 158;
    printf("Total set bits from 1 to %d: %d\n", n, totalSetBits(n));
    
    return 0;
}