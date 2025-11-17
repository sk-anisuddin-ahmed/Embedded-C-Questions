/*
Problem Statement:
Count the number of elements in an array using pointer arithmetic, without utilizing loop constructs
*/

#include <stdio.h>

size_t count_elements(int* start, int* end)
{
    return (size_t)((int)((char*)end - (char*)start) / sizeof(*start));
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5};
    int* end = arr + 5;
    printf("Number of elements: %zu\n", count_elements(arr, end));
    return 0;
}