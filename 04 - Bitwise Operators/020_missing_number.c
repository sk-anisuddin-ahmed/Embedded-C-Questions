/*
Problem: Missing Number
Given an array of size n-1 containing numbers from 1 to n with
one number missing, find the missing number using XOR operations.

Example:
Input: arr[] = {1, 2, 4, 5, 6}, n = 6
Output: 3 (missing number)
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

int findMissingNumber(int arr[], int size) 
{
    int totalXor = xorUptoN(arr[size - 1]);
    for (int i = 0; i < size; i++)
    {
        totalXor ^= arr[i];
    }
    return totalXor;
}

int main() 
{
    int test[] = {1, 2, 4, 5, 6};
    int size = sizeof(test) / sizeof(test[0]);
    printf("The missing number is %d\n", findMissingNumber(test, size));

    return 0;
}