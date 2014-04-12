<?php												
	$string="PHP is a language,PHP is a web langage,php";	
	$result=preg_match_all("/PHP/i",$string,$matches,PREG_OFFSET_CAPTURE);
													
	if ($result==true){								
	print "$result PHP was found.<br>";				
	print_r($matches);								
	echo "<br>";										
	} 
	else {											
		print "PHP was not found.<br>";				

		print_r($matches);							
		echo "<br>";									
	}
?>														
