<?php										
	echo "<h3>自增a++ </h3>";					
	$a = 5;									
	echo "Should be 5: " . $a++ . "<br />\n";	
	echo "Should be 6: " . $a . "<br />\n";		
	echo "<h3>自增++a </h3>";					
	$a = 5;									
	echo "Should be 6: " . ++$a . "<br />\n";	
	echo "Should be 6: " . $a . "<br />\n";		
	echo "<h3>自减a-- </h3>";					
	$a = 5;									
	echo "Should be 5: " . $a-- . "<br />\n";	
	echo "Should be 4: " . $a . "<br />\n";		
	echo "<h3>自减--a </h3>";					
	$a = 5;									
	echo "Should be 4: " . --$a . "<br />\n";	
	echo "Should be 4: " . $a . "<br />\n";		
?>											
