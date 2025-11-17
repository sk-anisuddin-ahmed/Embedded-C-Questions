/*
7. Check if one string is a rotation of another
Verify if one string can be obtained by rotating another string. 
Use string concatenation and substring search.

Example: Input: "abcd", "cdab"
Output: true
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool isRotation(char str1[], char str2[])
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if (len1 != len2) return false;    
    if (len1 == 0)  return true;
    
    char* concat = (char*)malloc((len1 * 2 + 1) * sizeof(char));
    strcpy(concat, str1);
    strcat(concat, str1);
    bool result = (strstr(concat, str2) != NULL);    
    free(concat);
    return result;
}

int main(void)
{
    char str1[] = "abcd";
    char str2[] = "cdab";
    
    printf("'%s' is rotation of '%s': %s\n", str2, str1, isRotation(str1, str2) ? "true" : "false");
    
    return 0;
}