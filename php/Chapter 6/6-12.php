<?php						
	$int1=1;					
	function fun1(){			
		echo "$int1<br>";		
		global $int1;			
		global $int2;			
		$int2=2;				
		echo "$int1<br>";		
	}
	fun1();					
	echo "$int2<br>";			
?>							
