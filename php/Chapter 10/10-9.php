<?php									
	$handle=fopen("many.txt","r");			
		//读取首行
	$buffer=fgets($handle,1024);			
	echo $buffer ."<br>";					
		//读取第二行
	$buffer=fgets($handle,1024);			
	echo $buffer ."<br>";					
		//读取第三行
	$buffer=fgets($handle,1024);			
	echo $buffer ."<br>";					
		//将指针回到文件开始，继续读取第一行数据。
	rewind($handle);						
	$buffer=fgets($handle,1024);			
	echo $buffer ."<br>";					
	fclose($handle);						
?>										
