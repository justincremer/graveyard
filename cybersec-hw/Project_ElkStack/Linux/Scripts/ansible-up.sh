#!/bin/bash
# Location :: Jumpbox

# This script checks the status of an ansible container, starts it if the status is exited,
# and creates it if the container doesn't exist. This should be run on a jumpbox 
# with docker.io installed and the daemon enabled.

# Get container status    
result=$(sudo docker ps -a |grep ansible |awk '{ if ($7=="Exited") print $12; else if ($7=="Up") print $7; else print "nil"}')

if [ $result == "Up" ]; then
    # If met, the container is up and you're free to shell in
    echo "Container already running..."
elif [ $result == "nil" ]; then
    # Pull image if it doesn't exist
    if [ $(-z $(sudo docker images |grep ansible)) ] then
        sudo docker pull cyberxsecurity/ansible
    fi
    # Create container
    sudo docker run -ti cyberxsecurity/ansible:latest bash
else 
    sudo docker start -i $result
fi