<?php
		/* 步骤一：设置初始变量*/
	$host="localhost"; 							
	$user=“root”;										
	$password=“123456”;								
	/* $dbase_name：数据库名称  */
	$dbase_name="students";							
	/* 步骤二：连接MySQL服务器 */
	$conn=mysql_connect($host,$user,$password)  or		
		die ("连接MySQL服务器失败。".mysql_error( ));		
	echo  "MySQL服务器: $host    用户名称：$user  <br>"; 	
		/* 步骤三：删除数据库。 */
	$mysql_command="drop  database  if  exists ".$dbase_name;				
													
	$result=mysql_query($mysql_command) or				
		die ("删除数据库失败。".mysql_error( ));			
	echo "成功删除数据库。".$dbase_name;				
?>
