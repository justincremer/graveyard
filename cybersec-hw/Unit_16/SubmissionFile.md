# Unit 16 
## Justin Cremer

#### Step 1

1. Karl Fitzgerald
2. An attacker can devise targeted phising campaign.  This information can lend
   itself to an actors ongoing reconaisance - allowing for further enumeration
   on different profiles, such as linked in.

#### Step 2 

1. San Antonio, TX 
2. 65.61.137.64 - 65.61.137.127
3. Akamai Technologies
4. 65.61.137.117

#### Step 3 

There is an unencrpypted instance of Apache-Coyote/1.1 running on port 80, which
is transporting raw text/html docs.

#### Step 4 

Yes, it is vulnerable to XSS

### Step 5 

Your client has asked that you help identify any vulnerabilities with their file-sharing server. Using the Metasploitable machine to act as your client's server, complete the following:

``` bash
nmap -T4 -A -v 192.168.0.10 -o metasploitable.nmap
```

``` bash
nmap -T4 -A -v --script vulners -p 139,445 192.168.0.10 -o metasploitable.nmap
```
- Zenmap vulnerability script command: 

- Once you have identified this vulnerability, answer the following questions for your client:
  1. What is the vulnerability:

  2. Why is it dangerous:

  3. What mitigation strategies can you recommendations for the client to protect their server:

