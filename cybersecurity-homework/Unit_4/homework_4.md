# Unit 4 Homework
## Justin Cremer

#### any instance of the string '::' respresnts a line insert or modification in a file 


## Step 1

1. ls -l /etc/shadow\
   sudo chmod 600 /etc/shadow

2. ls -l /etc/gshadow\
   sudo chmod 600 /etc/gshadow

3. ls -l /etc/group\
   sudo chmod 644 /etc/group

4. ls -l /etc/passwd\
   sudo chmod 644 /etc/passwd

## Step 2

1. sudo useradd --no-create-home sam\
   sudo useradd --no-create-home joe\
   sudo useradd --no-create-home amy\
   sudo useradd --no-create-home sara\
   sudo useradd --no-create-home admin

2. sudo nano /etc/security/pwquality.conf\
   :: minlen = 16  (require at least 16 characters)\
   :: dcredit = 2  (require at least 2 integers)\
   :: ocredit = 1  (require at least 1 symbol)

3. sudo chage -M 90 sam\
   sudo chage -M 90 joe\
   sudo chage -M 90 amy\
   sudo chage -M 90 sara\
   sudo chage -M 90 admin

4. sudo usermod -aG sudo admin (adds admin to sudo group)\
   sudo visudo 			 	   (opens sudoers file)\
   :: admin ALL=(ALL:ALL) ALL  (adds admin to the sudoers file)
   
## Step 3

1. sudo groupadd engineers

2. sudo usermod -aG engineers sam\
   sudo usermod -aG engineers joe\
   sudo usermod -aG engineers amy\
   sudo usermod -aG engineers sara\
   sudo usermod -aG engineers admin

3. sudo mkdir /home/engineers

4. sudo chgrp -R engineers /home/engineers\
   sudo chmod -R 770 /home/engineers

## Step 4

1. sudo apt-get install -y lynis

2. man lynis (or 'lynis --help')

3. sudo lynis audit system

4. documented as lynis_report.png

## Bonus

1. sudo apt-get install -y chkrootkit

2. man chkrootkit (or 'chkrootkit --help')

3. sudo chkrootkit -x

4. documented as chkrootkit_report.png
