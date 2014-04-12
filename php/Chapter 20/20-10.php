<?php
		/* 步骤一：设置初始变量*/
	$host="localhost";							
	$user=“root”;									
	$password=“123456”;							
		/* 步骤二：连接数据库服务器 */
	$conn=mysql_connect($host,$user,$password)  or 	
		die ("连接数据库服务器失败。".mysql_error( ));	
	echo  "数据库服务器: $host    用户名称：$user  <br>";	
		/* 步骤三：得到建立的数据库的信息 */
	$database=mysql_list_dbs($conn);				
		/* 步骤四：查询数据库的个数 */
	$database_count=mysql_num_rows($database);		
	echo "数据库文件个数：";							
	echo  $database_count							
?>
