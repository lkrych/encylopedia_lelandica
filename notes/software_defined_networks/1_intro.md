# Introduction to Software Defined Networks

## Table of Contents
* [Introduction](#introduction)
* [Terminology](#terminology)
* [Modern Data Centers](#modern-data-centers)
* [Traditional Switch Architecture](#traditional-switch-architecture)

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

## Modern Data Centers

Data centers are the organizational unit used to serve high volumes of traffic. They are composed of a very large number of servers arranged into organized rows of racks of servers. 

Over time, the demand for efficiency drove the migration of individual server computers into server blades, a stripped down server with a modular design optimized to minimize the use of physical space and energy. Racks of **blades are connected by Top-of-Rack switches**.

<img src="resources/data-center-network-topology.png">


Physical servers an conceivably host twenty virtual machines. With a data center of 100,000 servers, this can mean an internal network of 2,000,000 hosts!

So, let's paint a picture. In a traditionally-designed data center there are a large number of host computers that all communicate with each other via a set of communication protocols and networking devices designed to work over a large, disparate geographical area with unreliable communications. This isn't very efficient. 

The environment in a data center is much more stable than the world imagined when first developing networking technology.

Studies indicate that the majority of traffic in current data centers is **East-West traffic** (**traffic composed of packets sent from one host inside the data center to another host in the same data center**).

The protocols designed to achieve robustness in the geographically wide-dispersed Internet require that routers spend more than thirty percent of their CPU cycles rediscovering and recalculating routes for a network topology in a highly static data center.

## Traditional Switch Architecture

The various switching functions of a traditional switch are separated into three separate categories: **control, management, and data planes**. 

<img src="resources/device-planes.jpg">

The **vast majority of packets handled by the switch are by the data plane**. The **data plane consists of the various ports that are used for the reception and transmission of packets** and a **forwarding table** with its associated logic. The data plane assumes responsibility for **packet buffering, packet scheduling, header modification, and forwarding**. If an arriving packet's header is found in the forwarding table it will be subject to some header modification and then forwarded out without the intervention of the other planes.

Not all packets can be handled this way. Sometimes this is simply because their information is not yet entered into the table, or because they belong to a control protocol that must be processed by the control plane.

The **control plane's principal role is to keep current the information in the forwarding table** so that the data plane can independently handle as high a percentage of traffic as possible. The control plane is **responsible for processing a number of different control protocols** that may affect the forwarding table. 

These protocol are sufficiently complex to use general purpose microprocessors and accompanying software in the control plane, whereas the **data plane logic can be crafted entirely in silicon**.

Network administrators configure and monitor the switch through the management plane, which in turn extracts information or modifies data in the control and data planes as appropriate.

### Software-based Routing and Bridging

Back in the good ol' days most routers were just general purpose Unix computers running software that inspected a packet that arrived on one interface and looked up the destination IP address in some efficiently searched data type like a tree or a hash. This data structure was called the **routing table**. Based on the entry found in the routing table, the packet would be transmitted on the indicated outbound interface.

Demand for increased speed led to improvements in media speed, which in turn made it necessary to increase the speed of the router and bridge platforms. This led to the development of hardware lookup.

### Hardware Look-up Forwarding Tables

