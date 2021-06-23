# From Source to Binary

## Table of Contents

## Introduction

In programming, everything starts with source code. Source code typically consists of a number of text files. The CPU cannot execute textual instructions, these files need to be translated by a compiler to machine-level instructions.

In this chapter we will discuss:
1. The C compilation pipeline
2. Preprocessor
3. Compiler
4. Assemblers
5. Linkers

For more discussion about these systems, please check out my [Computer Systems](https://github.com/lkrych/encylopedia_lelandica/tree/main/notes/computer_systems) notes. 

## Compilation Pipeline

<img src="image/2_compilation_pipeline.png">

The C compilation pipeline has four distinct components with each of them doing a different task.

1. Preprocessor
2. Compiler
3. Assembler
4. Linker

Each component in this pipeline accepts a certain input from the previous component and produces a certain output for the next component of the pipeline.

A **platform** is a **combination of an operating system running on specific hardware**. The most important part of the platform is its **CPU instruction set**. 

Cross-platform software can run on different platforms. However there is a distinction between cross-platform and portable software. **Cross-platform software has different binaries and installers** for each platform, **portable software uses the same produced binaries and installers** on all platforms.

### Header files

Header files typically have a `.h` extension, they usually contain **enumerations, macros, and typedefs**, as well as the **declarations of functions, global variables, and structures**. In C, declarations can be separated from definitions for some objects.

As a rule of thumb, **the declarations are stored in header files** and the corresponding **definitions go to source files**.

Let's look at an example of a header file with a function declaration, and a source file with its definition.

*average.h*
```c
double average(int*, int)
```
*average.c*
```c
double average(int* array, int length) {
    if (length <= 0) {
        return 0;
    }
    double sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    return sum/length;
}
```

To further cement these concepts we are going to walk through the compilation pipeline with a specific example.

### Compiling an example

In this example we will have three files, one header file and two source files. The purpose of this code is to calculate the average of an array.

The header file is used as a bridge between two separate source files and makes it possible to write our code in two separate files but build them together. The header file will contain the function declaration of `avg`, one of the source files will contain the definition of `avg`, and the other will be invoking the function.

- /2_example
    - average.h
    - average.c
    - main.c
