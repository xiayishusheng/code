<?php
		/* 步骤一：设置初始变量*/
	$host=“localhost”;								
	$user=“root”;										
	$password=“123456”;								
		/* $dbase_name：数据库名称  $table_name数据表名称*/
	$dbase_name="people"; $table_name="students";		
		/* 步骤二：连接数据库服务器 */
	$conn=mysql_connect($host,$user,$password)  or		
		die ("连接数据库服务器失败。".mysql_error());		
	echo  "数据库服务器: $host    用户名称：$user  <br>";		
		/* 步骤三：连接数据库 */
	mysql_select_db($dbase_name,$conn) or				
		die ("连接数据库失败。".mysql_error());			
	echo  "数据库: $dbase_name    数据表: $table_name  <br> ";	
		/*数据表的字段为中文时,进行代码转换.*/
	mysql_query("SET NAMES 'GB2312'"); 				
		/*步骤四：得到数据记录集合*/
	$mysql_command="select * from  ".$table_name;		
	$result=mysql_query($mysql_command,$conn) or 		
		die ("<br> 数据表无记录。<br>");					
		/*步骤五：逐条显示记录*/
	$i=0;
	while ( $record=mysql_fetch_row($result)) {			
		$i=$i+1;
		echo " I D号: ".$record[0];					
		echo " 姓名: ".$record[1]; 						
		echo " 年龄: ".$record[2]; 						
		 echo " 性别: ".$record[3]; 					
		echo " 电话: ".$record[4]; 						
		echo "<br>";									
	}   
	echo "成功显示数据表: ".$table_name." 的记录。记录数:";echo  $i;	
?>
