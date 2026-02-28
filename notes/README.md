# Course Notes

This folder contains LaTeX reference notes for each module of the Complete C Programming Course.

## Contents

| File | Module |
|------|--------|
| `module-01.tex` | Getting Started with C |
| `module-02.tex` | Variables and Data Types |
| `module-03.tex` | Control Flow |
| `module-04.tex` | Functions |
| `module-05.tex` | Arrays and Strings |
| `module-06.tex` | Pointers |
| `module-07.tex` | Advanced Memory Management |
| `module-08.tex` | Structures and Unions |
| `module-09.tex` | File I/O |
| `module-10.tex` | Preprocessor and Macros |
| `module-11.tex` | Data Structures Fundamentals |
| `module-12.tex` | Advanced Data Structures |
| `module-13.tex` | Debugging with GDB |
| `module-14.tex` | GTK4 GUI Programming |
| `module-15.tex` | Game Development Projects |
| `module-16.tex` | Network Programming |
| `module-17.tex` | Machine Learning in C |
| `module-18.tex` | Handwriting Recognition |
| `module-19.tex` | Scientific Computing |
| `module-20.tex` | Professional Development |

## Compiling

Each file is a standalone LaTeX document. To compile a single module:

```bash
pdflatex module-01.tex
```

To build all notes at once using the provided Makefile:

```bash
make          # Build all PDFs
make module-01  # Build a specific module
make clean    # Remove generated PDFs and auxiliary files
```

## Requirements

A LaTeX distribution with `pdflatex` is required. On Ubuntu/Debian:

```bash
sudo apt-get install texlive-latex-base texlive-latex-recommended texlive-fonts-recommended
```
