<?php												
	echo str_replace("ASP", "PHP", "I love ASP, ASP said");				
													
	echo "<br>";										
	$str = "Line 1\nLine 2\rLine 3\r\nLine 4\n";		
	$order = array("\r\n", "\n", "\r");				
	$replace = '<br />';								
	$newstr = str_replace($order, $replace, $str);		
	echo $newstr;									
?>													
