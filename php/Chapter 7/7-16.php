<?php									
	$a = array("a","b","c","d","e","f");	
	$index = array_search("a",$a);			
	if($index === false)					
		echo "在数组a中未发现字符'a'";		
	else									
		echo "Index = $index";			
?>										
