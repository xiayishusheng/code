<?php											
	$date="2008-08-08";							
	if (ereg ("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2})", $date, $regs)) {
												
		echo "$regs[1] �� $regs[2] �� $regs[3] ��";	
	} 
	else {										
		echo "Invalid date format: $date";			
	}
?>												

