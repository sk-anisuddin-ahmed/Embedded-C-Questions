## 1. What happens when a C function returns a local array? Why?

**Answer:** It causes undefined behavior - this results in garbage values or crashes.
**Reason:** Local arrays live on the stack and get destroyed when the function ends. This returns a pointer to deleted memory.
**Example:**
```c
int* bad_function() 
{
    int arr[5] = {1,2,3,4,5};
    return arr;
}

int* good_function() 
{
    static int arr[5] = {1,2,3,4,5};
    return arr;
}
```

## 2. How would you pass a function as a parameter to another function in C?

**Answer:** Use function pointers - functions can be treated like variables.
**Syntax:** `return_type (*pointer_name)(parameters)`
**Example:**
```c
int add(int a, int b) 
{ 
    return a + b; 
}

int calculate(int x, int y, int (*operation)(int, int)) 
{
    return operation(x, y);
}

int result = calculate(5, 3, add);
```

## 3. What's the difference between inline and static in function declarations?

**Answer:** They do completely different things.
inline hints compiler to copy function code directly instead of calling it although it depends on compiler whether code will get replaced or not.

static hides the function from other files - only this file can use it.

## 4. Can you explain the difference between function declaration, definition, and prototype?

**Answer:**
Declaration/Prototype - `int add(int a, int b);` - tells compiler "this function exists somewhere"
Definition -The actual function with body - where code is written

## 5. What is the effect of using static inside a function? What about outside?

**Answer:** Static changes where variables life and scope.
Inside function - Variable keeps its value between function calls.
Outside function - Variable/function only accessible in current file.

## 6. What is tail-call optimization and does C support it?

**Answer:**
Definition - For recursive functions compiler can reuse the same stack space.
C Support - Some compilers do it but not guaranteed by standard.
Also, Smart compilers can turn some recursive calls into loops.

## 7. What happens if you call a function before its prototype is defined?

**Answer:** implicit declaration of function - error displays.

## 8. Write a variadic function that accepts any number of integers and returns the maximum. What issues might arise?

**Code:**
```c
#include <stdarg.h>
int find_max(int count, ...) 
{
    va_list args;
    va_start(args, count);
    int max = va_arg(args, int);
    for(int i = 1; i < count; i++) 
    {
        int current = va_arg(args, int);
        if(current > max) max = current;
    }
    va_end(args);
    return max;
}
```
**Issues:** 
- No type checking - passing wrong type produces garbage
- Arguments must be counted manually 
- Easy to crash if count is incorrect

## 9. How does the compiler handle type safety in variadic functions? Can it?

**Answer:** It doesn't. Any type can be passed and compiler won't prevent it - crashes become the programmer's responsibility.

## 10. Why are va_list, va_start, and va_arg macros required, and how do they work under the hood?

**Answer:** 
va_list- Creates a pointer to walk through arguments
va_start- Points to first variable argument  
va_arg- Gets next argument and moves pointer forward
Working - Usually pointer math - jump by argument size on stack

## 11. What are the dangers of calling a variadic function with fewer arguments than expected?

**Answer:** 
Function reads random memory thinking it's arguments.
Gets garbage values from stack/registers
Might crash reading invalid memory
Security holes - could expose sensitive data
Unpredictable behavior

## 12. Why is it a bad idea to pass floating-point numbers to variadic functions? What workaround exists?

**Answer:** 
C automatically "promotes" float to double, causing confusion.
Writing `va_arg(args, float)` causes errors - `double` must always be used.
Always use `double` in va_arg, even for float arguments.

## 13. How would you simulate anonymous functions in C (which does not support them natively)?

**Answer:** 
Nested functions
Macros that create functions
Structs containing function pointers

## 14. Log Session a function pointer array for arithmetic operations (+, -, *, /) and use it.

**Code:**
```c
int add(int a, int b) 
{ 
    return a + b; 
}

int sub(int a, int b) 
{ 
    return a - b; 
}

int mul(int a, int b) 
{ 
    return a * b; 
}

int div(int a, int b) 
{ 
    return a / b; 
}

int (*operations[])(int, int) = {add, sub, mul, div};
int result = operations[0](10, 5);
```

## 15. What are the implications of assigning a function to a pointer and calling it from different files?

**Answer:**
Function must not be static (must be visible outside file)
Need proper declarations in header files
Linker must find the function definition
Function signature must match pointer exactly

## 16. How do you declare and call a function pointer to a function returning void and accepting (int, char*) as arguments?

**Answer:** 
`void (*function_ptr)(int, char*);`
`function_ptr(42, "hello");`
**Example:**
```c
void print_info(int num, char* text) 
{
    printf("Number: %d, Text: %s\n", num, text);
}

void (*ptr)(int, char*) = print_info;
ptr(100, "world");
```

## 17. Can you dynamically switch the behavior of a C program at runtime using function pointers? How?

**Answer:** Yes - function pointers enable runtime polymorphism
**Example:**
```c
void debug_mode() 
{ 
    printf("Debug: detailed info\n"); 
}

void normal_mode() 
{ 
    printf("Info: basic info\n"); 
}

void (*logger)(void) = normal_mode;
if (user_wants_debug) 
    logger = debug_mode;
logger();
```

## 18. What's the maximum depth of recursion you can safely perform in C? How is it determined?

**Answer:** 
Stack size
Function's local variables

## 19. How would you rewrite a recursive function into an iterative one using an explicit stack?

**Answer:** Replace function call stack with a custom array/stack.
**Steps:**
1. Create a stack data structure
2. Push initial values onto stack  
3. Loop while stack not empty
4. Pop value, process it
5. Push new values if needed (instead of recursive calls)

## 20. Demonstrate mutual recursion with two or more functions. How does the compiler handle it?

**Answer:** Functions calling each other back and forth.
**Example:**
```c
int is_odd(int n);

int is_even(int n) 
{
    if (n == 0) return 1;
    return is_odd(n - 1);
}

int is_odd(int n) 
{
    if (n == 0) return 0;
    return is_even(n - 1);
}
```

## 21. What is tail recursion? Give an example and explain how a compiler might optimize it.

**Answer:** When recursive call with a jump back to start - reuses same stack space.

## 22. What problems in real-world applications are best solved using recursion (instead of loops)? Why?

**Answer:** 
- File system traversal (folders contain folders)
- Parsing code/math expressions (nested parentheses) 
- Tree/graph algorithms (binary trees, maze solving)
- Divide-and-conquer (quicksort, mergesort)
- Backtracking puzzles (N-queens, Sudoku)

## 23. Design a recursive variadic function to parse nested expressions like sum(1, sum(2, 3), 4).

**Answer:** 

## 24. Use function pointers and recursion together to build a custom command parser.

**Answer:** 

## 25. Explain how function pointers and recursion can lead to stack overflows if not handled carefully.

**Answer:** Both use stack space - combine them wrong and you eat stack fast.
**Causes:**
Recursive function calls via pointers with no base case
Deep recursion where each level calls through multiple pointers
Function pointers in recursive data structures
Circular function pointer chains
