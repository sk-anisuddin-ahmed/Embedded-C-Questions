/*
2. Find the first non-repeating character in a given string
Identify the first character that does not repeat anywhere else in the string, optimizing for time and space complexity.

Example: Input: "swiss"
Output: 'w'
*/

#include <stdio.h>
#include <string.h>

char findFirstNonRepeating(char str[])
{
    int freq[256] = {0};
    int n = strlen(str);
    
    for (int i = 0; i < n; i++) 
    {
        freq[str[i]]++;
    }
    
    for (int i = 0; i < n; i++) 
    {
        if (freq[str[i]] == 1) 
        {
            return str[i];
        }
    }
    
    return '\0';
}

int main(void)
{
    char test[] = "swiss";
    
    char result = findFirstNonRepeating(test);
    printf("Input: %s, First non-repeating: %c\n", test, result);
    return 0;
}