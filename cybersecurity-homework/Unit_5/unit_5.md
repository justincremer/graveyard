# Unit 5 Homework
#### Justin Cremer

## Step 1
1: cd ~/Projects && tar -xvvf ~/TarDocs.tar\

2: cd ~/Projects && tar -cvvWf Javaless_Docs.tar --exclude=./Documents/Java ./TarDocs\

3: cd ~/Projects && tar -tvvf Javaless_Docs.tar | grep -i java

Critical analysis question: the '-x' flag resolves to an archive extraction, while the '-c' flag resolves to a create archive.  When called together, these do not conflate into a multipurposed tool, but rather, will recursively call one another.

## Step 2
1: \
crontab -e\
:: Add to bottom of the file =>\
0 12 * * * sudo tar -czvf /auth_backup.tar.gz /var/log/auth.log
	
## Step 3
1: \
mkdir -p ~/backups/{freemem, diskuse, openlist, freedisk} (or)\
mkdir ~/backups && cd backups && mkdir freemem diskuse openlist freedisk

2:\
\#!/bin/bash\
\# Logs free memory to ~/backups/freemem/free_mem.txt\
free -h | awk '{print $1, $4}' > ~/backups/freemem/free_mem.txt

\# Logs Disk usage to ~/backups/diskuse/dick_usage.txt\
df -h | awk '{print $1, $3}' > ~/backups/diskuse/dick_usage.txt

\# logs Open files to ~/backups/openlist/open_list.txt\
lsof > ~/backups/openlist/open_list.txt

\# Logs Free disk space to ~/backups/freedisk/free_disk.txt\
df -h | awk '{print $1, $4}' > ~/backups/freedisk/free_disk.txt	

3: chmod +x system.sh\
Optional: ~/Scripts/system.sh && ls -R ~/backups


## Step 4
1:\
/var/log/auth.log {\
    missingok\
    monthly\
    create 0660 root utmp\
    rotate 1\
}

## Bonus
1: systemctl status auditd.service

2+3:\
-D\
-b 8192\
-f 1\
--backlog_wait_time 0\
-w /etc/shadow -p wa -k shadow\
-w /etc/passwd -p wa -k passwd

4: systemctl restart auditd.service

