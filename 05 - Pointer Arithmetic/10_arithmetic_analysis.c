/*
Problem: Analyze pointer arithmetic output
Given: char arr[] = "abcdef"; char *p = arr + 3; printf("%c", *(p - 1));
Explain the output and what causes undefined behavior.

Example:
Array: "abcdef" -> ['a','b','c','d','e','f','\0']
p points to arr[3] which is 'd'
*(p - 1) accesses arr[2] which is 'c'
Output: 'c'
*/

#include <stdio.h>

void analyzePointerArithmetic()
{
    char arr[] = "abcdef";
    char *p = arr + 3;
    
    printf("Array contents: %s\n", arr);
    printf("Array indices:  0123456\n");
    
    printf("p = arr + 3, so p points to: arr[3] = '%c'\n", *p);
    printf("*(p - 1) accesses: arr[2] = '%c'\n", *(p - 1));
    
    printf("\nStep by step:\n");
    printf("arr[0] = '%c'\n", arr[0]);
    printf("arr[1] = '%c'\n", arr[1]);
    printf("arr[2] = '%c'\n", arr[2]);
    printf("arr[3] = '%c' <- p points here\n", arr[3]);
    printf("arr[4] = '%c'\n", arr[4]);
    printf("arr[5] = '%c'\n", arr[5]);
    printf("arr[6] = '\\0'\n");
    
    printf("\nWhat would cause undefined behavior:\n");
    printf("1. Accessing before array start: *(arr - 1)\n");
    printf("2. Accessing beyond array end: *(arr + 10)\n");
    printf("3. Dereferencing null pointer: *((char*)0)\n");
}

int main()
{
    analyzePointerArithmetic();
    
    return 0;
}