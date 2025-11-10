/*
Problem: Reverse each string in a string array using double pointer
Given a double pointer char **ptr, use pointer arithmetic to access
individual characters and reverse each string in-place.

Example:
Input: {"hello", "world", "test"}
Output: {"olleh", "dlrow", "tset"}
*/

#include <stdio.h>

void reverseStringsInPlace(char **ptr, int count)
{
    for (int i = 0; i < count; i++)
    {
        char *start = *(ptr + i);
        char *end = *(ptr + i);
        char temp;
        
        while (*end != '\0')
        {
            end++;
        }
        end--;
        
        while (start < end)
        {
            temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end--;
        }        
    }
}

int main()
{
    char str1[] = "hello";
    char str2[] = "world";
    char str3[] = "test";
    char *strings[] = {str1, str2, str3};
    int count = sizeof(strings) / sizeof(strings[0]);
    
    printf("Original strings: ");
    for (int i = 0; i < count; i++)
    {
        printf("%s ", strings[i]);
    }
    printf("\n");
    
    reverseStringsInPlace(strings, count);
    
    printf("Reversed strings: ");
    for (int i = 0; i < count; i++)
    {
        printf("%s ", strings[i]);
    }
    printf("\n");
    
    return 0;
}