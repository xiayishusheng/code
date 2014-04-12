<?php											
	$mystring=php;								
	$pos = strrpos($mystring, "p");				
	if ($pos === false) { 						
		echo "not found...<br>";					
	}
	else {										
		echo "The string was  found in the string '$mystring'<br>";		
												
	}
	$mystring=php;								
	$pos = strrpos($mystring, "b");				
	if (is_bool($pos) && !$pos) {					
		echo "not found...";						
	}
	else {										
		echo "The string was  found in the string '$mystring'<br>";		
												
	}
?>												
