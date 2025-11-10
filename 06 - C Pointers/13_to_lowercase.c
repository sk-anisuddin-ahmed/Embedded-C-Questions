/*
Problem Statement:
Write a function that converts a string to lowercase using pointers
*/

#include <stdio.h>

void to_lowercase(char* str)
{
    while (*str) 
    {
        if (*str >= 'A' && *str <= 'Z') 
        {
            *str = *str + ('a' - 'A');
        }
        str++;
    }
}

int main() 
{
    char str[] = "HeLLo WoRLD";
    printf("Before: %s\n", str);
    to_lowercase(str);
    printf("After: %s\n", str);
    return 0;
}