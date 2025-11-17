/*
Problem Statement:
Design a program that checks if a string is a prefix of another string using pointers
*/

#include <stdio.h>

int is_prefix(const char* prefix, const char* str)
{
    
}

int main() 
{
    char *str = "HelloWorld";
    char *prefix = "Hello";
    printf("Is '%s' a prefix of '%s'? %s\n", prefix, str, is_prefix(prefix, str) ? "Yes" : "No");
    return 0;
}