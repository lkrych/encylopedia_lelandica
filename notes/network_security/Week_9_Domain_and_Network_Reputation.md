# Week 9 Domain and Network Reputation

Domain and Network Reputation videos

Reading - Building a Dynamic Reputation System for DNS

Reading - Detecting Malware Domains at the Upper DNS

**Domain and Network Reputation Lectures**

**

**

Blacklists are a traditional defense against Spam attacks in email systems. The problem with them is that they are static, and that spammers can always use a new IP if their original IP has been blacklisted.

How would we create a Dynamic Block list? One idea is to analyze DNS traffic. 

* Botnets typically have short-lived domains
* Spyware typically uses anonymously registered domains
* Adware typically uses disposable domains not related to legitimate businesses.

**NOTOS** is a system that dynamically assigns a reputation score for domain names.

**KOPIS** is a system that analyzes DNS queries at Authoritative or Top-Level domain servers.

![668ad3ac2162d45c5c5abb992e628b48.png](image/668ad3ac2162d45c5c5abb992e628b48.png)

* Resource Record (RR) - a tuple of domain name and IP address
* 2nd Level Domain, 3rd Level Domain - 2LD =

NOTOS Statistical Features

![4257456a0c9d8a0829e4dd8874d07f80.png](image/4257456a0c9d8a0829e4dd8874d07f80.png)

![7b8996407399e583c803b7b2505b1446.png](image/7b8996407399e583c803b7b2505b1446.png)
