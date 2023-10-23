# Numeric Representation

## Introduction

High-level languages shield programmers from the pain of dealing with numeric representation. Writing great code, however, requires that you understand how computers represent numbers. This is because that this is fundamentally what the underlying hardware is operating on.

Why should you care whether a sequence of symbols like "100" is the value one hundred or just a representation of it? There are many different representations and that sequence of symbols could easily be equivalent to the value of 4.

## Numbering Systems

A **numbering system** is a mechanism we use to represent numeric values. Today, most people use the decimal (base-10) numbering system, and most computer systems use the binary (base-2) numbering systems.

The decimal system uses **positional notation** which gives meaning not only to the symbol itself, but also the position of the symbol in the sequence. 

<image src="images/2_positional.png">

A scheme that doesn't have positional representation is tallying. You can count right to left and left to right, and you will always get the same value. This is bulky and requires a large amount of space to represent numbers.

## Radix values

The decimal positional numbering system uses powers of 10 and 10 unique symbols for each digit position. by substituting a different set of numeric digits and multiplying those digits by powers of some base other than 10, we can devise a different numbering system.

The **base** or **radix** is the value that we raise to successive powers for each digit to the left of the **radix point**.

To create a base-`n`` numbering system, you need `n` unique digits. The smallest possible radix is 2.

### The Binary Numbering system

Why even worry about binary? Almost every computer language allows programmers to use decimal notation (automatically converting to binary under the hood). Despite this capability, **most modern computer systems talk to I/O devices using binary, and their arithmetic circuitry operates on binary data**.

### Converting between Decimal and Binary Representation

```python
def int_to_bin(n):
    val = ""
    if n % 2 == 0:
        val += "0"
    else:
        val += "1"
    while n > 0:
        n = n//2
        if n % 2 != 0:
            val = "1" + val
        else:
            val = "0" + val
    return val
```

### Hexadecimal Numbering system

Binary numbering is verbose, hexadecimal representation offers two great features:
1. it is very compact
2. it is easy to convert between binary and hex

<image src="images/2_hex_chart.png">

To convert the hex representation of a number into binary, use the table above to substitute the corresponding 4 bits for each hex digit.

To convert the binary representation into a hex, first pad the binary number with 0s to make sure it is a multiple of 4 bits. Next separate the value into groups of 4 bits. Finally look up these values in the table.

## Numeric/String Conversions

All programming languages perform string to integer conversions. Unfortunately, if you have no idea the cost of doing this translation you won't realize how they can impact your program when performance is critical.

Let's look at an example

### Converting a decimal string into a decimal

```python
def s_to_i(s):
    val = 0
    for c in s:
        val = val * 10 + int(c) #lookup ascii value in table
    return val
```

Notice the we have to operate on each digit!

Converting an integer into a string is even more complicated because we need to divide. 

```python
def i_to_s(i):
    val = ""
    while i > 0:
        rem = str(i % 10)
        i = i // 10
        val = rem + val
    return val
```

The important thing here is to notice that **we have to operate on each character, and division is slow**.

To write great code, **you don't need to avoid using numeric/string conversions altogether**, however a great programmer will take care to use them only as necessary. 

## Internal Numeric Representation

Most modern computer systems use an internal binary format to represent values and other objects. However, most systems can only efficiently represent binary values of a given size. In order to write great code, you need to make sure that your programs use data objects that the machine can represent efficiently.