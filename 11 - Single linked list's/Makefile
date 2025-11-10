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

# Debug build: include debug symbols and disable optimizations
debug: $(SRCS) list.h
	$(CC) $(CFLAGS) $(DBGFLAGS) $(SRCS) -o debug

# Run debug binary
run-debug: debug
	./debug

# Run program
run: $(TARGET)
	./$(TARGET)

# Clean up the executable
clean:
	rm -f $(TARGET)