/*
Problem Statement:
Write a function to calculate the dot product of two vectors using pointers
*/

#include <stdio.h>

int dot_product(const int* vec1, const int* vec2, int size)
{
    int result = 0;
    for (int i = 0; i < size; i++) 
    {
        result += (*(vec1 + i)) * (*(vec2 + i));
    }
    return result;
}

int main() 
{
    int vec1[] = {1, 2, 3};
    int vec2[] = {4, 5, 6};
    printf("Dot product: %d\n", dot_product(vec1, vec2, 3));
    return 0;
}