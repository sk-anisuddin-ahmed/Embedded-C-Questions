/*
Problem: Void pointer arithmetic and workaround
What happens when you increment void* pointer using ptr++?
Why is it disallowed and how to work around using char*.

Example:
void *ptr = array;
ptr++; // Error: increment of void pointer
*/

#include <stdio.h>

int main()
{
    /* 
    Void pointer arithmetic is disallowed because compiler doesn't know 
    the size of pointed object for increment
    */

    int numbers[] = {100, 200, 300, 400};
    void *voidPtr = numbers;
    char *charPtr = (char *)voidPtr;
    int *intPtr = (int *)voidPtr;
    
    printf("Original void pointer: %p\n", voidPtr);
    printf("Value at void pointer (cast to int*): %d\n", *(int *)voidPtr);
    
    charPtr += sizeof(int);
    printf("After char pointer increment by sizeof(int): %p\n", (void *)charPtr);
    printf("Value: %d\n", *(int *)charPtr);
    
    intPtr++;
    printf("After int pointer increment: %p\n", (void *)intPtr);
    printf("Value: %d\n", *intPtr);
    
    return 0;
}