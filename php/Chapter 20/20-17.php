<?php
		/* 步骤一：设置初始变量*/
	$host=“localhost”;								
	$user=“root”;										
	$password=“123456”;								
	/* $dbase_name：数据库名称  $table_name数据表名称*/
	$db_name="students"; 								
	$table_name="classone";							
		/* 步骤二：连接MySQL服务器 */
	$conn=mysql_connect($host,$user,$password)  or		
		die ("连接MySQL服务器失败。".mysql_error());		
	echo  "数据库服务器: $host    用户名称：$user  <br>";		
		/* 步骤三：连接数据库 */
	mysql_select_db($db_name,$conn) or					
		die ("连接数据库失败。".mysql_error());			
	echo  "数据库: $db_name    数据表: $table_name  <br> ";	
													
		/* 步骤四：显示数据表的字段信息 */
		/*数据表的字段为中文时,进行代码转换.*/
	mysql_query("SET NAMES 'GB2312'"); 				
		/*得到数据表的字段信息。*/
	$fields=mysql_list_fields($db_name,$table_name,$conn);
		/*得到数据表的字段个数。*/
	$field_count=mysql_num_fields($fields);				
		/*显示数据表字段名。*/
	echo $table_name."数据表文件的字段名为：<br>";			
	$i=0;
	while ($i<$field_count) {							
		echo  mysql_field_name($fields,$i)."<br>";		
		$i=$i+1;
	}
?>



