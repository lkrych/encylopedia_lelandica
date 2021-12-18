# Basic Computing Concepts

## Table of Contents

### Introduction

Computers do a vast array of things and yet all of them rely on a limited repertoire of technologies.

At the heart of the modern computer is the **microprocessor (CPU)**, a tiny square of silicon that's etched with a network of gates and channels through which electricity flows.

The gates (transistors) and channels (wires) are a miniature version of the kind of circuitry that you might have seen when opening up old electronics.

**Once you understand how a microprocessor works, you'll have a thorough grasp of the fundamental concepts that underlie all of modern computing.**

### The Calculator Model of Computing

A computer **takes a stream of instructions (code) and a stream of data as input**, and it **produces a stream of results as an output**.

<img src="img/1_1.png">

For the purpose of an initial discussion, let's say that the code stream consists of different types of arithmetic operations and the data stream consists of data on which those operations operate. The results stream is thus the results of these operations. The results flow when the operators in the code stream are carried out on the operands in the data stream. 

Like a calculator, the computer takes numbers and operators as input, performs the requested operation, and then displays the results. These results might be in the form of pixel values that make up a rendered scene in a game, or they might be the dollar values ina financial spreadsheet.

### The File-Clerk Model of Computing

While the **calculator model** is useful, it **isn't the only** or even the best **way to think about what computers do**.

Let's look at another definition.

A computer is **a device that shuffles numbers around from place to place**, reading, writing, erasing, and rewriting different numbers in different locations **according to a set of inputs, a fixed set of rules for processing those inputs, and the prior history** of all the inputs that the computer has seen since it was last reset, until a predefined set of criteria are met that cause the computer to halt. 

We might call this idea of the computer the "file-clerk" model of computing.

In the **file-clerk model**, **the computer accesses a large store of sequentially arranged numbers for the purpose of altering the store** to achieve a desired result. Once the result is achieved, the computer stops so that a human can now read and interpret the store.

This model is useful because it emphasizes the end product of the computation not the computation itself. **The purpose of computers is to produce usable results from a given data set.**

Once we understand computers not in terms of the math they do, but in terms of the numbers they move and modify, we can begin to get a fuller picture of how they operate.

In a nutshell, a** computer is a device that reads, modifies, and writes sequences of numbers**. These functions: read, modify and write, are the **most fundamental functions that a computer performs**.

### The Stored-Program Computer

All computers consist of at least three fundamental types of structures needed to carry out the read-modify-write sequence:

1. **Storage** - All computers have **a place to put numbers**, a place to read from and write to.
2. **Arithmetic Logic Unit** - The device that **performs arithmetic operations** on numbers in the storage area. 

First numbers are read from the storage in the ALU's data input port. Once inside the ALU, they're modified by means of an arithmetic calculation, and then they're written back to storage via the ALU's output port.
3. **Bus** - The means or transmitting numbers between the ALU and storage. The bus is **a network of transmission lines for shuttling numbers inside the computer**.

The figure below depicts the code stream as a prerecorded list of instructions that is stored in a special area just like the data stream. 

<img src="img/1_3.png">

A modern **computer's ability to store and reuse prerecorded sequences of commands makes it fundamentally different** from the simpler calculating machines that preceded it.

Prior to the invention of the first stored-program computer, all computing devices had to be manipulated by an operator or group of operators who manually entered a particular set of commands each time they wanted to perform a calculation.

### Refining the File-Clerk model

Let's take a look at the relationship between the code, data and results streams by means of an example:

The code stream consists of a single instruction, an `add`, which tells the ALU to add two numbers togethers.

The `add` instruction travels from code storage to the ALU. The ALU goes through the following sequence of steps:
1. Obtain the two numbers to be added (input operands) from data storage
2. Add the numbers
3. Place the results back into data storage.

This is **the basic manner in which all computers operate**. Computers are fed a sequence of instructions one by one, and in order to execute them, the computer must first obtain the necessary data, then perform the calculation specified by the instruction, and finally write the result into a place where the end user can find out.

In a modern CPU, these three steps are carried out a billion times per second.

To return back to the file-clerk analogy - a computer is like a file clerk who sits at his desk and waits for messages from his boss. Each message tells him to perform a calculation on a pair of numbers. The message tells him which calculation to perform and where in the filing cabinets the numbers are located. 

### The Register File

We'd like for the ALU to have quick access to the numbers it needs to operate on. This means storing the operands as close as possible to the ALU so it can read the operands almost instantaneously. 

Practical considerations like the CPU's limited surface area limit the size of the storage area we put next to the ALU. This means that in real life, **most computers have a relatively small number of very fast data storage locations attached to the ALU**.

These **storage locations are called registers**. The registers, which are arrayed in a storage structure called a **register file**, store only a small subset of the data that the code stream needs.

Building on the previous three step description of what goes on when a computer's ALU is commanded to add two numbers we can modify it to add a little more detail:

1. Obtain the two numbers to be added from two source registers.
2. Add the numbers.
3. Place the results back in a destination register.

### RAM: When Registers Alone Won't Cut it


In order to make a computer that does useful work, you need to be able to **store very large data sets**. This is where the computer's main memory comes in. **Main memory**, which is always some type of **random access memory (RAM)**, stores the data set on which the computer operates, and only a small portion of that data set at a time is moved to the registers for easy access from the ALU.

<img src="img/1_4.png">


Main memory is **situated a quite a bit farther way from the ALU than the registers**. The **ALU and the registers are an internal part of the microprocessor**, but main memory is a completely separate component.

Main **memory is connected to the microprocessor** via the **memory bus**.

If computers didn't have registers and the ALUs had to read data directly from memory the computations would be much slower.

### The File-Clerk Model: Part 3

We can think of main memory as a document storage room located on another floor and the registers as a small, personal filing cabinet where the file clerk places the papers on which he's currently working. The clerk doesn't really know anything about the document storage room -- what it is or where it's located -- because his desk and his personal filing cabinet are all that he concerns himself with. 

There is another office worker who is responsible for fetching the files in the storage room for the clerk. We can think of this office worker as a secretary. When the boss wants the clerk to work on a file that's not in the clerk's personal filing cabinet, the secretary must first be ordered, via a message from the boss to retrieve the file from the storage room and place it into the clerk's cabinet so the clerk can access it.

