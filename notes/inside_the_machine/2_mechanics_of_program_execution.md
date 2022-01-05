# Mechanics of Program Execution

## Table of Contents

### Opcodes and Machine Languages

Both memory addresses and instructions are ordinary numbers that can be stored in memory. All of the instructions in a program are represented inside the computer as list of numbers. Indeed, a program is one long list of numbers stored in a series of memory locations.

So how is a program like 

<img src="image/1_program_1.png">

rendered in numerical notation so that it can be stored in memory and executed by the computer?

A computer actually only understands 1s and 0s (more precisely high and low electric voltages), not English words like `add`, `load`, and `store` or letters and base-10 numbers like A,B, 12, and 13.

In order **for a computer to run a program** all of its **instructions must be rendered in binary notation**.

### Machine Language on the DLW-1

The translation of programs of any complexity into binary-based machine language is a massive undertaking that's meant to be done by a computer, but we will look at the basics nonetheless.

The English words in a program like `add`, `load`, and `store`are **mapped to strings of binary numbers called opcodes**. Each opcode designates a different operation that the processor can perform.


<img src="image/2_opcode.png">

The binary values representing both the opcodes an the register codes are arranged in one of a number of 16-bit formats to get a complete machine language instruction, which is a binary number that can be stored in RAM and used by the processor. Let's look at some examples.

### Binary Encoding of Arithmetic Instructions

Arithmetic instructions have the simplest machine language instruction formats. The following figure shows the format for the machine language encoding of a *register-type* arithmetic instruction (an arithmetic instruction that uses only registers and no immediate values).

<img src="image/2_1.png">

In a register-type arithmetic instruction, the first bit of the instruction is the **mode bit**. If this bit is set to 0, then the instruction is a register-type. If it is set to 1, then the instruction is of immediate type.

Bits 1-3 of the instruction specify the opcode which tells the computer what type of operation the instruction represents.

Bits 4-5 specify the instruction's first source register.

Bits 6-7 specify the second source register.

Bits 8-9 specify the destination register.

The last six bits are not needed by the register-to-register arithmetic instructions, so they are padded with 0s.

Let's use some of the binary-values in the tables introduced earlier to create some machine-language instructions.

<img src="image/2_mli.png">

Arithmetic instructions containing an immediate value use an *immediate-type* instruction format. In the immediate-type format, the first byte contains the opcode, the source register, and the destination register, while the second byte contains the immediate value.

<img src="image/2_2.png">

Here are a few immediate-type arithmetic instructions translated from assembly language to machine language.

<img src="image/2_mli_imm.png">

### Binary Encoding of Memory Access Instructions

Memory-access instructions use both register and immediate-type instruction formats exactly like those for arithmetic instructions. The only difference is in how they use them.

#### Load Instruction

An immediate-type `load` uses the immediate-type instruction format, but because the `load`'s source is an immediate value (a memory address) and not a register, the source field is unneeded and must be zeroed out.

<img src="image/2_3.png">

Now let's translate it into the machine language instruction.

<img src="image/2_mli_load.png">

The first byte corresponds to an immediate-type `load` instruction that takes register A as its destination. The second byte is the binary representation of the number 12, which is the source address in memory that the data is to be loaded from.

The second type of load we've seen is the register type. The register-type load uses the register-type instruction format, but with the second source field zeroed out.

<img src="image/2_4.png">

The first source field specifies the register containing the memory address that the processor is to load data from, and the destination field specifies the register that the loaded data is to be placed in.

For a register-relative addressed `load`, we use a version of the immediate-type instruction format, with the base field specifying the register that contains the base address and the offset stored int he second byte of the instruction.

<img src="image/2_5.png">

#### The store instruction

The register-type binary format for a `store` instruction is the same as it is for a `load` except that the destination field specifies a register containing a destination memory address, and the source field specifies the register containing the data to be stored in memory.

The immediate-type machine language format for a store is also similar tot he immediate-type format for load, except that since the destination register is not needed (the destination is the immediate memory address), the destination field is zeroed out, while the source field specifies which register holds the data to be stored.

<img src="image/2_6.png">

The register-relative `store`, on the other hand, uses the same immediate-type instruction format used for the register-relative `load`, bu the destination field is set to a nonzero value, and the offset is stored in the second byte. 

### Translating an Example Program into Machine Language