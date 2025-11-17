/*
Problem Statement:
Implement a function that rotates an array to the right by k elements using pointers
*/

#include <stdio.h>

void rotate_array(int* arr, int k)
{
    int i = 0, j = k - 1;
    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++, j--;
    }
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8 ,9 ,10};
    int size = 10, k = 2;

    rotate_array(arr, size);
    rotate_array(arr, k);
    rotate_array(arr + k, size - k);

    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}