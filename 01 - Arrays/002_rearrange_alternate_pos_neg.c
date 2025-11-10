/*
2. Rearrange array elements so that positive and negative numbers are placed alternatively
Without changing the relative order of positive and negative numbers, rearrange them alternately. Extra space should be avoided if possible.

Example: Input: [1, 2, -3, -1, -2, 3]
Output: [1, -3, 2, -1, 3, -2]
*/

#include <stdio.h>
#include <stdlib.h>

void rearrangeAlternate(int arr[], int len)
{
    int* arrPos = calloc(len, sizeof(int));
    int* arrNeg = calloc(len, sizeof(int));
    int p = 0, n = 0;

    for (int i = 0; i < len; i++)
    {
        if (arr[i] < 0)
        {
            arrNeg[n++] = arr[i];
        }
        else
        {
            arrPos[p++] = arr[i];
        }
    }
    int P = 0, N = 0;
    for (int i = 0; i < len; i++)
    {
        if (P < p) arr[i++] = arrPos[P++];
        if (N < n) arr[i] = arrNeg[N++];
    }
}

void printArray(const int arr[], int n)
{
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    int arr[] = {1, 2, -3, -1, -2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Before: ");
    printArray(arr, n);
    rearrangeAlternate(arr, n);
    printf("After:  ");
    printArray(arr, n);
    return 0;
}
