# The Processor

## Table of Contents

### Introduction

The performance of a computer is determined by three factors:
1. Instruction count
2. Clock cycle time
3. Clock Cycles per Instruction (CPI)

The compiler and Instruction Set Architecture (ISA) determine the instruction count required for a given program. The implementation of the processor determines both the clock cycle time and the number of clock cycles per instruction.

#### A Basic MIPS Implementation

We will be examining an implementation that includes a subset of the core MIPS instruction set:

* The memory-reference instructions `load word(lw)` and `store word (sw)`.
* The arihmetic-logical instructions `add`, `sub`, `AND`, `OR`, and `slt` (set on less than sets the destination register's content to the value 1 if the first source register's value is less than the second source register's value) 
* the instructions `branch equal (beq)` and `jump (j)`

This set illustrates the key principles used in creating a datapath and designing the control.

#### An Overview of the Implementation

For every instruction, the first two steps are identical:

1. Send the program counter (PC) to the memory that contains the code and fetch the instructions from memory.
2. Read one or two registers, using fields of the instruction to select the registers to read. For the load word instruction, we need to read only one register, but other instructions require reading two registers.

After these two steps, the actions required to complete the instruction depend on the instruction class. All instruction classes, except `jump`, use the Arithmetic Logic Unit (ALU) after reading the registers.
* The memory-reference instructions use the ALU for an address calculation
* The arithmetic-logical instructions for the operation execution
* The branches for comparison

After using the ALU, the actions required by the classes differ.
* The memory-reference instruction will need to access the memory either to read data for a `load` or write data for a `store`.
* The `arithmetic-logical` or `load` instruction must write the data from the ALU to memory back into a register
* The branch may need to change the next instruction address based on the comparison, otherwise the PC will be incremented by 4 to get the address of the next instruction

Let's take a high-level look at the MIPS implementation:

<img src="image/4_1.png">

Although this figure shows most of the flow of data, it omits two aspects of the instruction execution:

1. In several places **the figure shows data going to a particular unit as coming from two different sources**. For example, the value written into the PC canc ome from one of two adders, the data written into the register file can come from either the ALU or data memory. **In practice, these data lines cannot be wired together**, we must add a logic element that chooses from among the sources and steers one to its destination. This selection is commonly **done with a device called a multiplexor**, which selects from several inputs based on a control line.
2. The second omission is that several of **the units must be controlled depending on the type of instruction**. For example the data memory must read on a `load` and `write` on a store.

Let's take a look at the data path with the three required multiplexors added, as well as the control lines for the major functional units:

<img src="image/4_2.png">

The top multiplexor controls what value replaces the PC(PC+4 or the branch destination address). This multiplexor is controlled by the gate that "ANDs` together the Zero output of the ALU and a control signal that indicates that the instruction is a branch.

The middle multiplexor, whose output returns the register file, is used to steer the output of the ALU (in the case of an arithmetic-logical instruction) or the output of the data memory (in the case of a `load`) for writing into the register file.

The bottommost multiplexor is used to determine whether the second ALU input is from the registers (for an arithmetic-logical instruction or branch) or from the offset field of the instruction (for a `load` or `store`). 

The other control lines determine the operation performed by the ALU, whether the data memory should read or write, and whether the registers should perform a write operation.

We will now explore using a single long clock cycle for every instruction. This means that every instruction will begin execution on one clock edge and complete execution on the next clock edge.

This approach is not practical, since the clock cycle must be severely stretched to accommodate the longest instruction. After designing the control for this simplistic example, we will look at pipelined implementation.

### Logic Design Conventions

To discuss the design of a computer, we  must decide how the hardware logic implementing the computer will operate and how the computer is clocked.

The datapath elements in the MIPS implementation consist of two different types of logic elements:
1. elements that **operate on data values**
2. elements that **contain state**

The elements that operate on data values are all **combinational**, which means that their outputs depend only on the current inputs. Given the same input, a combinational element will always produce the same output because it has no internal storage.

Other elements in the design are not combinational, but instead contain state. An element contains state if it has some internal storage. These are called **state** elements. In the figure above, the instruction and data memories are all examples of state elements.

State elements have at least two inputs and one output. The **required inputs** are the **data value to be written into the element** and **the clock**, which **determines when the data value is to be written**. The output from a state element provides the value that was written in an earlier clock cycle. A state element can be read at any time, it is not controlled by the clock input.

Logic components that contain state are called **sequential**, because their **outputs depend on both their inputs and the contents of the internal state**.

#### Clocking Methodology

A **clocking methodology** defines **when signals can be read and when they can be written**. It is important to specify the timing of reads and writes, because if a signal is written as the same time it is read, the value of the read could correspond to the old value, the newly written value, or some mix of the two! Clocking methodology **is designed to make hardware predictable**.

For simplicity, we will assume an **edge-triggered clocking methodology**. This means that **any values stored in a sequential logic element are updated only on a clock edge**, which is a **quick transition form low to high**, or vice-versa.

Because only state elements can store a data value, any collection of combinational logic must have its inputs come from a set of state elements and its output written into a set of state elements. The inputs are values that were written in a previous clock cycle, while the outputs are values that can be used in a following clock cycle.

<img src="image/4_3.png">

The figure above shows the two state elements surrounding a combinational logic block, which operates in a single clock cycle. All signals must propagate from state element 1, through the combinational logic, and to state element 2 in the time of one clock cycle.

For simplicity, a write control signal is not shown. A **control signal** is **used for multiplexor selection** or for **directing the operation of a functional unit**.  A control signal contrasts with a **data signal**, which **contains information that is operated on by a functional unit**.

In reality, both the clock signal and the write control signal are inputs, and the state element is only changed when the write control signal is asserted and the clock edge occurs. The word asserts is used to mean that the signal is logically high and deasserted to represent logically low.

An edge-triggered methodology allows us to read the contents of a register, send the value through some combinational logic, and write that register in the same clock cycle.

For the 32-bit MIPS architecture, nearly all of these state and logic elements **will have inputs and outputs that are 32 bits wide**, since that is the width of most of the data handled by the processor. The figures will indicate buses that are wider than 1 bit with thicker lines.

### Building a Datapath