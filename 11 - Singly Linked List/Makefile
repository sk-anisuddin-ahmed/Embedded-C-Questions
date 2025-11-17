CC = gcc
CFLAGS = -Wall -Wextra -std=c11
DBGFLAGS = -g -O0
TARGET = output

# Source files
SRCS = 008_clone_list_with_random_pointers.c list.c

.PHONY: all run clean debug run-debug

# Build executable directly (no .o files)
all: $(TARGET)

$(TARGET): $(SRCS) list.h
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Run program
run: $(TARGET)
	./$(TARGET)

# Clean up the executable
clean:
	rm -f $(TARGET)