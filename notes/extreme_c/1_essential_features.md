# Essential Features

## Table of Contents

## Foreshadowing

This first chapter is about essential features of the C language. It will cover:
1. Preprocessing, Macros and Conditional Compilation
2. Variable Pointers
3. Functions
4. Function Pointers
5. Structures

## Preprocessor Directives

Preprocessing is a unique feature of the C language. It allows you to **modify your source code before submitting it to the compiler**. 

The purpose of preprocessing is to **remove the preprocessing directives and substitute them with equivalent generated C code** and prepare a final source that is ready to be submitted to the compiler.

The **behavior of the C preprocessor** can be controlled and **influenced using** a set of **directives**, lines of code that start with the `#` symbol. The most important directives used for **macro definition** and **conditional compilation**.

## Macros

There is no escaping macros in C code. You will see them in the following places:

1. Defining a constant
2. Using as a function instead of writing a C function
3. Loop unrolling
4. Header guards
5. Code generation
6. Conditional compilation

Macros are defined using the `#define` directive. Each macro has a name and a possible list of parameters. A macro also has a value that gets substituted by its name in the preprocessing phase in a step known as **macro expansion**. This means that **macros only exit before the compilation phase**. 

```c
#define ABC 5

int main(int argc, char** argv) {
    int x = 2;
    int y = ABC;

    int z = x + y;
    return 0;
}
```

Above, `ABC` is **not a variable that holds an integer value** or an integer constant! It is a **macro** and its value is 5. After the macro expansion, the resulting code that will be submitted to the compiler is.

```c
int main(int argc, char** argv) {
    int x = 2;
    int y = 5;
    int z = x + y;
    return 0;
}
```

In the preceding example, the preprocessor did the **macro expansion**, and as part of this step, **replaced the macro's name with its value.** Let's look at another one, this time an example with a little more teeth.

```c
#define ADD(a, b) a + b

int main(int argc, char** argv) {
    int x = 2;
    int y = 3;

    int z = ADD(x,y);
    return 0;
}
```

Similar to the first example, `ADD` is not a function. It is a **function-like macro** that accepts arguments. After pre-processing, the code will look like:

```c
int main(int argc, char** argv) {
    int x = 2;
    int y = 3;

    int z = x + y;
    return 0;
}
```

Because function-like macros can accept input arguments, they **can mimic c functions**. 

### Translation Units and Using the Compiler to view code after preprocessing

Let's take the example directly above and save it to a file: `macro_add.c`. Let's invoke the compiler with the `-E` flag set so that we can view the code before it gets compiled, but after preprocessing.

```bash
~/encylopedia_lelandica/notes/extreme_c/examples(main*) » gcc -E macro_add.c
# 1 "macro_add.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 366 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "macro_add.c" 2


int main(int argc, char** argv) {
    int x = 2;
    int y = 3;

    int z = x + y;
    return 0;
}
```

What we can see here is called the **translation unit**, and it is the preprocessed C code that is ready to be passed to the compiler. In a translation unit, all directives are substituted with inclusions or macro expansions and a flat long piece of C code has been produced.

### Using Macros to create a DSL

Let's take a look at an example of using a few macros to generate a loop.

```c
#include <stdio.h>

#define PRINT(a) printf("%d\n", a);
#define LOOP(v, s, e) for (int v = s; v <= e; v++) {
#define ENDLOOP }

int main(int argc, char** argv) {
    LOOP(counter, 1, 10)
        PRINT(counter)
    ENDLOOP
    return 0;
}
```

This is a wild example. The code inside the main function is in no way valid C code, however after macro expansion, it becomes. 

```c
... some stuff

int main(int argc, char** argv){
    for (int counter = 1; counter <= 10; counter++) {
        printf("%d\n", counter);
    }
    return 0;
}
```
This is an example that shows one of the applications of macros. A well defined set can be used to define a **domain specific language(DSL)**, and allow you to write code using that DSL. DSLs are used heavily in testing frameworks like `gtest`.

### Advantages and Disadvantages of Macros

**Good software design** dictates that we should **try to package similar algorithms and concepts in several manageable and reusable modules**. 

Macros by contrast try to make everything **linear and flat** by substituting macro values before compile time. 

