/*
Write a C function that allocates and frees an array of integers. 
First, make a version that causes a memory leak. Then, fix the leak.

*/

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    /*Memory Leak*/
    int* arr1 = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) 
    {
        arr1[i] = i * i;
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    /*Fixed Version*/
    int* arr2 = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) 
    {
        arr2[i] = i * i;
        printf("%d ", arr2[i]);
    }
    printf("\n");
    free(arr2); 
    
    return 0;
}