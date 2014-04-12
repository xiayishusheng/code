<?php
		/* 步骤一：设置初始变量*/
	$host="localhost”;								
	$user=“root”;										
	$password=“123456”;								
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

		/*数据表的字段为中文时,进行代码转换.*/
	mysql_query("SET NAMES 'GB2312'");					
		/*步骤四：得到数据记录*/
	$mysql_command="select * from ".$table_name." where age>20  ";
													
	$result=mysql_query($mysql_command,$conn) or 		
	die ("<br> 数据表无记录。<br>");						
		/*步骤五：显示数据*/
	$record_count =mysql_num_rows($result);
	echo " <br> 学生信息表 ";							
	echo "<table border=1>";							
	echo "<tr><td>年龄大于20的记录数</td></tr>";			
	echo "<tr><td>$record_count </td></tr>";			
	echo " </table>";									
?>

