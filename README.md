# Complete C Programming Course 🚀

Welcome to the **Complete C Programming Course** - a comprehensive journey from absolute beginner to advanced C programmer! This course covers everything from basic syntax to advanced topics like machine learning, network programming, and scientific simulations.

## 📚 Course Overview

This course is structured into 20 modules, each building upon the previous one. Whether you're a complete beginner or looking to master advanced C programming, this course has something for you.

## 🗺️ Course Structure

### **Beginner Level** (Modules 1-5)

#### [Module 01: Getting Started with C](./01-basics/README.md)
- Introduction to C Programming
- Setting Up Your Development Environment
- Your First C Program (Hello World)
- Understanding Compilation Process
- Basic Input/Output

#### [Module 02: Variables and Data Types](./02-variables-and-types/README.md)
- Variables and Constants
- Primitive Data Types (int, float, char, double)
- Type Conversion and Casting
- Operators (Arithmetic, Relational, Logical, Bitwise)
- Pre/Post Increment and Decrement

#### [Module 03: Control Flow](./03-control-flow/README.md)
- Conditional Statements (if, else, else-if)
- Switch Statement
- Loops (for, while, do-while)
- Break and Continue
- Nested Loops and Loop Performance

#### [Module 04: Functions](./04-functions/README.md)
- Function Declaration and Definition
- Function Parameters and Return Types
- Scope and Lifetime
- Recursion
- Function Pointers

#### [Module 05: Arrays and Strings](./05-arrays-and-strings/README.md)
- One-Dimensional Arrays
- Multi-Dimensional Arrays
- Character Arrays and Strings
- String Manipulation without string.h
- Common String Operations

### **Intermediate Level** (Modules 6-10)

#### [Module 06: Pointers](./06-pointers/README.md)
- Introduction to Pointers
- Pointer Arithmetic
- Pointers and Arrays
- Pointer to Pointer
- Pointers and Functions

#### [Module 07: Advanced Memory Management](./07-memory-management/README.md)
- Stack vs Heap Memory
- Dynamic Memory Allocation (malloc, calloc, realloc, free)
- Memory Leaks and Debugging
- Custom Memory Allocators
- Memory Management Best Practices

#### [Module 08: Structures and Unions](./08-structures-unions/README.md)
- Defining Structures
- Nested Structures
- Arrays of Structures
- Pointers to Structures
- Unions and Bit Fields
- typedef and enum

#### [Module 09: File I/O](./09-file-io/README.md)
- File Handling Basics
- Reading and Writing Text Files
- Binary File Operations
- File Positioning
- Error Handling in File Operations

#### [Module 10: Preprocessor and Macros](./10-preprocessor/README.md)
- Preprocessor Directives
- Macros and Macro Functions
- Conditional Compilation
- Header Guards
- Common Preprocessor Tricks

### **Advanced Level** (Modules 11-15)

#### [Module 11: Data Structures Fundamentals](./11-data-structures/README.md)
- Linked Lists (Singly, Doubly, Circular)
- Stacks and Queues
- Hash Tables
- Implementation and Complexity Analysis
- Visualization with Mermaid Diagrams

#### [Module 12: Advanced Data Structures](./12-advanced-data-structures/README.md)
- Binary Trees and Binary Search Trees
- AVL Trees and Red-Black Trees
- Heaps and Priority Queues
- Graphs (Representation and Traversal)
- Tries and Suffix Trees
- Complete DSA with Visual Diagrams

#### [Module 13: Debugging with GDB](./13-debugging-gdb/README.md)
- Introduction to GDB
- Setting Breakpoints
- Stepping Through Code
- Examining Variables and Memory
- Advanced GDB Techniques
- Debugging Memory Issues

#### [Module 14: GTK4 GUI Programming](./14-gtk4-gui/README.md)
- Introduction to GTK4
- Setting Up GTK4 Development
- Creating Windows and Widgets
- Event Handling
- Building a Simple GUI Application
- GTK4 Best Practices

#### [Module 15: Game Development Projects](./15-game-projects/README.md)
- Console-Based Tic-Tac-Toe
- Snake Game
- Sudoku Solver
- Simple Platformer Basics
- Game Loop and State Management

### **Expert Level** (Modules 16-20)

#### [Module 16: Network Programming](./16-network-programming/README.md)
- Socket Programming Basics
- TCP/IP Communication
- UDP Programming
- HTTP Client/Server Implementation
- Multi-threaded Servers
- Network Protocol Implementation

#### [Module 17: Machine Learning in C](./17-machine-learning/README.md)
- Introduction to ML Concepts
- Perceptron Implementation
- Simple Neural Networks from Scratch
- Activation Functions
- Forward and Backward Propagation
- Training Neural Networks

