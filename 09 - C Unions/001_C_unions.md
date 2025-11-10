# C Unions - Questions and Solutions

```c
#include <stdio.h>
```

## Question 1:
You are building a program to handle messages that can have different types of data, like numbers (int or float) or short text. How can a union help you use less memory for this? What do you need to be careful about when using the union?

```c
union Message {
    int intValue;
    float floatValue;
    char text[16];
};
```

### Answer:
The union allocates memory equal to the size of its largest member.
Writing to one member and then reading another type leads to undefined behavior.

---

## Question 2:
If you have a union with an int, a float, and a char array, and you store a value in the int member, what will happen if you immediately try to read from the float member? Why does this happen?

```c
union Example {
    int i;
    float f;
    char str[4];
};
union Example ex;
// What happens if you now read ex.f?
```

### Answer:
```c
ex.i = 12345;      // Store an integer in the union
float var = ex.f;  // Access the same memory as a float
```

---

## Question 3:
You are making a device driver, and sometimes your hardware gives you a 32-bit error code, sometimes a floating-point value, and sometimes a short text message. How can you use a union in a structure to store these different values? What are the good and bad things about this approach?

### Answer:
```c
struct StatusReport {
    int type; // 0: error code, 1: sensor value, 2: message
    union {
        int errorCode;
        float sensorValue;
        char message[8];
    } data;
};
```

---

## Question 4:
What will be the output? Is there anything risky about using unions this way?

```c
union Data {
    int i;
    float f;
    char str[4];
};
union Data d;
d.i = 0x41424344;
printf("%s\n", d.str);
// What will the output look like? What should you be careful about?
```

### Answer:
Output - ABCD
Writing to one member and then reading from another member type can lead to undefined behavior.

---

## Question 5:
You need to store data about different shapes: circles (need radius), rectangles (length and width), and triangles (three sides). How could you use a structure and a union together to save memory? How would you know which shape you are dealing with when using the data?

### Answer:
```c
struct Shape {
    int type; // 1: circle, 2: rectangle, 3: triangle
    union {
        float radius;
        struct { 
            float length, width; 
        } rectangle;
        struct { 
            float a, b, c; 
        } triangle;
    } data;
};
```
Always check type before accessing union members.
Accessing the wrong member (e.g., reading rectangle data when it's actually a circle)

---

## Question 6:
Suppose you have a structure that can either store a pointer to a file or a pointer to a memory buffer, but not both at the same time. How would you use a union for this? What do you need to watch out for when working with the union members?

### Answer:
```c
struct FileOrBuffer {
    int mode; // 0: file, 1: buffer
    union {
        FILE *fp;
        char *buffer;
    } handle;
};
```
Always check type before accessing union members.
Accessing the wrong member

---

## Question 7:
If you use a union in a program that runs on different computer systems (like little-endian or big-endian CPUs), what kind of problems could happen when you try to use the same memory as different types?

```c
union EndianTest {
    int i;
    char c[4];
};
```

### Answer:
Little-endian: Least significant byte (LSB) stored first.
Big-endian: Most significant byte (MSB) stored first.
Can lead to incorrect data interpretation.

---

## Question 8:
How do anonymous unions make your code easier to read or maintain? Can you give a simple example where an anonymous union inside a structure helps when working with hardware or communication data?

### Answer:
```c
struct Register {
    unsigned int status;
    union {
        struct { unsigned int low, high; };
        unsigned long long full;
    }; // Anonymous union
};
```

---

## Question 9:
If you have an array of unions, and you store different types in each element (like int, float, or string), what problems can you run into if you try to read all values as the same type later? How can you avoid or check for this problem?

```c
union Variant {
    int i;
    float f;
    char str[8];
};
union Variant arr[10];
// What if you read arr[5].f when it was set as an int?
```

### Answer:
Incorrect data interpretation.

---

## Question 10:
Why is it not safe to use a union to switch (type pun) between types that might have different memory alignment, like between a double and a char array? What could go wrong on some computers?

```c
union TypePunning {
    double d;
    char bytes[8];
};
// What could go wrong here on different systems?
```

### Answer:
can be unsafe due to differences in memory alignment, endianness, and representation across systems.