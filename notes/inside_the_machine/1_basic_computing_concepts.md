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