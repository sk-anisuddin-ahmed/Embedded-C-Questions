/*
How would you safely read a large file line-by-line in C, 
ensuring you never overflow your buffer, even if a line is extremely long? 
Describe your approach and key functions you’d use.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_lines(char* filename)
{
    FILE* file = fopen(filename, "r");
    if (!file) 
    {
        printf("Error opening file\n");
        return;
    }
    char *buffer = malloc(1);
    char ch = '\0';
    int len = 0;
    size_t size = 1;
    while ((ch = fgetc(file)) != EOF) 
    {
        if (len > size)
        {
            size++;
            buffer = realloc(buffer, size);
        }
        buffer[len++] = (char)ch;

        if (ch == '\n')
        {
            buffer[len] = '\0';
            printf("%s", buffer);
            len = 0;
        }
    }
    free(buffer);
    fclose(file);
}

int main() 
{
    char* test_file = "file.txt";    
    read_lines(test_file);
    return 0;
}