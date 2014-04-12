<?php
		/* 步骤一：设置初始变量*/
	$host="localhost";					
	$user="root";							
	$pass="123456";						
		/* 步骤二：连接MySQL服务器 */
	$link=mysql_connect($host,$user,$pass);	
	if(!$link) echo "连接失败!<br>";		
	else echo "连接成功!<br>";				
		/*步骤三：关闭数据库*/
	$close=mysql_close();					
	if($close)							
	{
	echo "断开数据库连接!";					
	}
?>
