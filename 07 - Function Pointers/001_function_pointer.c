#include <stdio.h>
#include <stdlib.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

typedef int (*MathOperation)(int, int);

int add(int a, int b) 
{
    return a + b;
}

int subtract(int a, int b) 
{
    return a - b;
}

int multiply(int a, int b) 
{
    return a * b;
}

int divide(int a, int b) 
{
    if (b == 0) 
    {
        return 0;
    }
    return a / b;
}


int main() 
{
    int num1 = 20, num2 = 10;
    int result;
    MathOperation operation;
    
    operation = add;
    result = operation(num1, num2);
    printf("Addition: %d + %d = %d\n", num1, num2, result);
    
    operation = subtract;
    result = operation(num1, num2);
    printf("Subtraction: %d - %d = %d\n", num1, num2, result);
    
    operation = multiply;
    result = operation(num1, num2);
    printf("Multiplication: %d * %d = %d\n", num1, num2, result);
    
    operation = divide;
    result = operation(num1, num2);
    printf("Division: %d / %d = %d\n", num1, num2, result);
    
    return 0;
}