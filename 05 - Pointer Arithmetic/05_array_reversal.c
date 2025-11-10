/*
Problem: Reverse array in place using only two pointers
Given an integer array, reverse it in place without using
any index or size variables - just two pointers.

Example:
Input: [1, 2, 3, 4, 5]
Output: [5, 4, 3, 2, 1]
*/

#include <stdio.h>

void reverseArrayTwoPointers(int *arr, int size)
{
    int *left = arr;
    int *right = arr + size - 1;
    int temp;
    
    while (left < right)
    {
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    reverseArrayTwoPointers(arr, size);
    
    printf("Reversed array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}