This has led to the C developer adage of : *if a macro can be written as a C function, then you should write a C function instead*. 

Another problem is the **mismatch between the source code and the translation unit**. If a C developer is looking at the compiler errors from a piece of code that heavily uses macros, they will have to back-track through the pre-processing macro expansion to figure out how the generated code that is currently erroring was created.

### Conditional Compilation

Conditional compilation allows you to have different preprocessed source code based on different conditions.

There are a list of directives contributing to conditional compilation:
1. #ifdef
2. #ifndef
3. #else
4. #elif
5. #endif

```c
#define CONDITION

int main(int argc, char** argv) {
    #ifdef CONDITION
        int i = 0;
        i++;
    #endif
        int j = 0;
        return 0;
}
```
Because the `CONDITION` macro is defined the lines between `#ifdef` will be copied to the final source code.

One of the most common use cases of this feature is for **header guards**. A header guard **protects a header file from being included twice in the preprocessing phase**.

```c
#ifndef EXAMPLE_1_8_H
#define EXAMPLE_1_8_H

void say_hello();
int read_age();

#endif
```

How do header guards work?

Let's imaging that the preceding example is a header file. The variable and function declarations are put inside the `#ifndef` block. As the first inclusion happens, the macro `EXAMPLE_1_8_H` is not yet defined, so the preprocessor continues by entering the `#ifndef` block. The next statement defines the macro, and the preprocessor copies everything into the macro value. The next time the inclusion happens, the macro is already defined so the preprocessor skips the content.

Another common pattern is to use the `#pragma once` directive in order to protect a header from double inclusion. This pattern is not a C standard so it is not portable.

```c
#pragma once

void say_hello();
int read_age();

```

## Variable Pointers

Pointers are one of the most fundamental concepts in C. 

Fundamentally, a **pointer** is a **variable that stores a memory address**.

An asterisk (*) is used to declare a pointer in C. A **pointer which has a zero value** is called a **null pointer**. A null pointer does not point to a valid memory address.

The ampersand (&) is known as the **referencing operator**. It returns the address of the variable next to it.

The asterisk (*) used after declaration of a pointer is known as the **dereferencing operator**. It allows you to have **access to the memory cell that the pointer is pointing to**. Dereferencing a null pointer can lead to a crash in your program because a null pointer does not point to a valid memory address.

```c
int main(int argc, char** argv) {
    int var = 100; // declare and initialize var
    int* ptr = 0;  // declares and initialize null pointer
    ptr = &var;    // use reference operator to obtain the address of the variable
    *ptr = 200;    // use the dereferencing operator to save the value 200 in the address pointed to by ptr
    return 0;
}
```

It's common to define a `NULL` macro with a value of 0. This can be used to nullify pointers upon declaration.

```c
char* ptr = NULL;
```

### Arithmetic on pointers

The simplest picture of memory is **a very long one-dimensional array of bytes**. You can only go back and forth in the array. There's no other possible movement.

We can think of pointer arithmetic using this image of memory, you can add to a pointer to make the pointer go forward in memory, and you can subtract from the pointer to make it go backward in memory.

Each pointer has an **arithmetic step size**, this is the size of the data type that is pointed to by the pointer. A char is one byte, so the arithmetic step size is 1. An int is 4 bytes, so an int pointer has an arithmetic step size of 4. 

A good question to ask is why this is useful? 

In C, arrays are pointers that point to the first element of the array. Well, we know that **arrays are adjacent variables inside memory**, so incrementing and decrementing a pointer which is pointing to an element effectively makes it move back and forth inside the array and point to different elements.

### Generic Pointers

A pointer of type `*void` is said to be a **generic pointer**. It can point to any address like all other pointers, but we don't know its actual data type. This means we don't know its arithmetic step size.

Generic pointers are usually used to hold the content of other pointers, but they forget the actual data types of those pointers. This means **a generic pointer cannot be dereferenced** because the compiler does not know how much data should be read from memory.  

Generic pointers are useful for defining generic functions that can accept a wide range of pointers as their input arguments.

