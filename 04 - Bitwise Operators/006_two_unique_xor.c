/*
Problem: Two Unique Numbers using XOR
Given an array where every element appears twice except two elements appearing once,
find those two unique elements using XOR operations.

Example:
Input: arr[] = {2, 4, 6, 8, 2, 4, 7, 8}
Output: 6 and 7 (these two numbers appear only once)
*/

#include <stdio.h>

void findTwoUniqueXOR(int arr[], int size, int *x, int *y) 
{
    int xorAll = 0;
    for (int i = 0; i < size; i++)
    {
        xorAll ^= arr[i];
    }

    int diffBit = xorAll & -xorAll;
    *x = 0, *y = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] & diffBit)
        {
            *x ^= arr[i];
        }
        else
        {
            *y ^= arr[i];
        }
    }
}

int main() 
{
    int arr[] = {2, 4, 6, 8, 2, 4, 7, 8};
    int size = sizeof(arr)/sizeof(arr[0]);
    int x, y;
    
    findTwoUniqueXOR(arr, size, &x, &y);
    printf("The two unique numbers are %d and %d\n", x, y);
    
    return 0;
}