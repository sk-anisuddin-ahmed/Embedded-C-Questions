/*
Problem: Access 2D matrix using single loop and pointer arithmetic
Given a dynamically allocated 2D matrix (as int **), access and
manipulate elements using only a single loop and pointer arithmetic.

Example:
Matrix: [[1,2,3], [4,5,6], [7,8,9]]
Access all elements in single loop using base pointer + offset
*/

#include <stdio.h>
#include <stdlib.h>

void access2DMatrixSingleLoop(int **matrix, int rows, int cols)
{
    int *basePtr = matrix[0];
    int totalElements = rows * cols;
    
    for (int i = 0; i < totalElements; i++)
    {
        printf("%d ", *(basePtr + i));
        if ((i + 1) % cols == 0)
        {
            printf("\n");
        }
    }
}

int main()
{
    int rows = 3;
    int cols = 4;
    
    int *data = malloc(rows * cols * sizeof(int));
    
    for (int i = 0; i < rows * cols; i++)
    {
        data[i] = i + 1;
    }
    
    access2DMatrixSingleLoop(&data, rows, cols);
    
    free(data);
    
    return 0;
}