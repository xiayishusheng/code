<?php								
	class Counter { 					
		private static $count = 0; 	

	function __construct() {			
		self:: $count++ ; 			
	} 
	
	function __destruct() { 			
		self:: $count--; 				
	} 
	function getCount() { 			
		return self:: $count; 		
	} 
	} 

	$c = new Counter; 				
	print($c->getCount()."<br>"); 		
	$c2 = new Counter(); 				
	print($c->getCount() . "<br>");	
	$c2 = NULL; 						
	print($c->getCount()."<br>");		
?>									
										
