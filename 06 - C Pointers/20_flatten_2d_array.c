/*
Problem Statement:
Implement a program that flattens a 2D array into a 1D array using pointers
*/

#include <stdio.h>

void flatten_array(int (*arr2d)[3], int rows, int cols, int* result)
{
    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++) 
        {
            *(result + (i * cols + j)) = *(*(arr2d + i) + j);
        }
    }
}

int main() 
{
    int arr2d[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int result[6];
    
    flatten_array(arr2d, 2, 3, result);
    printf("Flattened array: ");
    for(int i = 0; i < 6; i++)
        printf("%d ", result[i]);
    return 0;
}