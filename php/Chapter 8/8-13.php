<?											
	$needle = "iwind"; 						
	$str = "I love iwind too"; 				
	if (strstr($str, $needle)){				
		echo strstr($str, $needle)."<br>";		
		echo "������ iwind<br>"; 				
		} 
	else 									
	{ 
  		echo "����û�� iwind<br>"; 				
	} 	
	$needle = "p"; 							
	$str1 = "php�����̳����ph��ȱ����ĸ"; 		
	if (strrchr ($str1, $needle)) {			
		echo strrchr ($str1, $needle)."<br>";	
		echo "������ p"; 						
		} 	
	else 									
	{ 
   		 echo "����û�� p<br>"; 				
	} 
?>											
