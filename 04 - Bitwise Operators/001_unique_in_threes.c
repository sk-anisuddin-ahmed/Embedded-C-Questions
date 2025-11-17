/*
Problem: Find the Unique Number in Array
Given an array where every element appears three times except one element
that appears only once, find that unique element.

Example:
Input: arr[] = {2, 2, 3, 2, 7, 7, 8, 7, 8, 8}
Output: 3 (it appears only once while others appear thrice)
*/

#include <stdio.h>

int findUniqueInThrees(int arr[], int size)
{
    unsigned int result = 0u;
    int sizeInt = sizeof(int) * 8;
    for (int bit = 0; bit < sizeInt; ++bit) 
    {
        int sum = 0;
        for (int i = 0; i < size; ++i) 
        {
            sum += ( ( (unsigned int)arr[i] >> bit ) & 1u );
        }
        if (sum % 3) result |= (1u << bit);
    }
    return (int)result;
}

int main() 
{
    int arr[] = {2, 2, 3, 2, 7, 7, 8, 7, 8, 8};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("The unique element is: %d\n", findUniqueInThrees(arr, size));
    
    return 0;
}