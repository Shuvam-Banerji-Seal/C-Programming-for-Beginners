# Module 20: Professional Development 🎓

Learn professional C development practices!

## 📚 What You'll Learn

1. Build systems (Make, CMake)
2. Unit testing in C
3. Code style and standards
4. Version control best practices
5. Profiling and optimization
6. Writing maintainable code

## 🔨 Makefile Example

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = myprogram

SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
$(CC) $(CFLAGS) -c $<

clean:
rm -f $(OBJS) $(TARGET)

.PHONY: all clean
```

## 📋 CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject C)

set(CMAKE_C_STANDARD 11)

add_executable(myprogram main.c utils.c)

# Enable warnings
target_compile_options(myprogram PRIVATE -Wall -Wextra)

# Add tests
enable_testing()
add_test(NAME test1 COMMAND myprogram)
```

## 🧪 Unit Testing

```c
// Simple test framework
#include <assert.h>

void test_addition() {
    assert(add(2, 3) == 5);
}

void test_multiplication() {
    assert(multiply(2, 3) == 6);
}

int main() {
    test_addition();
    test_multiplication();
    printf("All tests passed!\n");
    return 0;
}
```

## 📊 Profiling with gprof

```bash
gcc -pg -o program program.c
./program
gprof program gmon.out > analysis.txt
```

## 🎯 Code Style Guidelines

1. **Naming**: Use descriptive names
2. **Indentation**: 4 spaces or tabs
3. **Comments**: Explain why, not what
4. **Functions**: Keep them small and focused
5. **Error handling**: Always check return values
6. **Memory**: Free what you allocate

## 🔜 Congratulations!

You've completed the course! Keep practicing and building projects.

---

**Final Tip**: The journey of learning never ends. Keep coding, keep learning!
