# Unit 7
## Justin Cremer

### Mission 1
- Command : nslookup -type=mx starwars.com
- Results :
  - aspmx2.googlemail.com
  - alt1.aspx.l.google.com
  - aspmx3.googlemail.com 
  - alt2.aspmx.l.google.com
  - aspmx.l.google.com 
- Explanation : The resistance isn't recieving email, as their DNS is still resolving to (presumably) their old Mail Exchange servers.  This can be corrected by reconfiguring their mail service to use the new servers.
          
### Mission 2
- Command : nslookup -type=mx theforce.net
- Results : v=spf1 a mx mx:smtp.secureserver.net include: aspmx.googlemail.com ip4:104.156.250.80 ip4:45.63.15.159 ip4:45.63.4.215
- Explanation : The Force is using a spam and spoof mitigation client with their ipv4 addresses set to their old ip addresses.  They will need to update their spf configuration to allow their new address to authenticate with their mail server and disallow their old ip addresses to further mitigate spoofing.

### Mission 3
- Command : nslookup www.theforce.net 
- Results : canonical name = theforce.net 
- Explanation :  

### Mission 4
- Command : nslookup -type=soa princessleia.com 
- Results : Address: 34.102.136.180 
- Explanation :

### Mission 5
- OSPF : Batuu -> D -> C -> E -> F -> J -> K -> O -> R -> Q -> T -> V -> Jedha

### Mission 6
- Command : aircrack-ng Darkside.pcap -w rockyou.txt 
- Results : 
    - wpa-pwd : dictionary
    - Host MACs::IPs :
        - 00:13:ce:55:98:ef :: 254.85.152.239
        - 00:0f:66:e3:e4:01 :: 254.227.228.1

### Mission 7
- File is located 'Unit_9/img/starwars.png'
