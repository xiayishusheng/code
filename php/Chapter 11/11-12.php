<?php							
	class Counter { 				
	function __destruct() { 		
		echo "<br>析构函数被执行。";	
	}  
	} 
	$p=new Counter();				
	unset($p);					
	for($i=0;$i<=3;$i++){			
		echo "<br>".$i;			
	} 
?>								
