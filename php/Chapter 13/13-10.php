<?php													
	$string = "The quick brown fox jumped over the lazy dog.<br>";		
														
	$patterns[0] = "/quick/";								
	$patterns[1] = "/brown/";								
	$patterns[2] = "/fox/";								
	$replacements[2] = "bear";								
	$replacements[1] = "black";							
	$replacements[0] = "slow";								
	print preg_replace($patterns, $replacements, $string);	//�滻
	ksort($replacements);									
	print preg_replace($patterns, $replacements, $string);	//�滻
?>														
