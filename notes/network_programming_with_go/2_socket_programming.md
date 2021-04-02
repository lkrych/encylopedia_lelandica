# Socket Programming

## Table of Contents

## Reliable TCP Streams

TCP allows a computer to reliably stream data between nodes on a network. Go's stdlib allows programmers to write robust TCP-based network applications.

### Reliability and flow control

TCP is **reliable** because it was built to **handle packet loss and receiving packets out of order**. Packet loss can occur because of data transmission errors or network congestion. 

Routers are computers that handle the transfer of packets from node to node. They, like all computers, have a limited memory, and they use this memory to temporarily store packet info before forwarding traffic out of the correct port. If a network link is oversubscribed/congested, it means that the router is unable to keep up with the pace of incoming packets. When a router runs out of memory, it starts to discard packets.

One interesting thing about **TCP** is that it **adapts its data transfer rate** to make sure it transmits data as fast as possible while keeping dropped packets to a minimum even if the network conditions change. This process is called **flow control**.

TCP also **keeps track of received packets and retransmits unacknowledged packets**. Recipients can receive packets out of order and TCP will handle putting them in the correct order.

### TCP Sessions

A **TCP session** allows a computer to **deliver a stream of data of any size** to a recipient and **receive confirmation** that the recipient received the data.

You can think of a session as a conversation between two nodes. One node sends data, the other acknowledges that it has received the data so that the sending node can correct any errors in real time.

TCP sessions are established with a **three-way handshake**. The handshake will create an established TCP session.

<img src="./1_image/three_way_handshake.png">

Before a server can establish a TCP session, it must **listen for incoming connections**.

As the first step of the handshake, the client sends a packet with the **synchronize (SYN) flag**.