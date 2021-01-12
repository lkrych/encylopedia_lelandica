# Introduction to Systems Performance

## Table of Contents
* [Introduction](#introduction)
* [Workload Analysis vs Resource Analysis](#workload-analysis-vs-resource-analysis)
* [Performance is Difficult](#performance-is-difficult)


## Introduction

Systems performance studies the performance of an entire computer system, including all major software and hardware components. 

![](resources/systems_software_stack.png)

Anything in the data path can affect systems performance, so **if you don't have a diagram of your environment showing the data path, find one or draw it yourself**!

The typical goals of systems performance are to:
1. Improve the end-user experience by **reducing latency**
2. **Reduce computing cost**. Reducing cost can be achieved by eliminating inefficiencies, improving system throughput and general tuning.

Cloud computing provides new techniques for proof-of-concept testing. One such technique is called **canary testing** where **new software is tested on a single instance with a fraction of the production workload**. 

Another technique called **blue-green deployment** utilizes canary testing as a normal step in deployment: **traffic is gradually moved to a new pool of instances while leaving the old pool online as backup**.

## Workload Analysis vs Resource Analysis

Performance analysis is typically viewed from two different perspectives:
1. **Resource Analysis** - commonly employed by system administrators, they take a bottom up approach of looking at the software stack. They investigate the devices and hardware first.
2. **Workload Analysis** -  commonly employed by application developers, they take a top down approach of looking at the software stack. They investigate the application deployed on top of the hardware.

## Performance is difficult