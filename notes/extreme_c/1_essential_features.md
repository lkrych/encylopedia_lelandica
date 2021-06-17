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

