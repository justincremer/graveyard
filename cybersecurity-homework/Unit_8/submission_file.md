# Unit 7
## Justin Cremer

### Phase 1

- Commands : sudo nping -c 3 --icmp 15.199.94.91/28 11.199.158.91/28 167.172.144.11/32 11.199.141.91/28
- Results : 
  - Statistics for host 167.172.144.11 :
  - Probes Sent: 3 | Rcvd: 3 | Lost: 0  (0.00%)
  - Max rtt: 69.484ms | Min rtt: 69.346ms | Avg rtt: 69.415ms 
- Summary : 
  - I ran nping against the four ip addresses hosted in Hollywood, only one of which (167.172.144.11) recieved packets.
	  I didn't install fping, as nmap comes with a similar tool, nping, which gives a bit more flexibility to scans.  As seen in the
	  results, 167.172.144.11 was the only address with no packet loss.  The proccess of port scaning happens on the network layer (third). This could be the result of a malicous actor having gained access to one of Rockstar Corp's servers and having opened a port for future	remote access.  This could be resolved by implementing network scanning and logging procedures, patching the network firewall, disabling icmp pinging, and by using additional proxy/vpn layers, as this particular address hosts the company's application servers.


### Phase 2

- Commands : nmap -Pnv 167.172.144.11
- Results :
  - 22/tcp  open     ssh
  - 25/tcp  filtered smtp
  - 111/tcp filtered rpcbind
  - 135/tcp filtered msrpc
  - 139/tcp filtered netbios-ssn
  - 445/tcp filtered microsoft-ds
- Summary : Upon enumerating the ip address given in the last phase, we can see that an ssh port is open, as well as a number of remote access service ports.  Nmap takes advantage of a number of osi layers, but predominantly uses the trasport layer for spidering TCP, UDP, and SCTP protocols for open ports.  The best way for RockStar Corp to portenct against malicous attacks, while leaving these ports open, would be to increase firewall provisioning, with additional ruling for these ports.

### Phase 3

- Commands : 
  - sudo ssh jimi@167.172.144.11 -p 22
  - cat /etc/hosts
  -	nslookup 98.137.246.8
- Results : 
  - etc/hosts : 98.137.246.8 rollingstone.com
  - nslookup : 
    - 8.246.137.98.in-addr.arpa
    - media-router-fp72.prod.media.vip.gq1.yahoo.com
- Summary : It's easy to assume from these findings that a malicous actor popped this server and modified the /etc/hosts file to point traffic to another domain.  This can be confirmed using nslookup or online dns lookup tools, to confirm the ip address present in the /etc/hosts file does in fact point to an unexpected domain.  This redirection is an example of an actor taking advantage of the Network layer.

### Phase 4

- Commands : 
  - find -type f | grep packet
  - cat /etc/packetcaptureinfo.txt
- Results :
  - packetcapture : 
	  Captured Packets are here:\
	  https://drive.google.com/file/d/1ic-CFFGrbruloYrWaw3PvT71elTkh3eF/view?usp=sharing
- Summary : 192.168.47.200 points to two different mac addresses, presumably the result of a malicous actor redirecting network traffic and/or backdooring into RockStar Corp's server, set in the server's /etc/hosts config.  The hacker made a post request to Gottheblues.com, offering up sensitive information - an open ssh port with user creds in exchange for one million dollars, a terrible deal!  RockStar Corp should be actively monitoring their network traffic.  Assuming they are and have noticed this very action taking place, they should patch their firewall to disallow unauthorized traffic on port 22 and check for any network modifications (/etc/hosts in this case).  The OSI layer the hacker too advantage of is the network layer.

