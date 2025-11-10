/*
6. Implement pattern matching using the KMP algorithm
Explain and implement the Knuth-Morris-Pratt algorithm for substring search, 
focusing on preprocessing the pattern to avoid redundant comparisons.

Example: Pattern: "abc"
Text: "ababcabcab"
Output: Pattern found at indices 2, 5
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

_Bool kmpSearch(char text[], char pattern[])
{
    
}

int main(void)
{
    char text[] = "ababcabcab";
    char pattern[] = "abc";
    
    printf("Patter Matched: %s\n", kmpSearch(text, pattern) ? "true" : "false");    
    
    return 0;
}