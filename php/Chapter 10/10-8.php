<?php								
	$fp=fopen("many.txt","r");			
	//获得前15个字符
	$data=fgets($fp,15);				
	//获取当前指针
	echo ftell($fp);					
	fclose($fp);						
?>									
