/*
Problem: Find Set Bit Position
For a number that has exactly one set bit (i.e., is a power of two),
find the position/index of that set bit (0-based from LSB).

Example:
Input: n = 8 (1000 in binary)
Output: 3 (as the set bit is at position 3, counting from 0)
*/

#include <stdio.h>

int findBitPosition(int n) 
{
    int count = 0;
    while (n)
    {
        count++;
        n >>= 1;
    }
    return count - 1;
}

int main() 
{
    int n = 255;  // binary: 1000
    printf("Position of set bit in %d is %d\n", n, findBitPosition(n));
    
    return 0;
}