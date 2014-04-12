<?php											
	$date="2008-08-08";							
	if (ereg ("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2})", $date, $regs)) {
												
		echo "$regs[1] Äê $regs[2] ÔÂ $regs[3] ÈÕ";	
	} 
	else {										
		echo "Invalid date format: $date";			
	}
?>												

