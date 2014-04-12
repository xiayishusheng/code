<?php											
	$mystring = 'abc';							
	$findme = 'a';								
	$pos = strpos($mystring, $findme);				
	if ($pos == false) {							
	echo " 在 $mystring 中没有找到字符 $findme";		
	} 
	else {										
		echo " 在 $mystring 中找到了字符 $findme";		
	}
?>												
