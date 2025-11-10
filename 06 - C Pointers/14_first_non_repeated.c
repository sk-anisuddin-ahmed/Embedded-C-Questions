/*
Problem Statement:
Implement a program that finds the first non-repeated character in a string using pointers
*/

#include <stdio.h>

char find_first_non_repeated(const char* str)
{
    int count[256] = {0};
    const char* ptr = str;

    while (*ptr) 
    {
        count[(unsigned char)(*ptr)]++;
        ptr++;
    }

    ptr = str;
    while (*ptr)
     {
        if (count[(unsigned char)(*ptr)] == 1) 
        {
            return *ptr;
        }
        ptr++;
    }

    return '\0';
}

int main() 
{
    char str[] = "aabbccd";
    char result = find_first_non_repeated(str);
    printf("First non-repeated character in '%s': %c\n", str, result);
    return 0;
}