/*
10. Find all pairs in the array whose sum is equal to a given number
Given an array and a number, find all pairs whose sum equals the given number. 
Optimize for time complexity using hash map.

Example: Input: [1, 5, 7, -1, 5], Sum = 6
Output: Pairs (1,5), (7,-1), (1,5)
*/

#include <stdio.h>

void findPairsWithSum(int arr[], int n, int target)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] + arr[j] == target)
            {
                printf("(%d,%d)\n", arr[i], arr[j]);
            }
        }
    }
}

int main(void)
{
    int arr[] = {1,5,7,-1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 6;
    printf("Pairs with sum %d:\n", target);
    findPairsWithSum(arr, n, target);
    return 0;
}
