<?php													
	$Email="php@php.com";									
	if (ereg ("([0-9a-zA-Z]+)([@])([0-9a-zA-Z]+)(.)([0-9a-zA-Z]+)", $Email, $regs)) {
														
		echo "$regs[1]$regs[2]$regs[3]$regs[4]$regs[5]";	
	} 
	else {												
		echo "Invalid Email format : $Email";				
	}
?>														