generic pointer example:
```c
#include <stdio.h>

void print_bytes(void* data, size_t length) {
    char delim = ' ';
    unsigned char*  ptr = data;
    for (size_t i = 0;  i < length; i++) {
        printf("%c  0x%x", delim, *ptr);
        delim = ",";
        ptr++;
    }
    printf("\n");
}

int main(int argc, char** argv) {
    int a = 9;
    double b = 18.9;

    print_bytes(&a, sizeof(int));
    print_bytes(&b, sizeof(int));

    return 0;
}
```

```bash
~/encylopedia_lelandica/notes/extreme_c/examples(main*) » gcc -o print_bytes 1_print_bytes.c
---------------------------------------------------------------------------------------------
~/encylopedia_lelandica/notes/extreme_c/examples(main*) » ./print_bytes
   0x9,  0x0,  0x0,  0x0
   0x66,  0x66,  0x66,  0x66,  0x66,  0xe6,  0x32,  0x40
```

The `print_bytes` function receives an address as a `void*` pointer and ann integer indicating the length. Using the arguments, the function prints all the bytes started from the given address. By accepting a generic pointer, we can pass whatever kind of pointer we want.

Inside the `print_bytes` function we use an unsigned char pointer to move inside memory because an **unsigned char is 1 byte**. This makes it the best pointer type for iterating over a range of memory addresses.

### Size of a pointer

`size_t` is a standard and unsigned data type for storing sizes in C. In general you cannot define a fixe size for a pointer. **The size of a pointer depends on the architecture**. 

You can use the `sizeof` function to obtain the size of a pointer.

### Dangling pointers

The most common way to misuse a pointer is have a **dangling pointer**. A pointer usually points to an address where a variable is allocated. Reading or modifying an address where there is no variable registered is a big mistake and can result in a crash.

dangling pointer example:
```c
#include <stdio.h>

int* create_an_innteger(int default_value) {
    int var = default_value;
    return &var;
}

int main() {
    int* ptr = NULL;
    ptr = create_an_integer(10);
    printf("%d\n", *ptr);
    return 0;
}
```

In the example above, the `create_an_integer` function is used to create an integer. This function will not work because the `ptr` pointer **will point to an already de-allocated portion of memory**. 

The `var` variable is a local variable to the `create_an_integer` function that lives on the stack and it will be de-allocated after leaving the function.

The proper way to write this code is to **use Heap memory**.

```c
#include <stdio.h>

int* create_an_innteger(int default_value) {
    int* var_ptr = (int*)malloc(sizeof(int));
    *var_ptr = default_value;
    return var_ptr;
}

int main() {
    int* ptr = NULL;
    ptr = create_an_integer(10);
    printf("%d\n", *ptr);
    free(ptr);
    return 0;
}
```

Variables allocated from Heap memory are not limited to the function declaring it. Therefore it can be accessed in the main function. The pointer to this variable is not dangling anymore. Eventually the variable becomes de-allocated by calling `free`.

## Functions

In C, **functions return only one value**. Functions are **always blocking** in C. This means that the caller ha to wait for a function to finish and only then can it collect the returned result. Asynchronous functions are implemented using multithreading. They are discussed more in the concurrency section of these notes.

Nowadays there is growing interest in writing non-blocking function calls. This is usually positioned as **event-oriented programming**. In this style, actual function calls happen inside an event loop, and proper callbacks are triggered upon the occurrence of an event. Frameworks such as `libuv` and `libev` promote this way of coding.

### Stack Management

The memory layout of a process running on a Unix-like OS includes a **segment known as the Stack**. The Stack segment is the **default memory location where all local variables, arrays and structures are allocated from**. When you declare a local variable in a function, it is allocated on top of the Stack segment.

The Stack segment is used for function calls. **When you call a function**, a **stack frame** containing the return address and all the passing arguments is **put on top of the Stack segment**, and only then is the function logic executed. When **returning** from the function, the **stack frame is popped out**, and the instruction addressed by the return address gets executed, which should **usually continue the caller function**.

All local variables declared int he function body are put on top of the Stack segment. So when leaving the function, all Stack variables become freed. That is why they are called local variables and that is also why a function cannot access variables in another function.

### Pass-by-value versus Pass-by-reference

You can **only pass-by-value in C**. There is no reference in C. Everything is copied into the function's local variables and you cannot read or modify them after leaving a function.

