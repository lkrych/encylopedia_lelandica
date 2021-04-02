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

<img src="./2_image/three_way_handshake.png">

1. Before a server can establish a TCP session, it must **listen for incoming connections**.
2. As the first step of the handshake, the client sends a packet with the **synchronize (SYN) flag**. The SYN packet informs the server of the **client's capabilities and preferred window settings** (size of buffer to send).
3. The server will respond with a packet with the **acknowledgement (ACK) and synchronization (SYN) flags** set. The ACK flag tells the client that the server acknowledges receipt of the client's SYN packet. The **server's SYN packet tells the client what settings it has agreed to** for the conversation.
4. The client replies with an ACK packet to acknowledge the server's SYN packet.

Completion of the three-way handshake **establishes the TCP session**, and nodes may then exchange data. The TCP session remains idle until either side has data to transmit. Unmanaged and lengthy TCP sessions may result in wasteful consumption in memory, in fact, this is the vector of some cybersecurity attacks. An attacker will attempt to create numerous TCP sessions with your server without the intent of sending data just to limit your ability to server other clients.

### Sequence Numbers

Each TCP packet contains a **sequence number**, which the receiver **uses to acknowledge receipt of each packet** and to **properly order the packets** for presentation.

<img src="./2_image/seq_nums.png">

A client's operating system (OS) determines the initial sequence number and sends it to the server during the handshake. The server acknowledges receipt of the packet by including the sequence number plus 1 in its ACK packet. Similarly, the server will include its own sequence number in its SYN packet.

The ACK packet uses the sequence number to **tell the sender that it has received all packets up to and including the packet** with this sequence number. You might notice **selective acknowledgements (SACKs)** being exchanged. These are ACK packets used to acknowledge the receipt of a subset of sent packets.