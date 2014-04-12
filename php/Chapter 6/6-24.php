<?php													
	$lastday = mktime(0, 0, 0, 3, 0, 2007);					
	echo strftime("Last day in Feb 2007 is: %d", $lastday);	
	echo "<br>";											
	$lastday = mktime(0, 0, 0, 4, -31, 2008);				
	echo strftime("Last day in Feb 2008 is: %d", $lastday);	
?>														
