<?php 
		/* 步骤一：设置初始变量 */
	$host="localhost";							
	$user="root";									
	$password="123456";							
		/* 步骤二：连接MySQL服务器 */
	$conn=mysql_connect($host,$user,$password);		
	if (!$conn){									
		die ("连接MySQL服务器失败。".mysql_error( ));	
		}
		/* 步骤三：显示连接结果 */
	else{										
	echo  "MySQL服务器:$host <br> 用户名称：$user  <br>";	
	echo  "连接MySQL服务器成功。";					
	}
?>

