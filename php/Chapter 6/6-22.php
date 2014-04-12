<?php													
	echo date("F j, Y, g:i a"). "&nbsp&nbsp&nbsp&nbsp&nbsp";	
	echo date("m.d.y"). "&nbsp&nbsp&nbsp&nbsp&nbsp";		
	echo  date("j, n, Y"). "&nbsp&nbsp&nbsp&nbsp&nbsp";		
	echo  date("Ymd"). "&nbsp&nbsp&nbsp&nbsp&nbsp";				
	echo  date('h-i-s, j-m-y, it is w Day z '). "&nbsp&nbsp&nbsp&nbsp&nbsp";

	echo  date('\i\t \i\s \t\h\e jS \d\a\y.'). "&nbsp&nbsp&nbsp&nbsp&nbsp";
															
	echo  date("D M j G:i:s T Y"). "&nbsp&nbsp&nbsp&nbsp&nbsp";	
	echo  date('H:m:s \m \i\s\ \m\o\n\t\h'). "&nbsp&nbsp&nbsp&nbsp&nbsp";	
															
	echo  date("H:i:s"). "&nbsp&nbsp&nbsp&nbsp&nbsp";			
	echo date('l dS \of F Y h:i:s A');							
	echo date(DATE_ATOM, mktime(0, 0, 0, 7, 1, 2000));			
?>															
