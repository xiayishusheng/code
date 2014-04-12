<?php												
	$string="PHP is a language,PHP is a web langage,php";
	$result=preg_match_all("/PHP/",$string,$matches, PREG_PATTERN_ORDER);	
													
	if ($result==true){								
	 print "$result PHP was found.<br>";				
	 print_r($matches);								
	echo "<br>";										
	} else {											
	 print "PHP was not found.<br>";					
	 print_r($matches);								
	 echo "<br>";										
	}
?>													


