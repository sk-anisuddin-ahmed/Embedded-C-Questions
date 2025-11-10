/*
Problem Statement:
Implement a program that checks if a string is a palindrome using pointers
*/

#include <stdio.h>
#include <string.h>

int is_palindrome(const char* str)
{
    const char* start = str;
    const char* end = str;

    end = end + strlen(str) - 1;

    while (start < end) 
    {
        if (*start != *end) 
        {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main() 
{
    char str[] = "racecar";
    printf("Is '%s' a palindrome? %s\n", str, is_palindrome(str) ? "Yes" : "No");
    return 0;
}