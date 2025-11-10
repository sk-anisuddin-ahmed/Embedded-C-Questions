/*
Problem Statement:
Implement a function that segregates even and odd values of an integer array using pointers
*/

#include <stdio.h>

void segregate_even_odd(int* arr, int size)
{
    int start = 0, end = size - 1;
    while (start < end)
    {
        if (arr[start] % 2)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            end--;
        }
        else
        {
            start++;
        }
    }
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    segregate_even_odd(arr, size);
    printf("Segregated array: ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}