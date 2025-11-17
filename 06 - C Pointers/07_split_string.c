/*
Problem Statement:
Implement a function that splits a string into two halves and returns pointers to the beginning of each half
*/

#include <stdio.h>
#include <string.h>

void split_string(char* str, char** first_half, char** second_half)
{
    int len2 = strlen(str) / 2;
    *first_half = str;
    *(str + len2) = '\0';
    *second_half = str + len2 + 1;
}

int main() 
{
    char str[] = "Hello World";
    char *first, *second;
    split_string(str, &first, &second);
    printf("First half: %s\nSecond half: %s\n", first, second);
    return 0;
}