# Week 2 - Penetration Testing and Browser Security

Penetration Testing Lectures/Notes

Browser Security Lecture/Notes

Quiz 2 (9/7/19)

Submit Project 1 (9/9/19)

Readings

* A look back at security problems in TCP
* An Illustrated guide to DNS vulnerability ~ DNS poisoning is an exploit whereby an attacker tricks a resolver to point to it. This can happen at a very large scale and be dangerous.
* BGP Security in Partial Deployment ~ Half-delivered secure BGP isn't very effective, it is still susceptible to downgrade attacks. It is about as effective as Message Authentication
* Securing Frame Communication in Browsers
* The Security Architecture of Chromium
* Exposing private information through timing
* Intro to Content Security Policy ~ Use CSP to to prevent XSS attacks, it is a whitelist for what you can load on a page.
* Play safely iFrames ~ CSP allows you to whitelist trusted sources, iFrames and their sandbox attributes allow you to add more fine-grained control into your website around third-party code. 
* Web Workers
* Using CORS

Notes

Penetration Testing Lectures

**Penetration Testing**  - is used to evaluate the security of a network, more specifically it used to evaluate the security controls (procedures, operations, and technologies used). 

* **Footprinting** - Reconaissance and information gathering: network IP ranges, namespace, topology
    * **whois **
    * **nslookup **

* **Scanning**
    * **nmap **

* **Enumeration**
* **Gaining Access**
* **Escalating privilege**
* **Pilfering**
* **Covering Tracks**
* **Creating Backdoors**

When should penetration testing be done?

* Regularly, if not regularly, then when infrastructure, applications or security patches are added. Also, when end user policies are changed.

What is **social engineering**?

* Manipulating legitimate users into undermining their own security system
* Common social engineering techniques include
    * Impersonating help desk, third-party auth, or tech support
    * Tailgating, roaming the halls
    * Pop-up windows, IMs, email attachments, email scams, phishing websites

Notes

Browser Security/ Advanced Web Security Lectures

Some common web/browser attacks:

* **Using components with known vulnerabilities - **
* **Missing function level access control - **Privilege functionality is hidden rather than enforced through access controls
* **Sensitive data exposure - **Abuses lack of data encryption
* **Security misconfiguration - **Exploits misconfigured servers
* **Insecure direct object references - **Attackers modify file names
* **Cross site scripting - **Inserts JavaScript into trusted sites
* **Broken authentication and session - **
* **Injection - **Modifies back-end statement through user input

Goals of Web Security

* No stolen information
* Site A cannot compromise session at site B
* Applications delivered over the web should be able to achieve the same security properties as applications run on our computers.

Web Security Threat Model

* Attacker sets up a malicious site and waits for users to visit. They do not have access to the network.
* Can obtain SSL/TLS certificate for malicious website
* Can trick user using phishing or redirection
* Web attackers are

Network Security Threat Model

* Much more active than the web security attacker, can intercept and control the network.
* **Passive and active**

The most general and powerful attacks are **malware**. These programs escape the isolation mechanisms of the browser and run separately under the control of the OS.

Comparing OS and Web browser as execution environments

![dfd4ce76619866ca14658371cbd60452.png](image/dfd4ce76619866ca14658371cbd60452.png)

Basic Execution Model of Web Browsers

![2763a8e1a6b042e374a034bd3dcaec9d.png](image/2763a8e1a6b042e374a034bd3dcaec9d.png)

![f5d542dd70709f2135f5dd9fd6897b51.png](image/f5d542dd70709f2135f5dd9fd6897b51.png)

The basic idea of browser security is to **sandbox** web contents. Safely execute JavaScript code so that it cannot directly access the file system, has limited access to the OS, network, browser data and content that came from other websites.

The main policy is **Same Origin Policy (SOP)** which states that active code can only read properties of documents and windows from the same origin (protocol, domain and port). There are some exceptions to this, users can grant privileges to certain scripts.

**Origins **are defined by protocol, domain and port. 

For the DOM, the Same Origin Policy (SOP) states that Origin A can access Origin B's DOM if A and B have the same protocol, domain and port.

For Cookies, the the Same Origin Policy (SOP) states that Origin A can access Origin B's cookie if they have the same domain and path. Protocol is optional.

**Frames and iFrames** are like miniature browser windows. A frame is typically rigid or fixed on a page, whereas an iFrame can be floating. 

![7ed0694ad05cb2d9cf80f6b7d0a2dfba.png](image/7ed0694ad05cb2d9cf80f6b7d0a2dfba.png)

