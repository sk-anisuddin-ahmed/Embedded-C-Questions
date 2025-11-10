/*
Problem Statement:
Implement a function that merges two sorted arrays into a third array using pointers
*/

#include <stdio.h>

void merge_sorted_arrays(int* arr1, int size1, int* arr2, int size2, int* result)
{
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
            result[k++] = arr1[i++];
        else
            result[k++] = arr2[j++];
    }
    while (i < size1)
        result[k++] = arr1[i++];
    while (j < size2)
        result[k++] = arr2[j++];
}

int main() 
{
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    int result[6];
    merge_sorted_arrays(arr1, 3, arr2, 3, result);
    printf("Merged array: ");
    for(int i = 0; i < 6; i++)
        printf("%d ", result[i]);
    return 0;
}