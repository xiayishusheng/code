<?php
		/* 步骤一：设置初始变量*/
	$host="localhost";							
	$user=“root”;									
	$password=“123456”;							
	/* $dbase_name：数据库名称*/
	$dbase_name="news"; 
	/* 步骤二：连接数据库服务器 */
	$conn=mysql_connect($host,$user,$password)  or 	
		die ("连接数据库服务器失败。".mysql_error( ));	
	echo  "数据库服务器: $host    用户名称：$user  <br>";	
		/* 步骤三：得到数据表信息*/
	$tables=mysql_list_tables($dbase_name,$conn);	
		/*得到数据表的数目。*/
	$tables_count=mysql_num_rows($tables);			
		/*步骤四：显示数据表文件名*/
	echo $dbase_name."数据库中数据表文件名有：<br>";	
	$i=0;										
	while ($i<$tables_count) {						
		echo mysql_tablename($tables,$i)."<br>";	
		$i=$i+1;									
}
?>
