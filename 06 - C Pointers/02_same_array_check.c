/*
Problem Statement:
Design a function that determines if two pointers point to the same array
*/

#include <stdio.h>

int is_same_array(int* ptr1, int* ptr2, size_t size)
{
   if (ptr1 < ptr2)
   {
        for (size_t i = 0; i < size; i++)
        {
            ptr1++;
            if (ptr1 == ptr2) return 1;
        }
   }
   else
   {
        for (size_t i = 0; i < size; i++)
        {
            ptr2++;
            if (ptr1 == ptr2) return 1;
        }
   }
   return 0;
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5};
    int* p1 = &arr[1];
    int* p2 = &arr[3];
    printf("Pointing to same array? %s\n", is_same_array(p1, p2, 5) ? "Yes" : "No");
    return 0;
}