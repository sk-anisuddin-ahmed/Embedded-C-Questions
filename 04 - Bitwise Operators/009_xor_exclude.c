/*
Problem: XOR with Exclusion
Given an array, find the XOR of all elements excluding a particular 
specified element.

Example:
Input: arr[] = {1, 2, 3, 4}, index = 1
Output: 6 (1 ^ 3 ^ 4, excluding 2 at index 1)
*/

#include <stdio.h>

int xorExcluding(int arr[], int size, int excludeIdx) 
{
    int totalXOR = 0;
    for (int i = 0; i < size; i++)
        totalXOR ^= arr[i];
    return totalXOR ^ arr[excludeIdx];
}

int main() 
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int excludeIdx = 1;
    
    printf("XOR of array excluding element at index %d is %d\n",
           excludeIdx, xorExcluding(arr, size, excludeIdx));
    
    return 0;
}