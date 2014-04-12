<?php							
	class Counter { 				
		function __destruct() { 	
		echo "<br>析构函数被执行。";	
		}  
		} 
	$p=new Counter();				
	$i=1;						
	$sum=0;						
	do{
		$sum=$sum+$i;				
		echo $sum.”<br>”;			
		$i++;					
		}while($i<5)				
	echo "循环结束";				
	} 
?>								
