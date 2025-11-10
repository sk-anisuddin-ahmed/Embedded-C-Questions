/*
6. Find the first missing positive integer in an unsorted array
Write an efficient algorithm to find the smallest missing positive integer 
from an unsorted array (in O(n) time and constant space).

Example: Input: [3, 4, -1, 1]
Output: 2
*/

#include <stdio.h>
#include <stdlib.h>

int firstMissingPositive(int arr[], int n)
{
    for (int i = 0; i < n; ++i) 
    {
        if (arr[i] < 0) 
            arr[i] = 0;
    }    

    for (int i = 0; i < n; ++i) 
    {
        int val = abs(arr[i]);
        if (val >= 1 && val <= n) 
        {
            int pos = val - 1;
            if (arr[pos] > 0) 
                arr[pos] = -arr[pos];
            else if (arr[pos] == 0) 
                arr[pos] = -(n + 1);
        }
    }
    
    for (int i = 1; i <= n; ++i)
    {
        if (arr[i - 1] >= 0) 
            return i;
    }
    return n + 1;
}   

int main(void)
{
    int arr[] = {2,3,4,-1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int missing = firstMissingPositive(arr, n);
    printf("First missing positive = %d\n", missing);
    return 0;
}
