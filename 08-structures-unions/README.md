# Module 08: Structures and Unions

Organize complex data with structures and unions!

## What You'll Learn

1. Defining structures
2. Nested structures
3. Arrays of structures
4. Pointers to structures
5. Unions and bit fields
6. typedef and enum

## Structures

```c
#include <stdio.h>
#include <string.h>

struct Student {
 char name[50];
 int age;
 float gpa;
};

int main() {
 struct Student s1;
 strcpy(s1.name, "Alice");
 s1.age = 20;
 s1.gpa = 3.8;

 printf("Name: %s, Age: %d, GPA: %.2f\n", s1.name, s1.age, s1.gpa);

 return 0;
}
```

## Typedef

```c
typedef struct {
 int x;
 int y;
} Point;

Point p1 = {10, 20};
```

## Unions

```c
union Data {
 int i;
 float f;
 char str[20];
};

union Data data;
data.i = 10;
printf("%d\n", data.i);
data.f = 220.5;
printf("%.2f\n", data.f);
```

## Next Module

[Module 09: File I/O](../09-file-io/README.md)


## Files in this Module

Each source file has a companion markdown file with detailed explanations:

| File | Description |
|------|------------|
| [`advanced_structures.c`](advanced_structures.md) 📄 | Advanced Structures demonstration |
| [`bitfields_and_unions.c`](bitfields_and_unions.md) 📄 | Bitfields And Unions demonstration |
| [`structures_demo.c`](structures_demo.md) 📄 | Structures Demo demonstration |
| [`unions_demo.c`](unions_demo.md) 📄 | Unions Demo demonstration |

### Legend

- 📄 = Detailed explanation available
- 🐛 = Contains deliberate bugs for learning

