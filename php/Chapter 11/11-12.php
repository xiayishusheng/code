<?php							
	class Counter { 				
	function __destruct() { 		
		echo "<br>����������ִ�С�";	
	}  
	} 
	$p=new Counter();				
	unset($p);					
	for($i=0;$i<=3;$i++){			
		echo "<br>".$i;			
	} 
?>								
