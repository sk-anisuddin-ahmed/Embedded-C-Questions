/*
Problem: Two Unique Numbers
In an array where all numbers appear twice except two numbers that appear once,
identify those two unique numbers.

Example:
Input: arr[] = {2, 4, 7, 9, 2, 4}
Output: 7 and 9 (these two numbers appear only once)
*/

#include <stdio.h>

void findTwoUnique(int arr[], int size, int *num1, int *num2) 
{
    int xorAll = 0;
    for (int i = 0; i < size; i++)
    {
        xorAll ^= arr[i];
    }

    int diffBit = xorAll & (-xorAll); //Checks for rightmost set bit

    for (int i = 0; i < size; i++)
    {
        if (arr[i] & diffBit)
        {
            *num1 ^= arr[i];
        }
        else
        {
            *num2 ^= arr[i];
        }
    }
}

int main() 
{
    int arr[] = {2, 4, 7, 9, 2, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int num1 = 0, num2 = 0;
    
    findTwoUnique(arr, size, &num1, &num2);
    printf("The two unique numbers are: %d and %d\n", num1, num2);
    
    return 0;
}