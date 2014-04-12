<?php											    
	echo substr_replace("abcdefghi", "DEF", 3);		    
	echo "<br>";									    
	echo substr_replace("abcdefghi", "DEF", 3, 2);	     
	echo "<br>";									    
	$var = 'AAA5BB:/CCC55D/';						    
	echo "Original: $var<hr />";					    
	echo substr_replace($var, 'EEEFF', 0, 0) . "<br >";
	echo substr_replace($var, 'EEEFF', 8, -1) . "<br>";
	echo substr_replace($var, 'EEEFF', -7, -1) . "<br>"; 
	echo substr_replace($var, '', 8, -1) . "<br>";	    
?>												    
										
