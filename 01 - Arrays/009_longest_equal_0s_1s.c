/*
9. Find the longest subarray with equal number of 0s and 1s
Transform the problem using 0 -> -1 and use hashmap to 
find the longest subarray with zero sum.

Example: Input: [0, 1, 0, 1, 1, 1, 0]
Output: Length = 4
*/

#include <stdio.h>

int longestEqual01(int arr[], int n)
{
    int maxLen = 0;
    for (int i = 0; i < n; ++i) 
    {
        int zeros = 0, ones = 0;
        for (int j = i; j < n; ++j) 
        {
            arr[j] == 0 ? ++zeros : ++ones;
            if (zeros == ones) 
            {
                int len = j - i + 1;
                maxLen = (len > maxLen) ? len : maxLen;
            }
        }
    }
    return maxLen;
}

int main(void)
{
    int arr[] = {0,1,1,1,1,1,0,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int len = longestEqual01(arr, n);
    printf("Longest equal 0/1 length = %d\n", len);
    return 0;
}
