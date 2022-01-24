# Pipelined Execution

## Table of Contents

### Introduction

**Pipelined execution** is a technique that enables microprocessor designers to **increase the speed at which a processor operates**.

This chapter will first introduce the concept of pipelining with a factory analogy. This chapter focuses solely on the execution of arithmetic instructions. Memory and branch instructions use the same fundamental principles, but their pipelining is explored more in further chapters.

## The Lifecycle of an Instruction

In the previous section, you learned that a computer repeats three basic steps over and over again in order to execute a program:

1. **fetch** the next instruction from the address stored in the program counter and load that instruction into the instruction register. Increment the program counter.
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

1. **fetch** the next instruction from the address stored in the program counter and load that instruction into the instruction register. Increment the program counter.
2. **decode** the instruction in the instruction register (determine what instruction is to be performed).
3. **execute** the instruction in the instruction register. Because the instruction is not a branch instruction but an arithmetic instruction, send it to the ALU.
    1. Read the contents of registers A and B
    2. Add the contents of A and B
4. **Write** the result back to register C. 

In a modern processor, these four steps are repeated over and over again until the program is finished executing. These are the **four stages in the classic RISC pipeline**. Think of a pipeline as a series of stages that each instruction in the code stream must pass through when the code stream is executed. Here are the four stages in an abbreviated form:

1. Fetch
2. Decode
3. Execute
4. Write

Each of these stages can be said to represent one phase in the lifecycle of an instruction. **Each phase takes a fixed but by no means equal amount of time.**

## Basic Instruction Flow

One useful division that computer architects often employ when talking about CPUs is that of the **front end versus the back end**. 

When instructions are fetched from main memory, they must be decoded for execution. This **fetching and decoding** takes place in the **processor's front end**. 

<img src="image/3_1.png">

The front end roughly corresponds to the control and I/O units. The ALU and registers constitute the back end. Below is a figure that shows all four phases of the processor execution.

<img src="image/3_2.png">

For the rest of the chapter, we are going to focus primarily on the code stream, on how instructions enter and flow through the microprocessor. This means we will leave out the data and results streams.

<img src="image/3_3.png">

## Pipelining Explained

To explain pipelining, we will use a factory analogy. Let's say we want to build an automotive manufacturing business. In the spirit of our Lord Ford, we determine there are five stages to build our first product, a truck:

1. Build the chassis
2. Drop the engine into the chassis
3. Put the doors, hood, and coverings on the chassis
4. Attach the wheels
5. Paint the truck

Each of these stages requires the use of highly trained workers with very specialized skill sets. So when we make our first attempt at putting together our factory, we hire and train five crews of specialists, one for each stage of the process. Because the crews are so specialized and efficient, each stage takes exactly one hour to complete.

The first attempt at organizing this labor was to do one truck at a time. First the chassis team builds the chassis, while they are doing this the engine folk clock in, the chassis team hands it off to the engine folks and then they go on break. The engine folk do their work for an hour, and sometime during this work, the doors, hood and coverings team clocks in. Etc, you see how this pattern goes.

The truck moves down the line through all five stages in this way with only one crew working on one stage at any time. At this rate, it takes exactly five hours to finish a single truck, and our factory completes one truck every five hours.

<img src="image/3_4.png">

The most intuitive way to go about increasing our factory's truck completion rate is to try and decrease the production time for each truck. IF we can get the crews to work twice as fast, our factory can produce twice as many trucks in the same amount of time. Unfortunately, our specialists are already working as fast as they can. 

Since we can't speed up our teams, we can always hire a new assembly line, this doubles our completion rate. However, this isn't very scalable.

The solution is a revised work flow

1. the chassis team builds a chassis
2. once the chassis is complete, they send it to the engine folk
3. the engine folk receive the chassis while the chassis team receives a new chassis
4. the engine folk pass along their product to the coverings team, and they receive a new chassis.

Visually, the workflow looks like this:

<img src="image/3_5.png">

With this strategy, the crews can work simultaneously. If we can keep the assembly line full, we can produce a truck every hour. A fivefold improvement in the completion rate. This idea is called **pipelining**. While the total amount of time each individual truck spends in production has not changed, the rate at which the factory completes the trucks has increased drastically.

## Applying the Analogy

Let's look back at microprocessors now. We should think about using this same technique in the four phases of an instruction's lifecycle. Microprocessor designers are always looking for ways to increase the number of instructions a CPU can complete.

### A Non-pipelined processor

The previous chapter briefly described how simple processors use the clock to time internal operations.

These non-pipelined processors work on one instruction at a time, moving each instruction through all four phases of its lifecycle during the course of a one clock cycle. This is why non-pipelined processors are called single cycle processors. Because all instructions take one clock cycle to execute.

Because the processor completes instructions at a rate of one per clock cycle, you want the CPU's clock to run as fast as possible. To do this you need to calculate the maximum amount of time it takes to complete an instruction (remember not all instructions take the same time to execute) and make the clock cycle equivalent to this length of time.

<img src="image/3_6.png">

In the figure above, the blue instruction leaves the code storage area, enters the processor, and then advances through the phases of the lifecycle until at the end of the fourth nanosecond, it completes the last phase and its lifecycle is over.

The end of the fourth nanosecond is also the end of the first clock cycle, so now the red instruction can enter the processor at the start of the new clock cycle. After a total of 16 ns, the processor has completed all four instructions at a rate of .25 instructions/ns.

These types of processors are simple to design, but they waste a lot of resources.

### A pipelined processor

Pipelining a processor means breaking down its instruction execution process into a series of discrete pipeline stages that can be completed in sequence by specialized hardware. Because an instruction's lifecycle consists of four fairly distinct phases, you can start by breaking down the single-cycle processor's instruction execution process into a sequence of four discrete pipelined stages.

1. Fetch the instruction from storage
2. Decode the instruction
3. Execute the instruction
4. Write the results to the register file

The number of pipeline stages is called the **pipeline depth**. Let's say that each of these stages takes 1 ns to complete.

<img src="image/3_7.png">

At the start of the fifth nanosecond, the pipeline is now full, and the processor can begin completing instructions at a rate of one instruction per nanosecond. This is a fourfold improvement over the previous example.

### Shrinking the clock