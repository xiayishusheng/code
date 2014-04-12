<?php											
	$text = 'This is a test';						
	echo strlen($text)."<br>";						
	echo substr_count($text, 'is')."<br>";			
	echo substr_count($text, 'is', 3)."<br>";		
	echo substr_count($text, 'is', 3, 3)."<br>";
?>												
