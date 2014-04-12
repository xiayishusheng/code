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
	/* 步骤四：打印数据库的信息 */
	/*得到数据库个数*/
	$database_count=mysql_num_rows($database);			
		/*步骤五：显示数据库文件名*/
	echo "建立的数据库文件名有：<br>";						
	$i=0;											
	while ($i<$database_count) {
		echo mysql_tablename($database,$i)."<br>";		
		$i=$i+1;										
	}
?>