![26130279d9d4e339379b201952ff2504.png](image/26130279d9d4e339379b201952ff2504.png)

![30fcaeaaa72e4d01fd854401237f67b6.png](image/30fcaeaaa72e4d01fd854401237f67b6.png)

Browsing Context

* A frame with its DOM
* A web worker (thread), which does not have a DOM, JavaScript that runs in the background that is independent from UI

Every **Browsing Context** has an origin, is isolated from others by the same-origin policy, may communicate with other browser contexts using postMessage, and can make network requests using XHR (XML HTTP Request) or tags (<image>).

There are similarities between a browser context and an operating system context. OS's uses separation and isolation to allow multiple execution contexts and provide storage and communication services. Web browsers do the same!

![983cbf2e9f3542a6d73d74cc9042bf09.png](image/983cbf2e9f3542a6d73d74cc9042bf09.png)

Here are some examples of how modern browsers manipulate their context.

![619ba1d301c25c836a3879612ada61a8.png](image/619ba1d301c25c836a3879612ada61a8.png)

![53b4a5e1f80529466f7f44729270cd4c.png](image/53b4a5e1f80529466f7f44729270cd4c.png)

![071c92ea545167adfecf61eb607046c0.png](image/071c92ea545167adfecf61eb607046c0.png)

The goal of **Content Security Policy (CSP)** is to prevent and limit damage of **XSS (cross-site scripting)**.

**XSS** attacks bypass the same origin policy by tricking a site into delivering malicious code along with intended content.

With **CSP**, a browser can be instructed to **only load resources from a white-list**.

* Can be specified by scheme: https, etc.
* Can be specified by host name: matching any origin on that host
* Can be a fully qualified URL
* Additionally, you can have 'none', 'self', and different wild card matching.

**Web Workers** were not intended for security, but they improve it because they allow JavaScript to be run in isolated threads. Web workers have the same origin as the frame they were created in, but they have no DOM. They can communicate using postMessage.

![f03cf04a57e229b99a46711c7a65a54c.png](image/f03cf04a57e229b99a46711c7a65a54c.png)

**Subresource Integrity **- author of content specifies a hash of the resource they are loading. The browser then checks the hash of the content they are loading. When an integrity check fails, by default, the browser reports a violation and does not render/execute the resource. Or, optionally, the browser can report the violation, but still execute the resource.

![4bb23b12dbf047d26ca2fa1b6916da16.png](image/4bb23b12dbf047d26ca2fa1b6916da16.png)

**Cross-origin resource sharing** - A technique that is used to relax same-origin policy, which allows JavaScript on a web page to consume content from a different origin. A good example of this would be [amazon.com](http://amazon.com/) and aws. This technique uses white-lists

![9b78f109b6fbf9b6a56c59a561d139d0.png](image/9b78f109b6fbf9b6a56c59a561d139d0.png)

**SOP and cookies**

* The strict option on the 
* **HttpOnly**

![3893b3892c3c318b23f15598eb12c8ef.png](image/3893b3892c3c318b23f15598eb12c8ef.png)

Cookies can set **scope** for any domain-suffix except the top-level domain. So, for example. The website [login.site.com](http://login.site.com/) can set cookies for all of .site.com

![Screen_Shot_2019-09-03_at_8-20-24_PM.png](image/Screen_Shot_2019-09-03_at_8-20-24_PM.png)

Cookies are identified by name, domain and path. Browsers send all cookies that are in scope. 

![d9b912925359509f0a036f53a85e124e.png](image/d9b912925359509f0a036f53a85e124e.png)

JavaScript can be used to set, read, and delete cookies. The only exception to this is when the HttpOnly option is set. This means the cookie cannot be assessed by client-side scripts.

What does the statement, "the server is blind", mean in regards to cookies?

* Servers cannot see cookie attributes, and they cannot see which domain set the cookie. This can be exploited.

![c81117f236060c4d3c3153a1da8fbf96.png](image/c81117f236060c4d3c3153a1da8fbf96.png)

The problem here is that [course.site.com](http://course.site.com/) expects session-id from login.site.com, but cannot tell that the session-id cookie was overwritten.

![6eb5adb6fe95b4351fa866584b6a63ca.png](image/6eb5adb6fe95b4351fa866584b6a63ca.png)

Network attackers can intercept and re-write HTTPs cookies. HTTPS cookie values cannot be trusted.

Users can change and delete cookie values. So why are they even useful?!

Data integrity can be achieved using cryptographic checksums on the cookie values

![be0daba72818809a2a366f85cdf493ba.png](image/be0daba72818809a2a366f85cdf493ba.png)
