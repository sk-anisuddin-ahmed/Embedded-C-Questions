## 17. Write a C function that adds an element to a dynamic array using realloc. Make sure your code is safe, even if realloc fails.

**Answer**
```c
int* temp = realloc(*arr, (*size + 1) * sizeof(int));
if (temp == NULL) return -1;
*arr = temp;
```

## 18. Write a function that joins two strings together using dynamic memory allocation. Make sure your code works if either string is empty or NULL.

**Answer**
```c
char* string_concat(const char* str1, const char* str2) 
{
    if (str1 == NULL) str1 = "";
    if (str2 == NULL) str2 = "";
    
    size_t len = strlen(str1) + strlen(str2) + 1;
    char* result = malloc(len);
    if (result == NULL) return NULL;
    
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}
```

## 19. Write your own version of calloc by using malloc and memset.

**Answer**
```c
void* ptr = malloc(n * size);
if (ptr) memset(ptr, 0, n * size);
return ptr;
```

## 20. Make a structure for a student record, where the name can be any length. Show how you would allocate and free this structure.

**Answer**
```c
typedef struct {
    char* name;
    int age;
    float gpa;
} Student;

Student *s = malloc(sizeof(Student));
if (!s) return 0;

char *temp = "Name String";
s->name = malloc(strlen(temp) + 1);
if (!s->name) return 0;

s->id = 101;
s->marks = 92.5;
strcpy(s->name, temp);

free(s->name);
free(s);

void free_student(Student* s) {
    if (s != NULL) {
        free(s->name);
        free(s);
    }
}
```