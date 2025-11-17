/*
Write a function that allocates a 2D array of integers dynamically. 
Also, write a function that frees all of the memory for this array.

*/

#include <stdio.h>
#include <stdlib.h>

int** allocate2DArray(int rows, int cols) 
{
    int** array = malloc(rows * sizeof(int*));
    if (array == NULL) return NULL;
    
    for (int i = 0; i < rows; i++) 
    {
        array[i] = malloc(cols * sizeof(int));
        if (array[i] == NULL) 
        {
            for (int j = 0; j < i; j++) 
            {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
    }
    return array;
}

void free2DArray(int** array, int rows) 
{
    if (array == NULL) return;
    
    for (int i = 0; i < rows; i++) 
    {
        free(array[i]);
    }
    free(array);
}

int main() 
{
    int rows = 3, cols = 4;
    
    int** arr = allocate2DArray(rows, cols);
    if (arr == NULL) 
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            arr[i][j] = i * cols + j;
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
    
    free2DArray(arr, rows);
    printf("2D array freed successfully\n");
    
    return 0;
}