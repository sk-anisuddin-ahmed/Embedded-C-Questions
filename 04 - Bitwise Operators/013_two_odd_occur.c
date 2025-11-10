/*
Problem: Two Numbers Occurring Odd Times
In an array where all numbers occur an even number of times except
two numbers that occur an odd number of times, find those two numbers.

Example:
Input: arr[] = {4, 2, 4, 5, 2, 3, 3, 1}
Output: 5 and 1 (these two numbers occur odd times)
*/

#include <stdio.h>

void findTwoOddOccurrences(int arr[], int size, int *out1, int *out2) 
{
    int xorAll = 0;
    for (int i = 0; i < size; i++)
    {
        xorAll ^= arr[i];
    }

    int diffBit = xorAll & -xorAll;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] & diffBit)
        {
            *out1 ^= arr[i];
        }
        else
        {
            *out2 ^= arr[i];
        }
    }
}

int main() 
{
    int test[] = {4, 2, 4, 5, 2, 3, 3, 1};
    int size = sizeof(test) / sizeof(test[0]);
    int num1 = 0, num2 = 0;

    findTwoOddOccurrences(test, size, &num1, &num2);
    printf("The two numbers occurring odd times are %d and %d\n", num1, num2);

    return 0;
}