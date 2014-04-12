<?php
		/* 步骤一：设置初始变量*/
	$host="localhost";								
	$user="root";										
	$password="123456";								
	/* $dbase_name：数据库名称  $table_name数据表名称*/
	$dbase_name="students"; 							
	$table_name="classone";							
		/* 步骤二：连接数据库服务器 */
	$conn=mysql_connect($host,$user,$password)  or		
	die ("连接数据库服务器失败。".mysql_error());			
		echo  "数据库服务器: $host    用户名称：$user  <br>";	
		/* 步骤三：连接数据库 */
	mysql_select_db($dbase_name,$conn) or				
		die ("连接数据库失败。".mysql_error());			
	echo  "数据库: $dbase_name    数据表: $table_name  <br> ";	

		/*进行代码转换.*/
	mysql_query("SET NAMES 'GB2312'"); 				
		/*步骤四：删除记录*/
	$mysql_command="delete from ".$table_name." where name=\"张友\"";	
	$result=mysql_query($mysql_command)  or				
		die ("数据表:$table_name  删除记录失败!".mysql_error());		
													
	echo "成功删除数据表: ".$table_name." 的记录。";		
?>
