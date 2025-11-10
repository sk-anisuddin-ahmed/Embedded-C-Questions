/*
8. Find the lexicographic rank of a string using DFS
Use Depth-First Search to generate all permutations and find the rank of target string.

Example: Input: "string"
Output: 598
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void dfsPermute(char str[], int start, int n, char target[])
{
    
}

int main(void)
{
    char test[] = "cab";
    
    printf("Lexicographic rank of '%s': %lld\n", test, findRank(test));
    
    return 0;
}