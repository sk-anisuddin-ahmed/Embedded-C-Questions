/*
5. Find the longest substring without repeating characters
Find the length or substring which has all unique characters 
without any repetition.

Example: Input: "abcabcbb"
Output: "abc"
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void longestUniqueSubstring(char str[], char result[])
{
    int n = strlen(str);
    if (n == 0) 
    {
        result[0] = '\0';
        return;
    }
    
    int start = 0;
    int maxLength = 0;
    int index = 0;
    bool charSet[256] = {false};
    
    for (int end = 0; end < n; end++) 
    {
        while (charSet[str[end]]) 
        {
            charSet[str[start]] = false;
            start++;
        }
        
        charSet[str[end]] = true;
        
        int len = end - start + 1;
        if (len > maxLength) 
        {
            maxLength = len;
            index = start;
        }
    }

    strncpy(result, str + index, maxLength);
    result[maxLength] = '\0';
}

int main(void)
{
    char test[] = "abcabcbb";
    char result[100];
    
    longestUniqueSubstring(test, result);
    printf("Input: %s, Longest unique substring: %s\n", test, result);
    
    return 0;
}