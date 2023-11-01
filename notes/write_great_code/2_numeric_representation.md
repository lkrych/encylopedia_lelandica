# Numeric Representation

## Table of Contents
* [Numbering Systems](#numbering-systems)
* [Radix values](#radix-values)
* [The Binary Numbering system](#the-binary-numbering-system)
* [Converting between Decimal and Binary Representation](#converting-between-decimal-and-binary-representation)
* [Hexadecimal Numbering system](#hexadecimal-numbering-system)
* [Numeric/String Conversions](#numericstring-conversions)
    * [Converting a decimal string into a decimal](#converting-a-decimal-string-into-a-decimal)
* [Internal Numeric Representation](#internal-numeric-representation)
    * [Signed and Unsigned Numbers](#signed-and-unsigned-numbers)
    * [Useful properties of binary numbers](#useful-properties-of-binary-numbers)
    * [Sign Extension, Zero Extension, Contraction](#sign-extension-zero-extension-contraction)
    * [Saturation](#saturation)
    * [Fixed point representation](#fixed-point-representation)
    * [Scaled Numeric Formats](#scaled-numeric-formats)

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

Most computer systems only allow you to work with bit strings of certain fixed lengths:
* a **nibble** is 4 bits
* a **byte** is 8 bits.  A byte is the smallest addressable data item on many CPUs, this means that the C**PU can efficiently retrieve data in groups of 8 bits from memory**.

Because the byte is the smallest unit of storage on most machines, and many languages uses bytes to represent objects that require fewer than 8 bits, we need a way of denoting individual bits within a byte. To describe bits within a byte, we can use bit numbers. Bit 0 is the low order (LO) or least significant bit. Bit 7 is the high-order (HO) or most-significant bit. 

Let's look at an example that uses two bytes:

<image src="images/2_byte.png">

Most CPUs efficiently handle objects up to a certain size (typically 32 or 64 bits in contemporary systems). That doesn't mean you can't work with larger objects, only that it is less efficient to do so.

## Signed and Unsigned Numbers

How are negative numbers represented in binary? To **represent signed values**, most computer systems use the **two's complement numbering system**. 

With `n` bits, we can represent 2^`n` different objects. Because negative values are objects in their own right, we have to **divide these** 2^`n` **combinations between negative and non-negative values**.

In general, with `n` bits, we can represent the signed values in the range -2^`n-1` + 2^`n-1`.

The two's complement system uses the **HO bit** as a **sign bit**. If the HO bit is 0, the number is non-negative and has the usual binary encoding, if the HO bit is 1, the number is negative and uses the two's complement encoding.

To negate a number, you can use the two's complement operation:
1. invert all the bits in the numbers.
2. add 1 to the inverted result. 

If the result is negative, then this is the two's complement form of the non-negative value. Let's look at an example of negating 5.

1. %0000_0101  5 (in binary)
2. %1111_1010  Invert all the bits
3. %1111_1011  Add 1 to obtain -5

To read a number in two's complement, **add all the digits like you would in a normal representation but then subtract the value represented by the HO bit.**

```
%1111_1011 = -5

-128 + 64 + 32 + 16 + 8 + 2 + 1 = -5
```

Let's do take -5 and negate it

1. %1111_1011  -5 (in binary)
2. %0000_0100  Invert all the bits
3. %0000_0101  Add 1 to obtain 5

One thing to note here is that you cannot negate the smallest negative value in the two's complement system.

## Useful properties of binary numbers

1. If a bit position 0 of a binary value contains 1, the number is an **odd number**, if this bit contains 0, **the number is even**. 
2. If the LO n bits of a binary number all contain 0, then the number is evenly divisible by 2^n.
3. Shifting all the bits in a number to the left by one position multiplies the binary value by 2.
4. Shifting all the bits of an unsigned binary number to the right by one position effectively divides the number by 2. 
5. Inverting all the bits in a binary number is the same thing as negative the value and then subtracting by 1

## Sign Extension, Zero Extension, Contraction

With the two's complement system, **a single negative value is represented differently depending on the size of the representation** (because the HO bit has to be subtracted).

This conversion and its converse are known as **sign extension** and **contraction** operations.

Let's look at an example: the value -64. The 8-bit two's complement representation for this number is `$C0`. The 16-bit equivalent is `$FFC0`.

Now consider the value +64. The 8-bit value is `$40` and the 16-bit is `$0040`. **We extend the size of negative values differently than we extend the size of non-negative values.** 

To **sign-extend** a value, **copy the sign bit into the additional HO bits in the new format**. 

So, for example, to sign-extend an 8-bit number to a 16-bit number, copy bit 7 of the 8-bit number into the bits 8 through 15 of a 16-bit number.

<image src="images/2_sign_extension.png">

**Zero extension** converts small unsigned values to larger unsigned values,  it is very easy, just store 0s in the HO bytes of the larger operand.

<image src="images/2_zero_extension.png">

The important thing to remember here is that converting between different sizes isn't always free. This means you **should be careful when mixing variables of different sizes within the same arithmetic expression**.

**Sign Contraction** is converting a value with some number of bits to the same value with a fewer number of bits. To properly sign contract, you must look at the HO byte(s) that you want to discard:
1. The HO bytes must all contain either `0` or `$FF`
2. The HO bit of your resulting value must match every bit you've removed from the number.

<image src="images/2_sign_contraction.png">

## Saturation

You can also reduce the size of an integer value through **saturation**, which is useful when **you're willing to deal with loss of precision**.

To convert a value via saturation, **you copy the LO bits of the larger object into the smaller object**. If the **larger value is outside the smaller object's range**, then you clip the larger value by **setting the smaller object to the largest value within the smaller value's range**.

For example when converting a 16-bit integer to an 8-bit integer, if the 16-bit value is in the range -128 through +127 you can copy the LO byte to the 8-bit object. 

If the 16-bit signed value is greater than 127 you store 127 into the 8-bit object, likewise if it is less than -128, you store -128. 

## Fixed point representation

There are two ways computer systems commonly represent numbers with fractional components: **fixed point representations and floating-point representations**. 

When using fixed-point binary format, **you choose a particular bit in the binary representation and implicitly place the binary point before that bit**. You choose the bit based on the number of significant bits you require in the fractional portion of the number.

One issue with fixed point representation is that you lose precision. You cannot exactly represent 1.3 with this format.


## Scaled Numeric Formats

**Scaled numeric forma**t combines the exact representations of certain decimal fractions with the precision of binary format.  In this strategy you convert your fraction components to whole numbers, operate on the whole numbers and then convert back tot he fractional representation.