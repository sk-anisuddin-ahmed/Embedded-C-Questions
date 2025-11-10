/*
Problem Statement:
Implement a program that swaps two strings using pointers to pointers
*/

#include <stdio.h>
#include <string.h>

void swap_strings(char** str1, char** str2)
{
    for (int i = 0; i < strlen(*str1); i++)
    {
        char* temp = *str1;
        *str1 = *str2;
        *str2 = temp;
    }
}

int main() 
{
    char *str1 = "Hello";
    char *str2 = "World";
    printf("Before swap: str1=%s, str2=%s\n", str1, str2);
    swap_strings(&str1, &str2);
    printf("After swap: str1=%s, str2=%s\n", str1, str2);
    return 0;
}