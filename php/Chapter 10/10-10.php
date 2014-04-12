<?php											
	$handle=fopen ("many.txt","r");				
		//首先读取第1行，读取完毕后，指针在最后一行
	$buffer=fgets($handle,1024);					//读取第1行内容
	echo $buffer ."<br>";							
		//接着将指针向后移动5个字节
	fseek($handle,6,seek_cup);						//指针向后移动6个字节
		//接着读取一行
	$buffer=fgets($handle,1024);					//接着读取第1行内容
	echo $buffer . "<br>";						
		//将指针返回到到文件开始，重新读取第1行，因为是绝对位置为0
	fseek($handle,0);								
		//读取一行数据，因为指针回到文件开始，所以会读取第1行数据
	$buffer=fgets($handle,1024);					//再读取第1行文字
	echo $buffer ."<br>";							//输出读取内容
	fclose ($handle);								//关闭打开文件
?>												
