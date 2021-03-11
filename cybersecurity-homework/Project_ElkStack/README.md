# ElkStack-Project
## Author: Justin Cremer

### Summary 
A collection of scripts and configs for a cloud based Elk stack, using a series
of docker containers built from an ansible container on a jumpbox.  

### Ansible
The Ansible directory contains three directories, being Files, Roles, and
Scripts.  Both Files and Roles should be slotted in the /etc/ansible directory
of your ansible container.  Roles contains the ansible-playbooks for building
various system components, while Files contains the various configs used in the
playbook configs.  The Scripts directory contains shorthands for running the
ansible-playbook commands. 

### Linux
This directory will include general purpose tooling I used throughout the
project.

### Images
The virtual net and subnet include a strict firewall, screenshots for which will
be included in the Images/Firewall directory.  Additionally, I will include
system and subsystem diagrams in the Images/Diagrams directory.
