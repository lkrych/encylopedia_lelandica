# Week 10 ML for Security

Quiz 9 - Nov 11

ML for Security Lectures

Data Poisoning and Model Evasion Lectures

Reading Constructing features for IDS

**ML for Security Lectures**

The goal of machine learning in network security is to automatically identify new attacks.

Machine Learning is the process of creating a prediction function concerning a certain output. We create the function by minimizing the prediction error on a training set. 

In the real world a commonly used process for segmenting data involves drawing from the data randomly and segmenting it into either training data or test data. 

**Features** are a measurable property of a dataset and they are applications dependent. For images they could be raw pixels, histograms, etc.

Performance Measures in Machine Learning

* Error Rate -  Fraction of false predictions
* Accuracy - Fraction of correct predictions
* Precision - Fraction of correction predictions among all examples predicted to be positive
* Recall - Fraction of correct predictions among all real positive examples.

Decision Tree Learning - A set of training examples is repeatedly partitioned until all the examples in each partition belong to one class. It can be thought of as a set of rules that organize the data. 

![6e6b4c692d012ff962d7c720301e2ff2.png](image/6e6b4c692d012ff962d7c720301e2ff2.png)

The process of building a decision tree involves selecting the best features to serve as a root. Then we break up the training set into subsets based on the branch of the root node. We then recursively generate new branches by determining which remaining features are most determinative.

How do we determine which attribute is best?

* **Entropy **

In order to determine which attribute is best at partitioning a set we compute its **information gain, **how good it is at separating samples  according to their classification. 

Clustering - can also be used for classification. They construct categories that optimize the distance or similarity function between categories. That is, examples in a cluster are more similar to each other than examples from different clusters.

![79fbe0903d38c47fd1e1ee1de3b7fd55.png](image/79fbe0903d38c47fd1e1ee1de3b7fd55.png)

![9eea1755e07958b680b0926c630ec77a.png](image/9eea1755e07958b680b0926c630ec77a.png)

What is the process of creating classifiers for Intrusion detection?

1. Capture Raw Data (tcpdump packet data could be used)
2. Summarize the data into connection records
3. Construct features with high information gain, use temporal and statistical patterns.

![1be1390cf8e6b7b25764714dbf1ac3c1.png](image/1be1390cf8e6b7b25764714dbf1ac3c1.png)

Importantly, when designing features, we need to find ones that are "relevant". There are many associated events in network activity, but not all of them are useful for detecting malicious events.

We classify our features/attributes as **axis** attributes or **reference** attributes.

An **axis** attribute is the** most important** attribute. 

A **reference** attribute is a sequence of **related** attributes to the axis attribute

**Attacking Machine Learning Lectures**

There are two types of attacks on Machine Learning:

* **Exploratory Attack**
* **Causative (Data poisoning) Attack**

**PAYL (Payload-based anomaly detection system) **measures and models the frequency distribution of n-grams in payloads of each network service. The intuition here is that each service delivered to a host has unique characteristics and that a malicious attack would look very different from typical network traffic.

**Polymorphic Attacks** can change appearance with each instance, they do not have a predictable signature. The Attack body which contains the malicious code can be transformed or encrypted, and typically the attack bundles a decryptor so the code can be transformed back into its malicious nature. However, the network payloads that contain the attack code/decryptor tend to be large, so an anomaly detection engine can sometimes detect them.

**Polymorphic Blending Attacks **try to evade this detecting by mimicking legitimate traffic and distributing the byte frequency of their payload as such. The most important step is to transform the attack code into unsuspicious bytes so that they match a desired byte frequency.

![4a116a8fb2533215c12edca24bf03b80.png](image/4a116a8fb2533215c12edca24bf03b80.png)

Clever malware designers use fake anomalous flows to create noise in IDS systems. This is known as a noise injection attack.

![8450246abd4ec8f7a0d0cfb9ff3b40db.png](image/8450246abd4ec8f7a0d0cfb9ff3b40db.png)

Injecting fake invariants defeats hierarchical clustering. 

![e6bf97b2a78ed0587e264cfec4fcf673.png](image/e6bf97b2a78ed0587e264cfec4fcf673.png)

Injecting normal substrings into fake anomalous flows artificially inflates innocuous flows.

![af59615df39a10ce83cb64f4e8a7ac7b.png](image/af59615df39a10ce83cb64f4e8a7ac7b.png)
