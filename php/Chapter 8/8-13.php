<?											
	$needle = "iwind"; 						
	$str = "I love iwind too"; 				
	if (strstr($str, $needle)){				
		echo strstr($str, $needle)."<br>";		
		echo "里面有 iwind<br>"; 				
		} 
	else 									
	{ 
  		echo "里面没有 iwind<br>"; 				
	} 	
	$needle = "p"; 							
	$str1 = "php基础教程里的ph，缺了字母"; 		
	if (strrchr ($str1, $needle)) {			
		echo strrchr ($str1, $needle)."<br>";	
		echo "里面有 p"; 						
		} 	
	else 									
	{ 
   		 echo "里面没有 p<br>"; 				
	} 
?>											
