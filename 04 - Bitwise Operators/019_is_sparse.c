/*
Problem: Sparse Number
A number is called sparse if there are no two adjacent 1s in its
binary representation. Check whether a given number is sparse or not.

Example:
Input: 72 (1001000)
Output: true (no adjacent 1s)
Input: 12 (1100)
Output: false (has adjacent 1s)
*/

#include <stdio.h>

int isSparse(int n) 
{
    int cnt = 0;
    while (n)
    {
        n >>= 1;
        if (n & 1)
            cnt++;
        else
            cnt = 0;
        if (cnt > 1) return 0;
    }
    return 1;
}

int main() 
{
    int n = 12;  // Test case: 1001000
    printf("%d is %s sparse number\n", 
           n, isSparse(n) ? "a" : "not a");

    return 0;
}