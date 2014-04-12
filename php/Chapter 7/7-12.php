<?php								
	$languages=array(10=>"ASP",		
					20=>"php",		
					21=>"JSP");		
	$leach=each($languages);			
	echo $leach[key].'<br>';			
	echo $leach[value].'<br>';			
	$leach=each($languages);			
	echo $leach[0].'<br>';			
	echo $leach[1].'<br>'				
?>									
