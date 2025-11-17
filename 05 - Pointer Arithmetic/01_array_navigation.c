/*
Problem: Find elements before and after a pointer in an array
Given a pointer to the middle of an integer array, find the number of elements
before and after this pointer without knowing array size or using indices.

Example:
Array: [10, 20, 30, 40, 50]
Middle pointer points to 30 (index 2)
Elements before: 2, Elements after: 2
*/

#include <stdio.h>

int findElementsBefore(int *middle, int *start)
{
    return middle - start;
}

int findElementsAfter(int *middle, int *end)
{
    return end - middle;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *start = arr;
    int *middle = arr + 2;
    int *end = arr + size - 1;
    
    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Middle pointer points to: %d\n", *middle);
    printf("Elements before middle: %d\n", findElementsBefore(middle, start));
    printf("Elements after middle: %d\n", findElementsAfter(middle, end));
    
    return 0;
}