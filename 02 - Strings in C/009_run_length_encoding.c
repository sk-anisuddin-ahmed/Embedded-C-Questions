/*
9. Implement Run-Length Encoding (RLE) for string compression
Compress a string by replacing consecutive repeated characters 
with the character followed by the count.

Example: Input: "aaabbc"
Output: "a3b2c1"
*/

#include <stdio.h>
#include <string.h>

void runLengthEncode(char str[], char result[])
{
    int n = strlen(str);
    int j = 0;
    
    for (int i = 0; i < n; i++) 
    {
        int count = 1;        
        while (i + 1 < n && str[i] == str[i + 1]) 
        {
            count++;
            i++;
        }
        
        result[j++] = str[i];
        j += sprintf(&result[j], "%d", count);
    }    
    result[j] = '\0';
}

int main(void)
{
    char test[] = "aaabbc";
    char result[100];
    
    runLengthEncode(test, result);
    printf("Input: %s, RLE: %s\n", test, result);
    
    return 0;
}