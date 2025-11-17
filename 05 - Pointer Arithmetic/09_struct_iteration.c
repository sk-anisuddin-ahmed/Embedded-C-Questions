/*
Problem: Iterate over struct array using pointer arithmetic
Given pointer to struct, iterate over array of structs using only
pointer arithmetic, accounting for struct padding and alignment.

Example:
struct Student { int id; char name[20]; float grade; };
Iterate through array accounting for padding between members
*/

#include <stdio.h>

typedef struct student
{
    int id;
    char name[20];
    float grade;
} Student;

int main()
{
    Student students[] = {
        {1, "Alice", 85.5},
        {2, "Bob", 92.0}
    };
    
    Student *current = students;
    
    printf("Struct size: %zu bytes\n", sizeof(Student));
    
    for (int i = 0; i < 2; i++)
    {
        printf("ID=%d, Name=%s, Grade=%.1f\n", 
               current->id, current->name, current->grade);
        current++;
    }
    
    return 0;
}