<?php							
		$a[0] = 1;				
		$a[1] = 3;				
		$a[2] = 5;				
	$result1 = count($a);			
		$b[0] = 7;				
		$b[5] = 9;				
		$b[10] = 11;				
	$result2 = count($b);			
	$result3 = count(null);		
	$result4 = count(false);		
	echo "$result1<br>";			
	echo "$result2<br>";			
	echo "$result3<br>";			
	echo "$result4";				
?>								
