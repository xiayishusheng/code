<?php 
	/* 步骤一：设置初始变量 */
	$host="localhost";							
	$user="root";									
	$password="123456";							
		/* 步骤二：连接MySQL服务器 */
	$conn=mysql_pconnect($host,$user,$password); 	
	if (!$conn){									
		die ("连接MySQL服务器失败。".mysql_error( ));
		}
	else{										
	echo  "MySQL服务器:$host<br>用户名称：$user  <br>";	
	echo  "使用mysql_pconnect()永久连接数据库";		
	}
?>
