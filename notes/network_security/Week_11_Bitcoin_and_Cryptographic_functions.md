# Week 11 Bitcoin and Cryptographic functions

**Hash functions...**

* Are easy to compute
* Can compute message digest of data of any size
* Produce a fixed length output
* **One-way**
* Designed to be collision resistant

![cf6f250858b5ef1a78664d745d810113.png](image/cf6f250858b5ef1a78664d745d810113.png)

**Hash Pointe**r is a data structure that contains a pointer to where some info is stored (like a normal pointer), but also a cryptographic hash of the info that is stored. 

![0c2fc1442f7065a92494b4718f6ea1a8.png](image/0c2fc1442f7065a92494b4718f6ea1a8.png)

The hash allows us to** verify** that the data that is being pointed to **hasn't changed**.

The "**Block Chain**" is a linked list of Hash Pointers.

![988def2df18a3618d6e7cf74d7c82376.png](image/988def2df18a3618d6e7cf74d7c82376.png)

The genius of this setup is that modifying any piece of the block chain will require requisite changes to all the other components for it to be valid. 

With **Digital Signatures **only the owner of the private key can sign, but anyone can verify that the owner signed (because they can use the owners public key). 

![8a2bc65735626f617ce1a8b5d694fd23.png](image/8a2bc65735626f617ce1a8b5d694fd23.png)

The requirements for Digital signatures are that they can be verified and that you can't forge the signatures. 

Public Keys can be used as **identities**. 

![7286b99c418ba0a390b3a98289994c8c.png](image/7286b99c418ba0a390b3a98289994c8c.png)

How cryptocurrency is made: Goofycoin

There are two rules to goofy coin, Goofy can create new coins, and goofy gets to keep the coins.

Goofy computes the digital signature of the string CreateCoin[uniquecoinId] using his private signing key. Now anyone can verify with his public key that he created the coin.

![299c47aa7da7e6c210caff8b075ff331.png](image/299c47aa7da7e6c210caff8b075ff331.png)

To send a coin to someone else Goofy creates a new statement that includes the public key to whoever he wants to transfer to and a hash pointer to the coin that he created. He signs it with his private key.

![07c727a49285ff6586e4357a1469fa7b.png](image/07c727a49285ff6586e4357a1469fa7b.png)

![fc05ba5c0cd2bfae8eda6f56a692c69d.png](image/fc05ba5c0cd2bfae8eda6f56a692c69d.png)

At each step, you can verify that someone owned the coin.

**Double spending attacks** are one of the main design challenges in digital currency.

![37de9bcdc617f549a9674ef7cc5b9236.png](image/37de9bcdc617f549a9674ef7cc5b9236.png)

So how do you solve the double spending problem?

Let's talk about Scrooge Coin. With Scrooge Coin a designated entity publishes an **append-only ledger** containing the history of all the transactions that have happened. To prevent the double-spending attack, we require that all transactions are written to the ledger before they are accepted. That way it will be visible to everyone if a coin has already been spent. 

![af23ca622a42707904e39a07c6d9cfaf.png](image/af23ca622a42707904e39a07c6d9cfaf.png)

In Scrooge Coin there are two kinds of transactions:

* Creating coins
* Payments

![19965cf00a3abc2a50073d9ff4b263f0.png](image/19965cf00a3abc2a50073d9ff4b263f0.png)

The core problem with Scrooge Coin is that Scrooge has **too much influence**. Can we **decentralize** cryptocurrencies? To do this we have to have all users agree on a single published blockchain and agree on which transactions are valid. There needs to be decentralization of ID assignment and mining of new coins.

Since there is no centralized authority bitcoin, **distributed consensus** is critical. When Alice wants to pay Bob, she broadcasts the transaction to all bitcoin nodes. The consensus usually takes about an hour to compute.

![078b6665f10115df821d906f78ce495b.png](image/078b6665f10115df821d906f78ce495b.png)

Bitcoin rewards nodes for behaving honestly.

![e3afda5bd2103fb2e25e3d48684f2893.png](image/e3afda5bd2103fb2e25e3d48684f2893.png)

![d7822763e2ebc6bb3a0d4f17cbf358b6.png](image/d7822763e2ebc6bb3a0d4f17cbf358b6.png)

Fundamentally, security with Bitcoin is all about **key management**. Your key pair is your way of verifying that coins belong to you. Your key store is as secure as your device.

![Screen_Shot_2019-11-09_at_8-13-03_PM.png](image/Screen_Shot_2019-11-09_at_8-13-03_PM.png)

The hot side generates a new address when it wants to store a coin offline (cold side).  It can also generate a key so that it can send coins back to the hot side.

A **Merkle Tree** is a binary tree that is built with hash pointers. 

![bd214e2f1b5ac48eaafcd6676716d67d.png](image/bd214e2f1b5ac48eaafcd6676716d67d.png)

An exchange uses Merkle Trees to claim the proof of reserve, or that certain people have exchanged bitcoins there. 

![367c3476e85977328cc53b290ed30f23.png](image/367c3476e85977328cc53b290ed30f23.png)

**Decentralized Mixing** is a technique used to reduce the likability of bitcoin transactions. The basic idea is to pool transactions into a single transaction.

![Screen_Shot_2019-11-09_at_8-31-37_PM.png](image/Screen_Shot_2019-11-09_at_8-31-37_PM.png)
