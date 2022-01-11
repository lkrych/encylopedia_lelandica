# Pipelined Execution

## Table of Contents

### Introduction

**Pipelined execution** is a technique that enables microprocessor designers to **increase the speed at which a processor operates**.

This chapter will first introduce the concept of pipelining with a factory analogy. This chapter focuses solely on the execution of arithmetic instructions. Memory and branch instructions use the same fundamental principles, but their pipelining is explored more in further chapters.

## The Lifecycle of an Instruction

In the previous section, you learned that a computer repeats three basic steps over and over again in order to execute a program:

1. **fetch** the next instruction from the address stored int he program counter and load that instruction into the instruction register. Increment the program counter.
2. **decode** the instruction in the instruction register (determine what instruction is to be performed).
3. **execute** the instruction in the instruction register.

The execute step itself consists of multiple sub-steps depending on the type of instruction being executed. In the case of an arithmetic instruction: `add A B C`:

1. Read the contents of registers A and B
2. Add the contents of A and B
3. Write the result back to register C.

Thus the expanded list of actions required to execute an arithmetic instruction is:

1. **fetch** the next instruction from the address stored int he program counter and load that instruction into the instruction register. Increment the program counter.
2. **decode** the instruction in the instruction register (determine what instruction is to be performed).
3. **execute** the instruction in the instruction register. Because the instruction is not a branch instruction but an arithmetic instruction, send it to the ALU.
    1. Read the contents of registers A and B
    2. Add the contents of A and B
    3. Write the result back to register C. 

Okay, so this isn't exactly right. Most modern processors treat sub-steps 3a and 3b as a group, while they treat 3c (the register write) as a separate step. Thus the list should actually look like:

1. **fetch** the next instruction from the address stored int he program counter and load that instruction into the instruction register. Increment the program counter.
2. **decode** the instruction in the instruction register (determine what instruction is to be performed).
3. **execute** the instruction in the instruction register. Because the instruction is not a branch instruction but an arithmetic instruction, send it to the ALU.
    1. Read the contents of registers A and B
    2. Add the contents of A and B
4. **Write** the result back to register C. 

In a modern processor, these four steps are repeated ove rand over again until the program is finished executing. These are the **four stages in the classic RISC pipeline**. Think of a pipeline as a series of stages that each instruction in the code stream must pass through when the code stream is executed. Here are the four stages in an abbreviated form:

1. Fetch
2. Decode
3. Execute
4. Write

Each of these stages can be said to represent one phase in the lifecycle of an instruction. **Each phase takes a fixed but by no means equal amount of time.**

## Basic Instruction Flow

One useful division that computer architects often employ when talking about CPUs is that of the **front end versus the back end**. 

When instructions are fetched from main memory, they must be decoded for execution. This **fetching and decoding** takes place in the **processor's front end**. 

<img src="image/3_1.png">

## Pipelining Explained

## Applying the Analogy