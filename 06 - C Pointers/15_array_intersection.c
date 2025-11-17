/*
Problem Statement:
Design a function that finds the intersection of two arrays using pointers
*/

#include <stdio.h>

int* find_intersection(int* arr1, int size1, int* arr2, int size2, int* result_size)
{
    static int result[100];
    int k = 0;

    for(int i = 0; i < size1; i++) 
    {
        for(int j = 0; j < size2; j++) 
        {
            if(*(arr1 + i) == *(arr2 + j)) 
            {
                result[k++] = *(arr1 + i);
                break;
            }
        }
    }
    *result_size = k;
    return result;
}

int main() 
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {4, 5, 6, 7, 8};
    int result_size;
    int* intersection = find_intersection(arr1, 5, arr2, 5, &result_size);
    printf("Intersection: ");
    for(int i = 0; i < result_size; i++)
        printf("%d ", intersection[i]);
    return 0;
}