/*
Problem: Single Unique Number
In an array where every element appears twice except one element
that appears only once, find that single unique element.

Example:
Input: arr[] = {7, 3, 5, 4, 5, 3, 4}
Output: 7 (appears only once while all others appear twice)
*/

#include <stdio.h>

int findSingleUnique(int arr[], int size) 
{
    int xor = 0;
    for (int i = 0; i < size; i++)
    {
        xor ^= arr[i];
    }
    return xor;
}

int main() 
{
    int test[] = {7, 3, 5, 4, 5, 3, 4};
    int size = sizeof(test) / sizeof(test[0]);
    printf("The unique element is %d\n", findSingleUnique(test, size));

    return 0;
}