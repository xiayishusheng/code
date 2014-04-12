<?php										
	$string=preg_match ("/\bweb\b/i", "PHP is the web scripting language of choice.",$matches);									//Æ¥Åä
	if ($string==true){							
		print "A match was found.<br>";			
		print_r($matches);						
		echo "<br>";								
		} else {									
		print "A match was not found.<br>";		
		print_r($matches);						
		echo "<br>";								
		}
		$string=preg_match ("/\bweb\b/i", "PHP is the website scripting language of choice.",$matches);
		if ($string==true) {						
		 print "A match was found.";				
		print_r($matches);						
		echo "<br>";								
		} else {									
		 print "A match was not found.<br>";		
		 print_r($matches);						
		}
?>											
