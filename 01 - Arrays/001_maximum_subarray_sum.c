/*
1. Find the subarray with the maximum sum (Kadane’s Algorithm)
Implement an efficient algorithm to find the contiguous subarray within a one-dimensional array of numbers that has the largest sum.

Example: Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6 (subarray: [4, -1, 2, 1])
*/

#include <stdio.h>

int findMax(int num1, int num2) 
{
    return (num1 > num2) ? num1 : num2;
}

int maxSubarraySum(int arr[], int n)
{
    int currMax = arr[0], maxSoFar = currMax;
    for (int i = 1; i < n; i++)
    {
        currMax = findMax(arr[i], currMax + arr[i]);
        maxSoFar = findMax(maxSoFar, currMax);
    }
    return maxSoFar;
}

int main(void)
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = maxSubarraySum(arr, n);
    printf("Max subarray sum = %d\n", result);
    return 0;
}
