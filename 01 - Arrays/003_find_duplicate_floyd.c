/*
3. Find the duplicate number in an array of n+1 integers (each from 1 to n)
Use Floyd’s Cycle Detection or other space-efficient methods to detect a repeated number in the array without modifying the input.

Example: Input: [3, 1, 3, 4, 2]
Output: 3
*/

#include <stdio.h>

int findDuplicate(int arr[], int size)
{
    int slow = arr[0];
    int fast = arr[0];

    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = arr[0];
    while (slow != fast) 
    {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main(void)
{
    int arr[] = {3, 1, 3, 4, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int dup = findDuplicate(arr, size);
    printf("Duplicate = %d\n", dup);
    return 0;
}
