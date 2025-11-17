/*
3. Check if two strings are anagrams without using built-in sort
Determine if two strings contain the exact same characters in any order, without sorting them.

Example: Input: "listen", "silent"
Output: true
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool areAnagrams(char str1[], char str2[])
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if (len1 != len2) 
    {
        return false;
    }
    
    int freq[256] = {0};
    
    for (int i = 0; i < len1; i++) 
    {
        freq[str1[i]]++;
    }
    
    for (int i = 0; i < len2; i++) 
    {
        freq[str2[i]]--;
    }
    
    for (int i = 0; i < 256; i++) 
    {
        if (freq[i] != 0) 
        {
            return false;
        }
    }
    
    return true;
}

int main(void)
{
    char test1a[] = "listen";
    char test1b[] = "silent";
    
    printf("'%s' and '%s' are anagrams: %s\n", test1a, test1b, areAnagrams(test1a, test1b) ? "true" : "false");
    
    return 0;
}