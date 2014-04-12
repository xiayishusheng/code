<?php
		/* 步骤一：设置初始变量*/
	$host=“localhost”;								
	$user=“root”;										
	$password=“123456”;								
	$dbase_name="students"; 							
	$table_name="classone";							
		/* 步骤二：连接MySQL服务器 */
	$conn=mysql_connect($host,$user,$password)  or		
		die ("连接MySQL服务器失败。".mysql_error( ));		
	echo  "MySQL服务器: $host    用户名称：$user  <br>"; 	
		/* 步骤三：连接数据库 */
	mysql_select_db($dbase_name,$conn) or				
		die ("连接数据库失败。".mysql_error( ));			
	echo  "数据库: $dbase_name    数据表: $table_name  <br> ";	

	mysql_query("SET NAMES 'GB2312'"); 				
		/*步骤四：得到数据记录*/
	$mysql_command="select *  from ".$table_name." where age>20";	
	$result=mysql_query($mysql_command,$conn) or 		
		die ("<br> 数据表无记录。<br>");					
		/*步骤五：显示数据*/
	echo " <br> 年龄大于20的学生信息";					
	echo "<table border=1>";
	echo "<tr><td>序号</td><td>姓名</td><td>学号</td><td>年龄</td></tr>";
	$i=0;										
	while ($record=mysql_fetch_array($result)) {	
	$i=$i+1;
	/* 显示序号*/
	echo "<tr><td>$i</td>";						
	/* 显示姓名*/
	if (strlen($record[name])>0) 					

		echo "<td>$record[name]</td>";				
	else
	echo "<td>&nbsp</td>";						
	/* 显示学号*/
	if (strlen($record[numb])>0) 					
		echo "<td>$record[numb]</td>";				
	else
		echo "<td>&nbsp</td>";					
	/* 显示年龄*/
	echo "<td>$record[age]</td></tr>";				
	}
	echo " </table><br>";							
	echo "记录数:  $i";							
?>
							
