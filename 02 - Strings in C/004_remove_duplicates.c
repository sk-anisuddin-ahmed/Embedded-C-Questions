/*
4. Remove duplicate characters from a string while preserving order
Write a function to remove repeated characters, keeping the original sequence of the first occurrence.

Example: Input: "embedded"
Output: "embd"
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void removeDuplicates(char str[])
{
    bool seen[256] = {false};
    int writeIndex = 0;
    
    for (int readIndex = 0; str[readIndex]; readIndex++) 
    {
        char currentChar = str[readIndex];
        
        if (!seen[currentChar]) 
        {
            seen[currentChar] = true;
            str[writeIndex] = currentChar;
            writeIndex++;
        }
    }
    
    str[writeIndex] = '\0';
}

int main(void)
{
    char test[] = "embedded";
    
    printf("Original: %s\n", test);
    removeDuplicates(test);
    printf("After removing duplicates: %s\n", test);
    
    return 0;
}