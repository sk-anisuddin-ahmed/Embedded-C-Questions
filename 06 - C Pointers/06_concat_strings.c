/*
Problem Statement:
Design a program to concatenate two strings without using standard library functions, only pointers
*/

#include <stdio.h>
#include <string.h>

void concat_strings(char* dest, const char* src)
{
    int str1Len = strlen(dest);
    int str2Len = strlen(src);
    int i = 0;
    
    while(i < str2Len)
    {
        dest[str1Len++] = src[i++];
    }
    dest[str1Len] = '\0';
}

int main() 
{
    char str1[15] = "Hello ";
    char str2[] = "World";
    concat_strings(str1, str2);
    printf("Concatenated string: %s\n", str1);
    return 0;
}