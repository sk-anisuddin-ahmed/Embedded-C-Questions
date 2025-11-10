/*
Problem: Print string from beginning using pointer to random position
Given a character array containing a string and pointer to random position,
print the string from beginning using only pointer arithmetic.

Example:
String: "Hello World"
Random pointer points to 'W' (index 6)
Output: "Hello World"
*/

#include <stdio.h>

void printStringFromBeginning(char *randomPos)
{
    char *start = randomPos;
    
    while (start > 0 && *(start - 1) != '\0')
    {
        start--;
    }
    
    while (*start != '\0')
    {
        printf("%c", *start);
        start++;
    }
    printf("\n");
}

int main()
{
    char str[] = "Hello World";
    char *randomPos = str + 6;
    
    printf("Original string: %s\n", str);
    printf("Random pointer points to: '%c' at position %ld\n", *randomPos, randomPos - str);
    printf("String from beginning: ");
    printStringFromBeginning(randomPos);
    
    return 0;
}