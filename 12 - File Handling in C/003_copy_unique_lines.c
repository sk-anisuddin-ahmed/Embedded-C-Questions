/*
Write a function that copies only the unique lines from a source text file to a destination file, 
preserving order. 
For example, if a line appears more than once, only its first occurrence is copied.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

_Bool read_lines_compare(FILE * file, char* cmpStr)
{
    rewind(file);
    _Bool found = 0;
    size_t size = 1;
    char* lines = malloc(size);
    char ch = '\0';
    int len = 0;
    
    while ((ch = fgetc(file)) != EOF) 
    {
        if (len >= size)
        {
            size++;
            lines = realloc(lines, size);
        }
        lines[len++] = (char)ch;

        if (ch == '\n')
        {
            lines[len] = '\0';
            if (!strcmp(lines, cmpStr))
            {
                found = 1;
                break;
            }
            len = 0;
        }
    }
    free(lines);
    return found;
}

void copy_unique_lines (const char *src_filename, const char *dest_filename)
{
    FILE *src_file = fopen(src_filename, "r");
    FILE *dest_file = fopen(dest_filename, "w+");
    
    if (!src_file || !dest_file) 
    {
        if (src_file) fclose(src_file);
        if (dest_file) fclose(dest_file);
        return;
    }

    char ch = '\0';
    char *line = malloc(1);
    size_t line_size = 1;
    size_t line_len = 0;

    while ((ch = fgetc(src_file)) != EOF) 
    {
        if (line_len >= line_size) 
        {
            line_size++;
            line = realloc(line, line_size);
        }
        line[line_len++] = ch;

        if (ch == '\n') 
        {
            line[line_len] = '\0';
            line_len = 0;
            if (!read_lines_compare(dest_file, line)) 
            {
                fseek(dest_file, 0, SEEK_END);
                fputs(line, dest_file);
            }
        }
    }
    free(line);
    fclose(src_file);
    fclose(dest_file);
}

int main() 
{
    copy_unique_lines("input.txt", "output.txt");
    
    return 0;
}