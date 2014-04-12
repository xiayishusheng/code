<?php
		/* 步骤一：设置初始变量*/
	$host="localhost";						
	$user=“root”;								
	$pass="123456";							
		/* 步骤二：连接数据库服务器 */
	$link=mysql_connect($host,$user,$pass);		
	if(!$link) echo "失败!<br>";				
	else echo "成功!<br>";						
		/* 步骤三：选择数据库 */
	mysql_select_db("testdb");					
	if(mysql_errno())
	{
		die("<br>".mysql_errno().":".mysql_error()."<br>");				
											
	}
?>
