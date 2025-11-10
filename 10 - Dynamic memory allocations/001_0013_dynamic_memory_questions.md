## 1. Your program keeps using more memory as it runs, even though you use malloc and free. How would you find out what is wrong and fix it?

**Answer**
- Identify
- Losing pointers to allocated memory
- Not completely freeing only part of complex data structures

- Resolution
- Pair every `malloc()` with exactly one `free()`
- Set pointers to `NULL` after freeing
- Implement cleanup functions for complex structures

## 2. What happens if you call free on the same pointer twice? How can you avoid this problem in your code?

**Answer**
program may crash immediately
memory access violation

**Prevention Strategies:**
- Set pointer to `NULL` after `free()`
- Before using `free()` check for `NULL`

## 3. Give an example of a bug that happens when you use memory after you have freed it. How can you prevent such bugs?

**Answer**
```c
char* ptr = malloc(5);
free(ptr);
printf("%s", ptr);
```
- Set pointers to `NULL` after freeing

## 4. You want to make a memory block bigger using realloc. How can you do this safely, so you don't lose your data if realloc fails?

**Answer**
```c
void* temp = realloc(ptr, new_size);
if (temp != NULL && new_size > 0) 
{
    ptr = temp;
}
```

## 5. What is heap fragmentation? How can it become a problem in programs that run for a long time?

**Answer**
- Free memory exists but not in contiguous blocks
- Allocated blocks are larger than requested

## 6. What happens if you write outside the bounds of a dynamically allocated array? Why is this dangerous?

**Answer**
- Writing past array bounds corrupts adjacent memory
- Can overwrite control structures, other variables
- Security vulnerability
- Undefined behavior, crashes

## 7. You have a structure that ends with an array whose size is not fixed. How would you allocate and use this structure in C?

**Structure with variable-length array:**
```c
typedef struct {
    int count;
    char data[];
} var;

var* s = malloc(sizeof(var) + data_size);
```

## 8. What is the difference between malloc and calloc? When should you use one over the other?

**Answer**
- malloc()
- Allocates uninitialized memory
- Faster (no initialization overhead)
- Memory contains garbage values

- calloc()
- Allocates zero-initialized memory
- Slightly slower due to initialization
- Takes element count and size parameters
- Checks for overflow in size calculation

- Use malloc when you'll immediately initialize the memory
- Use calloc() when you need zero-initialized memory or want overflow protection

## 9. Why is it safe to use free(NULL) in C? Why was it designed this way?

**Answer**
- C standard explicitly allows `free(NULL)`
- Eliminates need for NULL checks before freeing
- Simplifies error handling paths
- Makes generic cleanup functions easier to write

## 10. If you forget to free allocated memory before your program ends, what happens? Does it matter if you are on a desktop or an embedded device?

**Answer**
- Leaks don't affect system after program ends. Still bad practice

## 11. When you use realloc, how does it work? What happens if there isn't enough space to grow the block where it is?

**Answer**
- Tries to extend current block in place
- If impossible, allocates new larger block
- Copies old data to new location
- Frees old block
- Returns pointer to new block

## 12. How can you find memory leaks in a big C program? What tools or methods can you use?

**Answer**
- Valgrind - Industry standard (Linux/Mac)
- Dr. Memory - Windows equivalent of Valgrind
- AddressSanitizer - Compiler-based, very fast

## 13. What problems can happen if you access memory that is not aligned correctly, especially with dynamically allocated memory?

**Answer**
- Structure packing affects alignment requirements
- Need to use pointer arithmetic carefully
- Depends on target platform's alignment requirements