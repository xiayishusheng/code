<?php
		/* 步骤一：设置初始变量*/
	$host="localhost";								
	$user=“root”;										
	$password="123456";								
		/* $dbase_name：数据库名称*/
	$dbase_name="news"; 								
		/* 步骤二：连接数据库服务器 */
	$conn=mysql_connect($host,$user,$password)  or 		
		die ("连接数据库服务器失败。".mysql_error( ));		
	echo  "数据库服务器: $host    用户名称：$user  <br>";		
		/* 步骤三：得到数据表信息*/
	$tables=mysql_list_tables($dbase_name,$conn);		
		/*得到数据库的数据表个数*/
	$tables_count=mysql_num_rows($tables);				
	echo "数据表文件个数：";								
	echo $tables_count;								
?>
