	<?php
		/* ����һ�����ó�ʼ����*/
	$host="localhost";								
	$user=��root��;										
	$password=��123456��;								
		/* $db_name�����ݿ�����  $table_name���ݱ�����*/
	$db_name="students";								
	$table_name="classone";							
		/* �����������MySQL������ */
	$conn=mysql_connect($host,$user,$password)  or		
		die ("����MySQL������ʧ�ܡ�".mysql_error( ));
	echo  "MySQL������: $host    �û����ƣ�$user  <br>";	
		/* ��������������ݿ� */
	$mysql_command="drop  database  if  exists ".$db_name;
												
	$result=mysql_query($mysql_command);			
		/* �����ģ��������ݿ� */	
	$mysql_command="create database ".$db_name;		
	$result=mysql_query($mysql_command) or			
		die ("�������ݿ�ʧ�ܡ�".mysql_error( ));		
	mysql_select_db($db_name,$conn) or				
	die ("�������ݿ�ʧ�ܡ�".mysql_error( ));			
	echo "���ݿ�:$db_name  ���ݱ�:$table_name  <br> ";	
		/*���ݱ���ֶ�Ϊ����ʱ,���д���ת��.*/
	$mysql_command="drop  database   ".$table_name;	
	if(!$mysql_command)
	echo "ɾ�����ݿ��ʧ��";							
	else
	echo "ɾ�����ݿ��ɹ�";							
?>
	