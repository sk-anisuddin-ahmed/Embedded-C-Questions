/*
Problem 4: Describe how you would implement a log file that never grows beyond a certain size (for example, 1 MB). 
What would you do when the file exceeds the limit?

Approach
- Treat file as circular buffer, overwrite oldest entries
- Rewrite oldest lines when limit exceeded
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1024  // 1 KB

typedef struct 
{
    char *filename;
    long size;
    long max_size;
    FILE* file;
} FileLogger;

_Bool file_logger(FileLogger* logger, char* write_line)
{
    logger->file = fopen(logger->filename, "r+");
    if (logger->file == NULL)
    {
        logger->file = fopen(logger->filename, "w+");
        if (logger->file == NULL) return 0;
    }
    fseek(logger->file, logger->size, SEEK_SET);
    fputs(write_line, logger->file);
    logger->size += (strlen(write_line) + strlen("\r\n"));
    logger->size %= logger->max_size;
    printf("size: %ld\n", logger->size);
    fclose(logger->file);
    return true;
}

int main() 
{
    FileLogger logger;
    logger.filename = "app.log";
    logger.max_size = MAX_FILE_SIZE;
    logger.size = 0;

    for (int i = 0; i < MAX_FILE_SIZE; i++)
    {
        file_logger(&logger, "c\n");
    }
    return 0;
}