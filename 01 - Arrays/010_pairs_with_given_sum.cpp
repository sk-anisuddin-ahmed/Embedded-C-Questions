/*
10. Find all pairs in the array whose sum is equal to a given number
Given an array and a number, find all pairs whose sum equals the given number. Optimize for time complexity using hash map.

Example: Input: [1, 5, 7, -1, 5], Sum = 6
Output: Pairs (1,5), (7,-1), (1,5)
*/

#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
    int arr[] = {1, 5, 7, -1, 5}, sum = 6;
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    std::unordered_map<int, int> freq;

    for (int i = 0; i < arrLen; i++)
    {
        freq[arr[i]]++;
    }
    std::vector<std::pair<int, int>> output;

    for (auto &val: arr)
    {
        int temp = sum - val;

        if (freq.find(temp) != freq.end()) 
        {
            output.push_back({val, temp});
        }
    }

    for (auto &out: output)
    {
        std::cout << "(" << out.first << ", " << out.second << ")";
        std::cout << "\t";
    }

    return 0;
}