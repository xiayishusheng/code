<?php
		/* ����һ�����ó�ʼ����*/
	$host="localhost"; 							
	$user=��root��;										
	$password=��123456��;								
	/* $dbase_name�����ݿ�����  */
	$dbase_name="students";							
	/* �����������MySQL������ */
	$conn=mysql_connect($host,$user,$password)  or		
		die ("����MySQL������ʧ�ܡ�".mysql_error( ));		
	echo  "MySQL������: $host    �û����ƣ�$user  <br>"; 	
		/* ��������ɾ�����ݿ⡣ */
	$mysql_command="drop  database  if  exists ".$dbase_name;				
													
	$result=mysql_query($mysql_command) or				
		die ("ɾ�����ݿ�ʧ�ܡ�".mysql_error( ));			
	echo "�ɹ�ɾ�����ݿ⡣".$dbase_name;				
?>
