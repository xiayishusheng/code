<?php													
	echo  "目前执行的文件名称". $_SERVER['PHP_SELF']."<br>";	
	echo  "服务器名" . $_SERVER['SERVER_NAME']."<br>";		
	echo  "服务器软件".$_SERVER['SERVER_SOFTWARE']."<br>";		
	echo  "文档的根目录" . $_SERVER['DOCUMENT_ROOT']."<br>";	
	echo  "用户相关信息" . $_SERVER['HTTP_USER_AGENT']."<br>";	
	echo  "远程用户的地址". $_SERVER['REMOTE_ADDR']."<br>";	
	echo  "远程用户的连接端口". $_SERVER['REMOTE_PORT']			
?>														
