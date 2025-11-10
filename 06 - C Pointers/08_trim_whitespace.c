/*
Problem Statement:
Write a function that trims leading and trailing whitespace from a string using pointers
*/

#include <stdio.h>
#include <string.h>

char* trim_whitespace(char* str)
{
    int len = strlen(str) - 1;
    while(*(str + len) == ' ')
        len--;
    *(str + len + 1) = '\0';
    while(*str == ' ')
        str++;
    return str;
}

int main() 
{
    char str[] = "   Hello World   ";
    printf("Before trim: '%s'\n", str);
    char* result = trim_whitespace(str);
    printf("After trim: '%s'\n", result);
    return 0;
}