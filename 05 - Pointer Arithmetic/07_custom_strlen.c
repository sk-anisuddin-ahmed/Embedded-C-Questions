/*
Problem: Implement custom strlen using only pointer arithmetic
Create your own version of strlen() using only pointer arithmetic
and no index or library functions.

Example:
Input: "Hello"
Output: 5
*/

#include <stdio.h>

int customStrlen(char *str)
{
    char *start = str;
    
    while (*str != '\0')
    {
        str++;
    }
    
    return str - start;
}

int main()
{
    char testStrings[][20] = {
        "Hello",
        "World",
        "C Programming",
        "Pointer Arithmetic",
        ""
    };
    
    int count = sizeof(testStrings) / sizeof(testStrings[0]);
    
    for (int i = 0; i < count; i++)
    {
        int length = customStrlen(testStrings[i]);
        printf("String: \"%s\" -> Length: %d\n", testStrings[i], length);
    }
    
    return 0;
}