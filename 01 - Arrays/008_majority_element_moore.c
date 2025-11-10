/*
8. Find the majority element (element that appears more than n/2 times)
Use Moore’s Voting Algorithm to identify the majority element if it exists.

Example: Input: [2, 2, 1, 1, 2, 2, 2]
Output: 2
*/

#include <stdio.h>

int majorityElement(int arr[], int n)
{
    int candidate = -1;
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        if (count == 0)
        {
            candidate = arr[i];
            count = 1;
        }
        else 
        {
            count += (arr[i] == candidate) ? 1 : -1;
        }
    }

    return candidate;
}

int main(void)
{
    int arr[] = {2,2,1,1,2,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maj = majorityElement(arr, n);
    printf("Majority element = %d\n", maj);
    return 0;
}
