/*
9. Find the longest subarray with equal number of 0s and 1s
Transform the problem using 0 -> -1 and use hashmap to 
find the longest subarray with zero sum.

Example: Input: [0, 1, 0, 1, 1, 1, 0]
Output: Length = 4
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int findMaxLength(int nums[], int n)
{
    unordered_map<int,int> first; 
    first[0] = -1;
    int sum = 0, maxSoFar = 0;
    for (int i = 0; i < n; ++i) 
    {
        sum += (nums[i] == 1 ? 1 : -1);
        if (first.find(sum) != first.end())
        {
            int len = i - first[sum];
            if (len > maxSoFar) maxSoFar = len;
        } 
        else 
        {
            first[sum] = i;
        }
    }
    return maxSoFar;
}

int main()
{
    int arr[] = {0, 1, 0, 1, 1, 1, 0};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    cout << "Longest equal 0/1 length = " << findMaxLength(arr, n) << "\n";
    return 0;
}
