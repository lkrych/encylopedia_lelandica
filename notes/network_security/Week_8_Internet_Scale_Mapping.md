# Week 8 Internet Scale Mapping

** Quiz 8 - October 28**

**Project 4 - November 5**

**Internet Scale Mapping Lectures**

**Footprinting** - The attacker gathers information about a target. The kind of information gathered is: DNS, email servers and the IP address range.

**Scanning** - The attacker uses the internet to obtain information on specific IP addresses. The kind of information gathered is O.S, services, and architecture of the target system

**Enumeration** - the attacker gathers information on network user and group names, routing tables and simple network management protocol.

Internet-wide studies are hard to pull off. They take a lot of computing resources and time. **Zmap** is an open-source network scanner that can scan a single port of every machine on the internet in under an hour.

![Screen_Shot_2019-10-18_at_3-31-33_PM.png](image/Screen_Shot_2019-10-18_at_3-31-33_PM.png)

How does Zmap scan the entire internet without keeping track of all that it has scanned? It scans hosts according to a random permutation.

![a0afb0238f8bcca7f5b0de7616c271ab.png](image/a0afb0238f8bcca7f5b0de7616c271ab.png)

The only state we need to keep track of is:

* The primitive root
* The current location
* The first address (getting back to this suggests we have iterated through the entire space)

![7d65b4f9f10cbfebcbf76cbd17ea9ce5.png](image/7d65b4f9f10cbfebcbf76cbd17ea9ce5.png)

How do we validate responses from targets that are being probed by our internet-wide scanner?

One way is to encode secrets into mutable fields of probe packets that will have recognizable effects on responses. 

![ac19cae89f9c6cb6201655a37b9f6c4d.png](image/ac19cae89f9c6cb6201655a37b9f6c4d.png)

ZMap high level process

![3344868218bb08c22ed2325749041681.png](image/3344868218bb08c22ed2325749041681.png)

![887f00a4b1f6948ac3b35078c9655dba.png](image/887f00a4b1f6948ac3b35078c9655dba.png)

Statelessness leads to increased performance and coverage. 

**Entropy** is randomness for use in cryptography or other applications that require random data.  The two sources of entropy are hardware sources and randomness generators. A lack of entropy will have a negative impact on performance and security.

Studies have shown that of the many public keys that are online, a lot of them are not distinct. This can sometimes be due to underpowered entropy in the algorithms. This leads to ways to uncover the keys. 

![ee19532be0355567ccef53495f3c3aa0.png](image/ee19532be0355567ccef53495f3c3aa0.png)

![ffc4a20ba9bc73002a5bd4f455aea9a6.png](image/ffc4a20ba9bc73002a5bd4f455aea9a6.png)

One problem with this setup is that many linux systems don't support the inputs that lead to the entropy generation. Think servers in a rack. 

![79841306c06aac48f711a4dce5099147.png](image/79841306c06aac48f711a4dce5099147.png)

How are certificates used in web browsers?

![fac9968e7e7f573315112fdb45b6896f.png](image/fac9968e7e7f573315112fdb45b6896f.png)

The client validates the certificate chain by validating all the keys that exist in the chain. 

![8b6ee92a37f69820fb8b71cc84e3ed30.png](image/8b6ee92a37f69820fb8b71cc84e3ed30.png)

![2c88d242da38018c5cdf9a2aa7b8d91f.png](image/2c88d242da38018c5cdf9a2aa7b8d91f.png)
