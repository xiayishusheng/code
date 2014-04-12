	<?php
		/* 步骤一：设置初始变量*/
	$host="localhost";								
	$user=“root”;										
	$password=“123456”;								
		/* $db_name：数据库名称  $table_name数据表名称*/
	$db_name="students";								
	$table_name="classone";							
		/* 步骤二：连接MySQL服务器 */
	$conn=mysql_connect($host,$user,$password)  or		
		die ("连接MySQL服务器失败。".mysql_error( ));
	echo  "MySQL服务器: $host    用户名称：$user  <br>";	
		/* 步骤三：检查数据库 */
	$mysql_command="drop  database  if  exists ".$db_name;
												
	$result=mysql_query($mysql_command);			
		/* 步骤四：建立数据库 */	
	$mysql_command="create database ".$db_name;		
	$result=mysql_query($mysql_command) or			
		die ("建立数据库失败。".mysql_error( ));		
	mysql_select_db($db_name,$conn) or				
	die ("连接数据库失败。".mysql_error( ));			
	echo "数据库:$db_name  数据表:$table_name  <br> ";	
		/*数据表的字段为中文时,进行代码转换.*/
	$mysql_command="drop  database   ".$table_name;	
	if(!$mysql_command)
	echo "删除数据库表失败";							
	else
	echo "删除数据库表成功";							
?>
	