```c
#include <stdio.h>

void func(int* a) {
    int b = 9;
    *a = 5;
    a = &b;
}

int main(int argc, char** argv) {
    int x = 3;
    int* xptr = &x;
    printf("Value before call: %d\n", x);
    printf("Pointer before function call: %p\n", (void*)xptr);
    func(xptr);
    printf("Value after call: %d\n", x);
    printf("Pointer after function call: %p\n", (void*)xptr);
    return 0;
}
```
```bash
~/encylopedia_lelandica(main) » gcc 1_pass_by_value.c -o pass_by_value
----------------------------------------------------------------------------------------

~/encylopedia_lelandica(main*) » ./pass_by_value                                 lkrych@LKRYCH-M-W49D
Value before call: 3
Pointer before function call: 0x7ffee9dc1a0c
Value after call: 5
Pointer after function call: 0x7ffee9dc1a0c
```
What we see here is that the value of the pointer is not changed after the function call, one might suppose that we would see the value of 9, after the invocation of `func`, however the pointer is passed by value. Dereferencing the pointer inside `func` has allowed accessing the variable where the pointer is pointing to, but changing the value of the pointer parameter inside the function doesn't change its counterpart argument in the caller function.

The above example demonstrates an important style in C programming: it is **recommended that we use pointers as arguments instead of passing objects into a function** because copying a pointer value is much more efficient than copying hundreds of bytes of a big object into a function.

### Function Pointers

Function pointers are another unique feature of C. Their most common application is to **split a large binary into smaller binaries and loading them again in small executables**. This technique has led to **modularization** and software design.

Like a variable pointer addressing a variable, a function pointer addresses a function and allows you to call that function indirectly.

```c
#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    int (*func_ptr) (int, int);
    func_ptr = NULL;

    func_ptr = &sum;
    int result = func_ptr(5, 4);
    printf("Sum: %d\n", result);

    func_ptr = &subtract;
    int result = func_ptr(5, 4);
    printf("Subtract: %d\n", result);
    return 0
}
```

In the preceding example, `func_ptr` is a function pointer, it **can only point to a specific class of functions that match its signature**. We can call different functions for the same list of arguments using a single function pointer. T**his is the only way to support polymorphism in C**. 

A common pattern is to use `typedef` for function pointers. The `typedef` keyword allows you to define an alias for an already defined type. These aliases add readability to the code and let you choose a shorter name for a long and complex type. In C, the name of a new type usually ends with `_t` by convention.

## Structures

Structures are one of the most important features of C, they enable **encapsulation**. Structures **encapsulate related values under a single unified type**. 

```c
struct color_t {
    int red;
    int green;
    int blue;
}
```

*Note that we use an `_t` suffix for naming new types*.

Structures **allow you to define your own data types**. These types are different from the types you could define with the keyword `typedef`. The `typedef` keyword doesn't really create a new type, but rather it defines an alias for an already defined type.

### Memory layout

It is important for C programmers to know the memory layout of a structure variable. Having a bad layout could cause performance degradations on certain architectures.

The memory layout of a structure is very similar to an array. The difference is that in an array all the element have the same type and therefore the same size. In a struct, each field can have a different type and hence, a different size. This means that unlike an array, **the size of a struct in memory depends on a few factors and cannot be easily determined**.

Let's look at an example:

```c
#include <stdio.h>

struct sample_t {
    char first;
    char second;
    char third;
    char fourth;
};

void print_size(struct sample_t* var) {
    printf("Size: %lu bytes\n", sizeof(*var));
}

void print_bytes(struct sample_t* var) {
    unsigned char* ptr = (unsigned char*) var;
    for (int i = 0; i < sizeof(*var); i++,  ptr++) {
        printf("%d ", (unsigned int)*ptr);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    struct sample_t var;
    var.first = 'A';
    var.second = 'B';
    var.third = 'C';
    var.fourth = 765;
    print_size(&var);
    print_bytes(&var);
    return 0;
}
```
and now let's compile it

```bash
~/encylopedia_lelandica(main*) » gcc 1_print_struct.c -o print_struct

~/encylopedia_lelandica(main*) » ./print_struct                                              lkrych@LKRYCH-M-W49D
Size: 6 bytes
65 66 67 0 253 2
```