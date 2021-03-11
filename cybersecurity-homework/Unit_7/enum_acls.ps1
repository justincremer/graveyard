# enumerates the ACL status of each file/directory in the current directory

$directory = ls;
foreach($item in $directory) { Get-Acl $item }
