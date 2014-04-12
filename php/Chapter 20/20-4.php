<?php
	/* 步骤一：设置初始变量*/
	$host="localhost";							
	$user="root";									
	$password="123456"; 							
	$db_name="students"; 							
	/* 步骤二：连接数据库服务器 */
	$conn=mysql_connect($host,$user,$password)  or	
		die ("连接数据库服务器失败。".mysql_error( ));	
	echo  "数据库服务器: $host    用户名称：$user  <br>";	
	/* 步骤三：建立数据库 */
	$mysql_command="create database ".$db_name;		
	$result=mysql_query($mysql_command) or			
   		 die ("建立数据库失败。".mysql_error( ));		
	/* 步骤四：建立成功提示 */
	echo "成功建立数据库:".$db_name;					
?>
