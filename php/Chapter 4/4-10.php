<?php										
	$var="1";								
	echo "$var is a ".gettype($var)."<br>";		
	$var+=1;									
	echo  "$var is a ".gettype($var)."<br>";	
	$var+=1.1;								
	echo  "$var is a ".gettype($var)."<br>";	
	$var=array($var);							
	echo  "$var is a ".gettype($var)."<br>";	
?>											