#### [Module 18: Handwriting Recognition](./18-digit-recognition/README.md)
- Understanding MNIST Dataset
- Image Processing in C
- Building a Digit Recognizer
- Training and Testing
- Optimization Techniques
- Complete Working Project

#### [Module 19: Scientific Computing](./19-scientific-computing/README.md)
- Numerical Methods
- Matrix Operations
- Molecular Dynamics Simulations
- Physics Simulations
- Data Visualization
- Performance Optimization

#### [Module 20: Professional Development](./20-professional-dev/README.md)
- Build Systems (Make, CMake)
- Unit Testing in C
- Code Style and Standards
- Version Control Best Practices
- Profiling and Optimization
- Writing Maintainable Code

## 🎯 Learning Path

### For Complete Beginners
Start with Module 01 and work through Modules 1-5 sequentially. Take your time with each concept.

### For Those with Basic Programming Knowledge
You might skim Modules 1-3 and focus more on Modules 4-10.

### For Intermediate Programmers
Jump to Modules 6-15, focusing on areas where you need improvement.

### For Advanced Learners
Modules 16-20 provide cutting-edge applications of C programming.

## 📝 How to Use This Course

1. **Read the Theory**: Each module starts with conceptual explanations
2. **Study the Examples**: Carefully examine the provided code examples
3. **Compile and Run**: Use the provided Makefiles to compile examples
4. **Learn from Bugs**: Study the buggy examples to understand common mistakes
5. **Practice**: Complete the exercises at the end of each section
6. **Build Projects**: Apply your knowledge in the projects
7. **Review**: Revisit difficult concepts and practice more

## 🛠️ Prerequisites

- A computer (Windows, macOS, or Linux)
- A C compiler (GCC or Clang - both supported)
- A text editor or IDE (VS Code, CLion, Vim, etc.)
- Basic command-line knowledge
- Enthusiasm to learn!

## 🔧 Compilation Quick Start

Each module includes a **Makefile** for easy compilation:

```bash
# Navigate to any module
cd 03-control-flow

# Compile all programs
make

# Run programs
./conditionals
./loops
./switch_demo

# Clean up compiled files
make clean

# Use Clang instead of GCC
make CC=clang
```

📘 **For detailed compilation instructions**, see [COMPILATION_GUIDE.md](./COMPILATION_GUIDE.md)

### Available Make Targets

Most modules support these targets:
- `make` - Compile all programs
- `make clean` - Remove compiled files
- `make run` - Compile and run all programs
- `make run-buggy` - Run buggy examples (educational)
- `make debug` - Compile with debug symbols
- `make asan` - Compile with AddressSanitizer (memory error detection)

### Example Compilation

```bash
# Module 03: Control Flow
cd 03-control-flow
make                    # Compile with GCC
make CC=clang          # Compile with Clang
make run               # Run all correct examples
make run-buggy         # Run buggy examples

# Module 06: Pointers
cd ../06-pointers
make asan              # Compile with memory sanitizer
./pointer_basics

# Module 07: Memory Management
cd ../07-memory-management
make valgrind          # Run with Valgrind (if installed)
```

## 💡 Features

- ✅ **Progressive Learning**: Concepts build upon each other logically
- ✅ **Visual Aids**: Mermaid diagrams for data structures and algorithms
- ✅ **Hands-on Projects**: Real-world applications in every advanced module
- ✅ **Best Practices**: Learn industry-standard coding practices
- ✅ **Complete Examples**: Every concept is demonstrated with working code
- ✅ **Buggy Examples**: Learn from deliberately wrong code with explanations
- ✅ **Compilation Guide**: Comprehensive guide for GCC and Clang with all flags explained
- ✅ **Makefiles**: Each module includes a Makefile with detailed flag documentation
- ✅ **Memory Safety**: Examples include sanitizers for detecting memory errors
- ✅ **Exercises**: Reinforce learning with practical problems

## 📖 Additional Resources

- **[Compilation Guide](./COMPILATION_GUIDE.md)**: Complete guide to GCC and Clang compiler flags
- **Makefiles**: Each module has a Makefile with detailed comments
- **Buggy Code**: Learn from common mistakes with `*_buggy.c` files
- **Cheat Sheets**: Quick reference guides in each module
- **Common Pitfalls**: Learn from common mistakes
- **FAQs**: Answers to frequently asked questions
- **External Resources**: Curated links to additional learning materials

## 🤝 Contributing

This is an educational resource. If you find errors or want to suggest improvements, please feel free to contribute!

## 📜 License

This course is released under the MIT License. See [LICENSE](./LICENSE) for details.

## 🚀 Getting Started

Ready to begin? Head over to [Module 01: Getting Started with C](./01-basics/README.md) and start your journey!

---

**Happy Coding!** 💻✨

Remember: The best way to learn programming is by doing. Don't just read the code—type it out, modify it, break it, and fix it. That's how you truly learn!
