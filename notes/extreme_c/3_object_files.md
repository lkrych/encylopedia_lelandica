# Object Files

## Table of Contents

## Application Binary Interface

An **application programming interface (API)** is **a standard** agreed upon **between two software components**.

An **application binary interface (ABI)** is a standard that **guarantees that two programs are compatible at their machine-level instructions**.

For example, a program cannot use a static library that has a different ABI. An executable file cannot be run on a system supporting a different ABI than the one that the executable was built for.

An ABI will typically cover the following details:
1. The instruction set of the target architecture: processor instructions, memory layout, endianness, registers, etc.
2. Existing data types, their sizes, and alignment policy.
3. Function calling conventions like the structure of the stack frame.
4. Definitions of how system calls should be made.
5. Object file format (which this section will be about)

The **System V ABI** is the most widely used ABI among Unix-like OSes. **Executable and Linking Format (ELF)** is the standard object file format used in System V. 

## Object File Formats