/*
Problem: Greatest Power of Two
Given a number N, find the greatest power of two that is
less than or equal to N.

Example:
Input: 16
Output: 16 (2^4)
Input: 10
Output: 8 (2^3)
*/

#include <stdio.h>

int findGreatestPowerTwo(int n) 
{
    if ((n & (n - 1)) == 0) return n;
    int cnt = 0;
    while (n > 1)
    {
        n >>= 1;
        cnt++;
    }
    n <<= cnt;
    return n;
}

int main() 
{
    int n = 19; 
    printf("Greatest power of 2 less than or equal to %d is %d\n",
           n, findGreatestPowerTwo(n));

    return 0;
}