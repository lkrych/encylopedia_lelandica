# Introduction to Software Defined Networks

## Table of Contents
* [Introduction]()
* [Terminology]()

## Introduction

**Software Defined Networking** (SDN) is a novel **way to program the switches utilized in modern data networks**. It is a move towards centralized network control architecture, and it is well suited to large networks prevalent at data centers.

## Terminology

The **Data Link Layer** is the second lowest layer of the OSI model (behind the physical layer). This layer **provides the capability to transfer data from one device to another on a single network segment**. The link layer includes
    1. mechanisms to detect sequencing errors or bit errors that might occur during transmission.
    2. mechanisms for flow control between the sender and receiver across the network segment.
    3. a multiplexing ability to allow multiple network protocol to use the same communication medium.
These three functions are considered to be part of the **logical link control component** of the data link layer. The remaining functions of the data link layer are part of the **media access control component** **(MAC)**. The MAC layer is the part of the data link layer that **controls when a shared medium may be accessed and provides addressing** in the case that multiple receivers will receive the data yet only one should process it.

The **Network Layer** provides the **functions and processes that allow data to be transmitted from sender to receiver across multiple intermediate networks**. To transit each intermediate network involves the data link layer processes described above.

A **switch** is a **device that receives information on one of its ports and transmits that information out one or more of its other ports**. Switches come in two flavors:
    1. A **circuit switch** is a switch where contextual **information specifying where to forward the data belonging to a circuit is maintained** in the switch for a prescribed duration. This context is established either by configuration or by a call/connectionn set-up specific to the type of search.
    2. A **packet switch** is a switch where the **data comprising the communication between two or more entities is treated as individual packets that each make their way independently** through the network toward the destination. Packet switches can be **connection-oriented or connectionless**.
        1. In a **connection-oriented model**, there is some context information residing in intermediate switches that allows the switch to forward the data to its destination.
        2. In a **connectionless model** there is sufficient data within a packet such that each intermediate switch can forward the data toward its destination without any context have been established about that data.

A **router** is **a packet switch used to separate subnets**. A subnet is a network consisting of a set of hosts that share the same network prefix. A network prefix consists of the most significant bits of the IP address. A prefix may be of varying length. Usually all the hosts on a subnet reside on the same LAN>

The term **line rate** refers to the **bandwidth** of the communication medium connected to a port on a switch. When we say that a switch handles packets at line rate, this means it is capable of handling a continuous stream of packets arriving on that part at that bandwidth.