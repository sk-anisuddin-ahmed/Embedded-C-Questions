/*
Problem Statement:
Design a program to find the overlapping part of two arrays using pointers
*/

#include <stdio.h>

int* find_overlap(int* arr1, int size1, int* arr2, int size2, int* overlap_size)
{
    static int result[100];
    int* ptr_result = result;
    *overlap_size = 0;
    
    for(int* ptr1 = arr1; ptr1 < arr1 + size1; ptr1++) 
    {
        for(int* ptr2 = arr2; ptr2 < arr2 + size2; ptr2++) 
        {
            if(*ptr1 == *ptr2) 
            {
                *ptr_result = *ptr1;
                ptr_result++;
                (*overlap_size)++;
                break;
            }
        }
    }
    return result;
}

int main() 
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {4, 5, 6, 7, 8};
    int overlap_size;
    int* result = find_overlap(arr1, 5, arr2, 5, &overlap_size);
    printf("Overlapping elements: ");
    for(int i = 0; i < overlap_size; i++)
        printf("%d ", result[i]);
    return 0;
}