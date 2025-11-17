/*
Problem Statement:
Implement a function that finds the common elements in three sorted arrays using pointers
*/

#include <stdio.h>

void find_common_elements(int* arr1, int size1, int* arr2, int size2, int* arr3, int size3)
{
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2 && k < size3) 
    {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) 
        {
            printf("%d ", arr1[i]);
            i++;
            j++;
            k++;
        } 
        else if (arr1[i] < arr2[j]) 
        {
            i++;
        } 
        else if (arr2[j] < arr3[k]) 
        {
            j++;
        } 
        else 
        {
            k++;
        }
    }
    printf("\n");
}

int main() 
{
    int arr1[] = {1, 5, 10, 20, 40, 80};
    int arr2[] = {6, 7, 20, 80, 100};
    int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    
    printf("Common elements: ");
    find_common_elements(arr1, 6, arr2, 5, arr3, 8);
    return 0;
}