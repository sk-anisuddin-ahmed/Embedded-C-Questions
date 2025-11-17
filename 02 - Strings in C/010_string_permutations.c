/*
10. Print all permutations of a string in lexicographic order
Generate and print every permutation of the given string sorted alphabetically.

Example: Input: "abc"
Output: "abc", "acb", "bac", "bca", "cab", "cba"
*/

#include <stdio.h>
#include <string.h>

void strPermute(char str[], int start, int n)
{
    
}

int main(void)
{
    char test[] = "abc";
    char copy[10];
    strcpy(copy, test);
    
    printf("All permutations of '%s': ", test);
    strPermute(copy, 0, strlen(copy));
    printf("\n");
    
    return 0;
}